/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:47:05 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 20:47:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_unsigned(unsigned int nbr);
void	ft_putnbr_unsigned(unsigned int n);

int	ft_print_unsigned(unsigned int nbr)
{
	unsigned int	n;
	int				print_count;

	n = nbr;
	print_count = 0;
	if (nbr == 0)
	{
		ft_putnbr_fd(nbr, 1);
		return (1);
	}
	while (n != 0)
	{
		n /= 10;
		print_count++;
	}
	ft_putnbr_unsigned(nbr);
	return (print_count);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
	{
		write(1, &"0123456789"[n], 1);
	}
}
