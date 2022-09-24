/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:13:11 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/06/21 06:37:42 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
		return ;
	}
	if (n == 2147483647)
	{
		ft_putstr_fd ("2147483647", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd (n + '0', fd);
	}
	else
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
}
