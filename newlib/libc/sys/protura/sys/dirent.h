
#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <sys/types.h>

typedef struct {
    int dd_fd;		/* directory file */
    int dd_loc;		/* position in buffer */
    int dd_seek;
    char *dd_buf;	/* buffer */
    int dd_len;		/* buffer length */
    int dd_size;	/* amount of data in buffer */
} DIR;

#define MAXNAMLEN 255		/* sizeof(struct dirent.d_name)-1 */

struct dirent {
    ino_t d_ino;
    int d_reclen;
    int d_namlen;
    char d_name[];
};

#define __dirfd(dir) (dir)->dd_fd

#undef HAVE_NO_D_NAMLEN
#undef HAVE_DD_LOCK

DIR *opendir(const char *);
struct dirent *readdir(DIR *);
int readdir_r(DIR *__restrict, struct dirent *__restrict,
              struct dirent **__restrict);
void rewinddir(DIR *);
int closedir(DIR *);

/* internal prototype */
void _seekdir(DIR *dir, long offset);
DIR *_opendir(const char *);

#ifndef _POSIX_SOURCE
long telldir (DIR *);
void seekdir (DIR *, off_t loc);

int scandir (const char *__dir,
             struct dirent ***__namelist,
             int (*select) (const struct dirent *),
             int (*compar) (const struct dirent **, const struct dirent **));

int alphasort (const struct dirent **__a, const struct dirent **__b);
#endif /* _POSIX_SOURCE */

#endif
