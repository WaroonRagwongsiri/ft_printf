/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:27:36 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 17:27:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	long	n;
	int		print_count;

	print_count = 0;
	n = nbr;
	if (n == 0)
	{
		ft_putnbr_fd(nbr, 1);
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		print_count++;
	}
	while (n != 0)
	{
		n /= 10;
		print_count++;
	}
	ft_putnbr_fd(nbr, 1);
	return (print_count);
}
