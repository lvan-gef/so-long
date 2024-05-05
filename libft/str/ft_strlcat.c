/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:18:11 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 16:56:29 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static	size_t	size(char *dst, size_t dstsize)
{
	char	*ptr;

	ptr = dst;
	while (dstsize != 0 && *ptr != '\0')
	{
		ptr++;
		dstsize--;
	}
	return (ptr - dst);
}

static	char	*go_to(char *dst, size_t counter)
{
	size_t	index;

	index = 0;
	while (index != counter)
	{
		dst++;
		index++;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		cat_len;
	size_t		dst_len;
	size_t		counter;
	const char	*src_start;

	counter = dstsize;
	dst_len = size(dst, counter);
	cat_len = dstsize - dst_len;
	src_start = src;
	if (cat_len == 0)
		return (dst_len + ft_strlen(src));
	dst = go_to(dst, dst_len);
	while (*src_start != '\0')
	{
		if (cat_len != 1)
		{
			*dst++ = *src_start;
			cat_len--;
		}
		src_start++;
	}
	*dst = '\0';
	return (dst_len + (src_start - src));
}
