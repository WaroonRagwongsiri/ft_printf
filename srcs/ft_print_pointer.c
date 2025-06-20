/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:05:05 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 20:05:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_pointer(void *ptr);
int		ft_print_hex_long(unsigned long bytes);
void	ft_put_address(unsigned long bytes);

int	ft_print_pointer(void *ptr)
{
	int				print_count;
	unsigned long	bytes;

	print_count = 0;
	bytes = (unsigned long) ptr;
	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	print_count += ft_print_str("0x");
	print_count += ft_print_hex_long(bytes);
	return (print_count);
}

int	ft_print_hex_long(unsigned long bytes)
{
	int					print_count;
	unsigned long long	n;

	n = bytes;
	print_count = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n != 0)
	{
		n /= 16;
		print_count++;
	}
	ft_put_address(bytes);
	return (print_count);
}

void	ft_put_address(unsigned long bytes)
{
	unsigned long long	n;

	n = bytes;
	if (n > 15)
	{
		ft_put_address(n / 16);
		ft_put_address(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n], 1);
	}
}
