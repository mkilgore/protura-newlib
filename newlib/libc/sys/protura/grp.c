
#include <sys/errno.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <grp.h>

static FILE *f;
static size_t line_len = 0;
static char *line;
static struct group ret_group;

void setgrent(void)
{
    if (f)
        fclose(f);
    f = fopen(_PATH_GROUP, "r");
}

void endgrent(void)
{
    if (f) {
        fclose(f);
        f = NULL;

        free(line);
        line = NULL;
        line_len = 0;
    }
}

static int read_int(char **line)
{
    int i = 0;

    for (; isdigit(**line); (*line)++)
        i = i * 10 + (**line - '0');

    return i;
}

struct group *getgrent(void)
{
    ssize_t len;
    if (!f)
        setgrent();

  again:
    len = getline(&line, &line_len, f);
    if (len == -1)
        return NULL;

    line[len - 1] = '\0';

    /* Advance one character to ensure the field wasn't blank */
    ret_group.gr_name = line++;
    if (!(line = strchr(line, ':')))
        goto again;

    *line++ = '\0';
    ret_group.gr_passwd = line;
    if (!(line = strchr(line, ':')))
        goto again;

    *line++ = '\0';
    ret_group.gr_gid = read_int(&line);
    if (*line != ':')
        goto again;

    *line++ = '\0';

    int member_count = 0;

    char *tmp = line;

    while (tmp && *tmp) {
        member_count++;
        tmp = strchr(tmp, ',');
    }

    if (ret_group.gr_mem)
        free(ret_group.gr_mem);

    ret_group.gr_mem = malloc(sizeof(*ret_group.gr_mem) * (member_count + 1));

    int i = 0;
    tmp = line;
    for (i = 0; tmp && *tmp; tmp = strchr(tmp, ','), i++)
        ret_group.gr_mem[i] = tmp;

    ret_group.gr_mem[i] = NULL;

    return &ret_group;
}

struct group *getgrgid(gid_t gid)
{
    struct group *grp;
    setgrent();

    while (grp = getgrent())
        if (grp->gr_gid == gid)
            return grp;

    return NULL;
}

struct group *getgrnam(const char *name)
{
    struct group *grp;
    setgrent();

    while (grp = getgrent())
        if (strcmp(name, grp->gr_name) == 0)
            return grp;

    return NULL;
}
