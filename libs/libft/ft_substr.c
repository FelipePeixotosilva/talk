/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:50:24 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/06/27 20:53:46 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && i < ft_strlen(s))
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
