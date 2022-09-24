/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 04:39:49 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/21 06:10:10 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s)+1;
	while ((i > 0))
	{
		i--;
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}	
	}
	return (NULL);
}
