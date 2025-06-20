/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:19:39 by marvin            #+#    #+#             */
/*   Updated: 2025/06/18 00:19:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c);
size_t	count_word(char const *s, char c);
void	*free_arr(char **arr);
char	**process(char const *s, char c, char **new, size_t i);
void	inner_loop(char const *s, size_t last_index_sep,
			size_t index_sep, char *new);

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	wc;

	if (s[0] == '\0')
	{
		new = malloc(sizeof(char *) * 1);
		if (!new)
			return (NULL);
		new[0] = NULL;
		return (new);
	}
	wc = count_word(s, c);
	new = malloc(sizeof(char *) * (wc + 1));
	if (!new)
		return (NULL);
	if (process(s, c, new, 0) == NULL)
	{
		new[wc] = NULL;
		return (NULL);
	}
	new[wc] = NULL;
	return (new);
}

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
		{
			word++;
		}
		else if (s[i] != c && s[i - 1] == c)
		{
			word++;
		}
		i++;
	}
	return (word);
}

void	*free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**process(char const *s, char c, char **new, size_t i)
{
	size_t	index_sep;
	size_t	last_index_sep;
	size_t	new_count;

	new_count = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && i == 0)
			last_index_sep = i;
		else if (s[i] != c && s[i - 1] == c)
			last_index_sep = i;
		if (i > 0)
		{
			if ((s[i] == c || i == ft_strlen(s)) && s[i - 1] != c)
			{
				index_sep = i;
				new[new_count] = malloc(index_sep - last_index_sep + 1);
				if (!new[new_count])
					return (free_arr(new));
				inner_loop(s, last_index_sep, index_sep, new[new_count++]);
			}
		}
		i++;
	}
	return (new);
}

void	inner_loop(char const *s, size_t last_index_sep
			, size_t index_sep, char *new)
{
	size_t	j;

	j = 0;
	while (last_index_sep < index_sep)
	{
		new[j] = s[last_index_sep];
		last_index_sep++;
		j++;
	}
	new[j] = '\0';
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**tab;
// 	tab = ft_split("", ' ');
// 	// if (split && split[2])
// 	printf("%p\n", tab[0]);
// 	if (tab)
// 		free_arr(tab);
// 	return (0);
// }
