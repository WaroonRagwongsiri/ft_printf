/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:27:01 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 12:27:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_format(char c_format, va_list args);
int	check_valid_format(char c);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_count;
	size_t	i;

	print_count = 0;
	i = 0;
	va_start(args, format);
	while (i < (ft_strlen(format) - 1))
	{
		if (format[i] == '%')
		{
			print_count += ft_print_format(format[i + 1], args);
			i++;
		}
		else
			print_count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_count);
}

// cspdiuxX%
int	ft_print_format(char c_format, va_list args)
{
	if (c_format == 'c')
		return (ft_print_char(va_arg(args, char)));
	else if (c_format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c_format == 'p')
		ft_print_pointer();
	else if (c_format == 'd' || c_format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c_format == 'x' || c_format == 'X')
		return (ft_print_hex(va_arg(args, int), c_format));
	else if (c_format == '%')
		return (ft_print_char('%'));
}

int	check_valid_format(char c)
{
	char	format[9];

	format[0] = 'c';
	format[1] = 'p';
	format[2] = 'd';
	format[3] = 'i';
	format[4] = 'u';
	format[5] = 'x';
	format[6] = 'X';
	format[7] = '%';
	format[8] = '\0';
	while (*format)
	{
		if (c == *format)
		{
			return (1);
		}
	}
	return (0);
}
