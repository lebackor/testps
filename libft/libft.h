/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:34:08 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/06 19:40:03 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalnum(int a);
int			ft_isalpha(int a);
int			ft_isascii(int c);
int			ft_isdigit(int a);
int			ft_isprint(int a);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *ptr, int x, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
long long	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(char *s1);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		*get_next_line(int fd);
char		*ft_strcpy(char *dest, char *src);
int			ft_print_hexa(unsigned long long nb, int a, int *count);
int			ft_put_hexa_min(unsigned int nb);
int			ft_put_hexa_maj(unsigned int nb);
int			ft_check_pourcent(char c, va_list args);
const char	*ft_print_until(const char *str, va_list args);
int			ft_printf(const char *str, ...);
int			ft_pointer(unsigned long long nb, int *count);
int			ft_putnbr_u(unsigned int nb);
long long	ft_count_nb(long long nb);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nb);
int			*ft_sort_int_tab(int *tab, int size);
int			ft_strcmp(char *s1, char *s2);
char		**ft_free_table(char **str);
#endif
