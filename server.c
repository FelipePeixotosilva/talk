/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:06 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/27 20:32:05 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int				nbr;
	static unsigned char	c;

	if (sig == SIGUSR1)
	{
		c = c | (128 >> nbr);
	}
	nbr++;
	if (nbr == 8)
	{
		write(1, &c, 1);
		nbr = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_handler = handler;
	pid = getpid();
	ft_printf("My pid:%d\n", pid);
	while (1)
	{
		sigaction (SIGUSR1, &action, NULL);
		sigaction (SIGUSR2, &action, NULL);
		pause();
	}
}
