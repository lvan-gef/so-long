/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 17:14:38 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 15:41:27 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static	int	check_it(va_list args, char c)
{
	if (c == 'c')
		return (write_ascii(va_arg(args, int)));
	else if (c == 's')
		return (write_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (format_int(va_arg(args, int), 0, 10));
	else if (c == 'u')
		return (to_hex(va_arg(args, unsigned int), 0, 10));
	else if (c == 'p')
		return (format_ptr(va_arg(args, void *), 0, 16));
	else if (c == 'x')
		return (to_hex(va_arg(args, unsigned int), 0, 16));
	else if (c == 'X')
		return (to_hex(va_arg(args, unsigned int), 1, 16));
	else if (c == '%')
		return (write_ascii('%'));
	else
		return (write_ascii(c));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			result;
	int			counter;

	result = 0;
	va_start(args, s);
	while (*s && result > -1)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				break ;
			counter = check_it(args, *s);
		}
		else
			counter = write_ascii(*s);
		if (counter < 0)
			result = counter;
		else
			result += counter;
		s++;
	}
	va_end(args);
	return (result);
}
