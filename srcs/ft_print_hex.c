/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:59:56 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 17:59:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_hex(int nbr, char c_format);
void	ft_putnbr_hex_s(int nbr);
void	ft_putnbr_hex_m(int nbr);

int	ft_print_hex(int nbr, char c_format)
{
	int		print_count;
	long	n;

	n = nbr;
	print_count = 0;
	if (n == 0)
		return (ft_print_char('0'));
	if (n < 0)
	{
		n = -n;
		print_count++;
	}
	while (n > 15)
	{
		n /= 16;
		print_count++;
	}
	if (c_format == 'x')
		ft_putnbr_hex_s(nbr);
	else if (c_format == 'X')
		ft_putnbr_hex_m(nbr);
	return (print_count);
}

void	ft_putnbr_hex_s(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 15)
	{
		ft_putnbr_hex_s(n / 16);
		ft_putnbr_hex_s(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n], 1);
	}
}

void	ft_putnbr_hex_m(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 15)
	{
		ft_putnbr_hex_m(n / 16);
		ft_putnbr_hex_m(n % 16);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[n], 1);
	}
}
