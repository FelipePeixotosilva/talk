/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Felipe Peixoto <felipe.peixoto@msn.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:42:39 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/11 17:53:31 by Felipe Peix      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
	{
		ft_memmove(dst, src, ft_strlen(src) + 1);
		dst[size - 1] = '\0';
	}
	else if (size != 0)
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = '\0';
	}	
	return (ft_strlen(src));
}
