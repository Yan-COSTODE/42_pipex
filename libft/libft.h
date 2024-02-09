/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:18:43 by ycostode          #+#    #+#             */
/*   Updated: 2023/12/08 15:36:28 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Check if c is an alphabetical character
int		ft_isalpha(int c);
// Check if c is a digital character
int		ft_isdigit(int c);
// Check if c is an alphanumerical character
int		ft_isalnum(int c);
// Check if c is an ascii character
int		ft_isascii(int c);
// Check if c is a printable character
int		ft_isprint(int c);
// Return the length of the string s
size_t	ft_strlen(const char *s);
// Fill a memory with n bytes of c character
void	*ft_memset(void *s, int c, size_t n);
// Fill a memory with n bytes of 0
void	ft_bzero(void *s, size_t n);
// Copy a memory area from src into dest on n bytes
void	*ft_memcpy(void *dest, const void *src, size_t n);
// Copy a memory area from src into dest on n bytes evoiding overlapping
void	*ft_memmove(void *dest, const void *src, size_t n);
// Copy size character of src into dst
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// Concatenate size character from src into dst
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// Return c in Uppercase
int		ft_toupper(int c);
// Return c in Lowercase
int		ft_tolower(int c);
// Return the first occurence of c in s
char	*ft_strchr(const char *s, int c);
// Return the last occurence of c in s
char	*ft_strrchr(const char *s, int c);
// Compare n char of s1 and s2 by their ascii values
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// Return the first occurence of c in s on n bytes
void	*ft_memchr(const void *s, int c, size_t n);
// Compare n bytes of s1 and s2 by their ascii values
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// Locate the substring little in the string big at max len length
char	*ft_strnstr(const char *big, const char *little, size_t len);
// Convert a string into an int
int		ft_atoi(const char *nptr);
// Allocate and initialize a malloc of length size * nmemb
void	*ft_calloc(size_t nmemb, size_t size);
// Duplicate s
char	*ft_strdup(const char *s);
// Return the substring of s from start to len or end of s
char	*ft_substr(char const *s, unsigned int start, size_t len);
// Return a concatenation of s1 and s2
char	*ft_strjoin(char const *s1, char const *s2);
// Return a copy of s1 without all the character in set
char	*ft_strtrim(char const *s1, char const *set);
// Return an array of string from s splitted by c
char	**ft_split(char const *s, char c);
// Free a double array of char
char	**ft_freesplit(char **split);
// Convert an int to a string
char	*ft_itoa(int n);
// Applies f to each character of f;
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Applies f to each character of f;
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// Write the character c on the file descriptor fd
void	ft_putchar_fd(char c, int fd);
// Write the string s on the file descriptor fd
void	ft_putstr_fd(char *s, int fd);
// Write the string s with a new line on the file descriptor fd
void	ft_putendl_fd(char *s, int fd);
// Write the number n on the file descriptor fd
void	ft_putnbr_fd(int n, int fd);
// Create a new node node with content and no next
t_list	*ft_lstnew(void *content);
// Add new to the front of the list
void	ft_lstadd_front(t_list **lst, t_list *nw);
// Return the size of the list
int		ft_lstsize(t_list *lst);
// Return the last element of the list
t_list	*ft_lstlast(t_list *lst);
// Add new to the end of the line
void	ft_lstadd_back(t_list **lst, t_list *nw);
// Free a node
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// Free all the node since lst
void	ft_lstclear(t_list **lst, void (*del)(void *));
// Iterate the list and apply f to each content
void	ft_lstiter(t_list *lst, void (*f)(void *));
// Iterate the list and apply f to each content and create a new list of result
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
