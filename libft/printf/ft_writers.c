/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 17:42:54 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 15:40:23 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	write_str(char *s)
{
	int	count;
	int	result;

	count = 0;
	if (!s)
		s = "(null)";
	while (s[count])
	{
		result = write_ascii(s[count]);
		if (result < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	write_ascii(int c)
{
	return (write(1, &c, 1));
}
