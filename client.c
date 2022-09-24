/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:44:42 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/24 18:43:57 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert(int number, int pid)
{
	int	i;
	
		i=0;
	while(i < 8)
	{
	   if(number & (128 >> i))
	   {
	   		kill(pid,SIGUSR1);
	   }
	   else
	   {
		   kill(pid,SIGUSR2);
	   }
	   usleep(600);
		i++;
	}
}
int main(int argc, char *argv[])
{
    int pid;
	int i;
	pid = ft_atoi(argv[1]);

	if(argc == 3)
	{
		i = 0;
		while (argv[2][i])
		{
    		convert(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_printf("Problem parameter:");
		ft_printf("Name_program,PID and string");
		ft_printf("\n");
	}
}
