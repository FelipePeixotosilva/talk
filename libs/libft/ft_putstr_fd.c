/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Felipe Peixoto <felipe.peixoto@msn.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:50:05 by Felipe Peix       #+#    #+#             */
/*   Updated: 2022/06/16 11:02:35 by Felipe Peix      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		return ;
	}
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
