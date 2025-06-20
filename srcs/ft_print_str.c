/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:24:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 17:24:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	print_count;

	print_count = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (str[print_count])
	{
		write(1, &str[print_count], 1);
		print_count++;
	}
	return (print_count);
}
