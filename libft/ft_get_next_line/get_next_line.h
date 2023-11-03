/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:27 by atasyure          #+#    #+#             */
/*   Updated: 2023/10/20 14:19:48 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

size_t	ft_len(const char *s);
char	*ft_dup(const char *s1);
char	*ft_join(char const *s1, char const *s2);
char	*ft_sub(char const *s, unsigned int start, size_t len);
void	*ft_free_stash(char **stash, int create_line);
char	*get_next_line(int fd);

#endif
