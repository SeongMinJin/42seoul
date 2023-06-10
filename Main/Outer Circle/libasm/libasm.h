#ifndef LIBSAM_H
#define LIBSAM_H

#include <sys/types.h>

size_t	ft_strlen(const char *str);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strcpy(char *dst, const char* src);
char		*ft_strdup(const char *s1);
int			ft_strcmp(const char *str1, const char *str2);


#endif