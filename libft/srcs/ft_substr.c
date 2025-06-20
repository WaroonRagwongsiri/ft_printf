/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:25:58 by marvin            #+#    #+#             */
/*   Updated: 2025/06/17 21:25:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*new;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		new = malloc(1);
		new[0] = '\0';
		return (new);
	}
	if (start + len > s_len)
		len = s_len - start;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char 	*str;
// 	str = strdup("0123456789");
// 	s = ft_substr(str, 9, 10);
// 	printf("%s\n", s);
// 	free(s);
// 	free(str);
// 	return (0);
// }
