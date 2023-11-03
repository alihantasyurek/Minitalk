/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:40:06 by atasyure          #+#    #+#             */
/*   Updated: 2023/07/13 13:56:09 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;
	size_t	j;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	i = 0;
	j = dsize;
	if (dstsize <= dsize)
		return (dstsize + ssize);
	while (src[i] && j + 1 < dstsize)
		*(dst + j++) = *(src + i++);
	dst[dsize + i] = '\0';
	return (dsize + ssize);
}
