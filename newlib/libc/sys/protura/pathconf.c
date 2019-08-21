
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>
#include <utime.h>

/* Get file-specific information about PATH.  */
static long int
posix_pathconf (const char *path, int name)
{
  if (path[0] == '\0')
    {
      __set_errno (ENOENT);
      return -1;
    }

  switch (name)
    {
    default:
      __set_errno (EINVAL);
      return -1;

    case _PC_LINK_MAX:
#ifdef	LINK_MAX
      return LINK_MAX;
#else
      return -1;
#endif

    case _PC_MAX_CANON:
#ifdef	MAX_CANON
      return MAX_CANON;
#else
      return -1;
#endif

    case _PC_MAX_INPUT:
#ifdef	MAX_INPUT
      return MAX_INPUT;
#else
      return -1;
#endif

    case _PC_NAME_MAX:
#ifdef	NAME_MAX
      {
	struct statfs buf;
	int save_errno = errno;

	if (__statfs (path, &buf) < 0)
	  {
	    if (errno == ENOSYS)
	      {
		errno = save_errno;
		return NAME_MAX;
	      }
	    return -1;
	  }
	else
	  {
#ifdef _STATFS_F_NAMELEN
	    return buf.f_namelen;
#else
# ifdef _STATFS_F_NAME_MAX
	    return buf.f_name_max;
# else
	    return NAME_MAX;
# endif
#endif
	  }
      }
#else
      return -1;
#endif

    case _PC_PATH_MAX:
#ifdef	PATH_MAX
      return PATH_MAX;
#else
      return -1;
#endif

    case _PC_PIPE_BUF:
#ifdef	PIPE_BUF
      return PIPE_BUF;
#else
      return -1;
#endif

    case _PC_CHOWN_RESTRICTED:
#ifdef	_POSIX_CHOWN_RESTRICTED
      return _POSIX_CHOWN_RESTRICTED;
#else
      return -1;
#endif

    case _PC_NO_TRUNC:
#ifdef	_POSIX_NO_TRUNC
      return _POSIX_NO_TRUNC;
#else
      return -1;
#endif

    case _PC_VDISABLE:
#ifdef	_POSIX_VDISABLE
      return _POSIX_VDISABLE;
#else
      return -1;
#endif

    case _PC_SYNC_IO:
#ifdef	_POSIX_SYNC_IO
      return _POSIX_SYNC_IO;
#else
      return -1;
#endif

    case _PC_ASYNC_IO:
#ifdef	_POSIX_ASYNC_IO
      {
	/* AIO is only allowed on regular files and block devices.  */
	struct stat64 st;

	if (stat64 (path, &st) < 0
	    || (! S_ISREG (st.st_mode) && ! S_ISBLK (st.st_mode)))
	  return -1;
	else
	  return 1;
      }
#else
      return -1;
#endif

    case _PC_PRIO_IO:
#ifdef	_POSIX_PRIO_IO
      return _POSIX_PRIO_IO;
#else
      return -1;
#endif

    case _PC_FILESIZEBITS:
#ifdef FILESIZEBITS
      return FILESIZEBITS;
#else
      /* We let platforms with larger file sizes overwrite this value.  */
      return 32;
#endif

    case _PC_REC_INCR_XFER_SIZE:
      /* XXX It is not entirely clear what the limit is supposed to do.
	 What is incremented?  */
      return -1;

    case _PC_REC_MAX_XFER_SIZE:
      /* XXX It is not entirely clear what the limit is supposed to do.
	 In general there is no top limit of the number of bytes which
	 case be transported at once.  */
      return -1;

    case _PC_SYMLINK_MAX:
      /* In general there are no limits.  If a system has one it should
	 overwrite this case.  */
      return -1;
    }
}

long int pathconf (path, name)
     const char *path;
     int name;
{
  if (name == _PC_LINK_MAX)
    {
	  return 5;
    }

  return posix_pathconf (path, name);
}

