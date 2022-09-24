/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:49:27 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/21 07:02:57 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	limit;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + ft_strlen(src));
	}
	limit = size - dst_len - 1;
	j = 0;
	while (src[j] && j < limit)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + ft_strlen(src));
}
