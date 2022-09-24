/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:45:12 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/21 05:57:09 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (n > 0)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		n--;
		i++;
	}
	return (0);
}
