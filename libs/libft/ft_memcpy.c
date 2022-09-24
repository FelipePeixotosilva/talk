/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:54:44 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/21 06:50:49 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	while (n > 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
		n--;
	}
	return (dest);
}
