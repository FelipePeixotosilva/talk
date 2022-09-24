/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:39:50 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/21 06:34:14 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ptr;
	size_t				i;

	i = 0;
	ptr = s;
	if (n == 0)
	{
		return (NULL);
	}
	while (n > 0)
	{
		if (((char *)s)[i] == (char)c)
		{
			return ((void *) &ptr[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
