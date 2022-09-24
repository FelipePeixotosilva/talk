/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:32:48 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/06/21 07:00:27 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	start;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
				index++;
		start = index;
		while (s[index] != c && s[index])
				index++;
		if (start != index)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	index;
	size_t	j;
	size_t	start;

	index = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[index])
	{
		while (s[index] == c && s[index])
				index++;
		start = index;
		while (s[index] != c && s[index])
				index++;
		if (start != index)
				ptr[j++] = ft_substr(s, start, index - start);
	}
	ptr[j] = NULL;
	return (ptr);
}
