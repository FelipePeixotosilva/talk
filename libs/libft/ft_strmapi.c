/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:44:58 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/06/17 02:58:23 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen(s)+1);
	if (ptr == 0)
	{
		return (0);
	}
	while (s[i])
	{
		ptr[i] = f (i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
