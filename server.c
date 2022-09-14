/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:06 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/13 21:17:46 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		s;
	int		j;

	i = 0;
	s = 1;
	j = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}	
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0'))
	{
		j = j * 10 + (nptr[i] - '0');
		i++;
	}	
	return (j * s);
}

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
		printf("\n");
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
   // sleep(5000);
    
}
