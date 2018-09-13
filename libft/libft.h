/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:27:11 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 11:58:26 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include "./get_next_line.h"

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
int			ft_isspace(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strncpy(char *dest, const char *src, size_t len);
void		ft_putstr_fd(char const *str, int fd);
void		ft_putstr(char const *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t len);
char		*ft_strstr(const char *str1, const char *str2);
void		ft_putendl(char const *str);
void		ft_putendl_fd(char const *str, int fd);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char	const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strnstr(const char *str1, const char *str2, size_t len);
char		*ft_itoa(int n);
char		**ft_strsplit(char const *s, char c);
int			get_next_line(int const fd, char **line);
void		ft_fill_char(char *value, char *s, int len, int i);
char		*ft_getz(char *num);
int			ft_iterative_power(int nb, int power);
char		*ft_make_word(char *s, char c);
void		ft_mnbr(char *num, int len, int n);
int			ft_printf(const char *format, ...);
void		ft_putchar_color_fd(char c, int color, int fd);
void		ft_putstr_color(char *str, int color);
void		ft_putstr_color_fd(char *str, int color, int fd);
int			ft_recursive_factorial(int nb);
void		ft_strclr(char *s);
int			ft_wc(char *s, char c);
intmax_t	ps_big_atoi(const char *str);
#endif
