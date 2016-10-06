#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#define __need_size_t
#define __need_NULL
#include <stddef.h>
#include <sys/config.h>
#include <machine/types.h>
#include <sys/_types.h>

#if !defined(__time_t_defined) && !defined(_TIME_T)
#define _TIME_T
#define __time_t_defined
typedef _TIME_T_ time_t;
#endif

#if !defined(__clock_t_defined) && !defined(_CLOCK_t)
#define _CLOCK_T
#define __clock_t_defined
typedef _CLOCK_T_ clock_t;
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
typedef _ssize_t ssize_t;
#endif

#ifndef __u_char_defined
#ifdef __GNUC__
__extension__ typedef long long quad_t;
__extension__ typedef unsigned long long u_quad_t;
#else
typedef struct
  {
    long int __val[2];
  } quad_t;
typedef struct
  {
    unsigned long __val[2];
  } u_quad_t;
#endif
typedef struct
  {
    int __val[2];
  } fsid_t;
#define __u_char_defined
#endif

typedef int clockid_t;

#ifndef _SYS_TYPES_FD_SET

# include <protura/fs/fdset.h>

# define NOFILE __kNOFILE
# define FD_SETSIZE __kFD_SETSIZE

typedef __kfd_set fd_set;
typedef __kfd_mask fd_mask;

# define NBBY __kNBBY
# define FDBITS __kFDBITS

# define FD_CLR(fd, set) __kFD_CLR(fd, set)
# define FD_SET(fd, set) __kFD_SET(fd, set)
# define FD_ISSET(fd, set) __kFD_ISSET(fd, set)
# define FD_ZERO(set) __kFD_ZERO(set)

# define _SYS_TYPES_FD_SET
#endif

#include <protura/types.h>
#define __mode_t_defined
#define __pid_t_defined
#define __ssize_t_defined
#define __off_t_defined
#define __uid_t_defined
#define __gid_t_defined

typedef __kino_t ino_t;
typedef __kuintptr_t uintptr_t;
typedef __kintptr_t intptr_t;
typedef __koff_t off_t;
typedef __kpid_t pid_t;

typedef __ksuseconds_t suseconds_t;
typedef __kuseconds_t useconds_t;

typedef __kudev_t dev_t;
typedef __kmode_t mode_t;
typedef __kumode_t umode_t;
typedef __kuid_t uid_t;
typedef __kgid_t gid_t;

typedef __kdaddr_t daddr_t;
typedef __kcaddr_t caddr_t;

#include <sys/_stdint.h>

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef __kuint8_t u_int8_t;
typedef __kuint16_t u_int16_t;
typedef __kuint32_t u_int32_t;
typedef __kuint64_t u_int64_t;

typedef __kuint64_t u64;
typedef int64_t sbintime_t;

#endif
