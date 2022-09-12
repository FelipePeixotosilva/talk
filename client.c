/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:44:42 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/12 20:05:25 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int convert(int number, int pid)
{
    if(number < 2)
    {
        if(number == 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        usleep(100);
    }
    else
    {
        convert(number / 2, pid);
        convert(number % 2, pid);
    }       
}
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
int main(int argc, char *argv[])
{
    int pid = ft_atoi(argv[1]);
    convert(ft_atoi(argv[2]), pid);
}
