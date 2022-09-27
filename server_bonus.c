/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:06 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/27 20:28:19 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *oact)
{
	static int				nbr;
	static unsigned char	c;
	(void) *oact;
	if (sig == SIGUSR1)
	{
		c = c | (128 >> nbr);
	}
	nbr++;
	if (nbr == 8)
	{
        if(c != 0)
		    write(1, &c, 1);
		else
            kill(info -> si_pid, SIGUSR1);
        nbr = 0;
		c = 0;
        
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_sigaction = handler;
    action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("My pid:%d\n", pid);
	while (1)
	{
		sigaction (SIGUSR1, &action, NULL);
		sigaction (SIGUSR2, &action, NULL);
		pause();
	}
}
