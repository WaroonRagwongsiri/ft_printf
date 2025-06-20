/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:02:02 by marvin            #+#    #+#             */
/*   Updated: 2025/06/18 00:02:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

size_t	count_word(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	j;
	size_t	word;

	if (set == NULL || s1 == NULL)
		return (NULL);
	word = count_word(s1, set);
	new = malloc(word + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
		{
			new[j] = *s1;
			j++;
		}
		s1++;
	}
	new[j] = '\0';
	return (new);
}

size_t	count_word(char const *s1, char const *set)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			word++;
		i++;
	}
	return (word);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*new = ft_strtrim("          \t   \n  abc \n  \t", "");
// 	printf("%s\n", new);
// 	free(new);
// 	return (0);
// }
