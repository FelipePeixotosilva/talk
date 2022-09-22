/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:06 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/22 14:27:32 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig)
{
	static int nbr;
	static unsigned char c;

    if(sig == SIGUSR1)
	{
		c = c | (128 >> nbr);
	}
	nbr++;
	//printf("%d\n", nbr);
	if(nbr == 8)
	{
		//printf("Caracter:");
		write(1,&c,1);
		nbr = 0;
		c = 0;
	}        
}
int main()
{
    int pid = getpid();
    printf("Meu pid %d\n", pid);
	
    while(1)
	{
		signal(SIGUSR1,handler);
		signal(SIGUSR2,handler);
        pause();
	}
   // sleep(5000)
}
