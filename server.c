/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:06 by fpeixoto          #+#    #+#             */
/*   Updated: 2022/09/10 19:18:04 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig)
{
    printf("\n");
    if(sig == SIGUSR1)
        printf("1");
    else if(sig == SIGUSR2)
        printf("0");
    printf("\n");
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
