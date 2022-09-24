/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:15:45 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/06/21 06:36:06 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cvrt(int n)
{
	if (n < 0)
		return (n = n * -1);
	return (n);
}

static int	qnbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		i++;
		n = cvrt(n);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = qnbr(n);
	ptr = (char *)malloc((sizeof(char) * qnbr(n)) + 1);
	if (ptr == 0)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	ptr[i] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = cvrt(n);
	}
	while (n > 0)
	{
			i--;
			ptr[i] = n % 10 + '0';
			n = n / 10;
	}
	return (ptr);
}
