/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:21:58 by cdoria            #+#    #+#             */
/*   Updated: 2022/01/27 19:41:02 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_action(int signal, siginfo_t *siginfo, void *context)
{
	static int		i = 0;
	static pid_t	pid = 0;
	static char		ch = 0;
	
	(void) context;
	if (pid != siginfo->si_pid)
	{
		i = 0;
		ch = 0;
		pid = siginfo->si_pid;
	}
	ch |= (signal == SIGUSR2);
	if (++i == 8)
	{
		write(1, &ch, 1);
		if (!ch)
		{
			kill (siginfo->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		i = 0;
		ch = 0;
	}
	else
		ch <<= 1;
}

int main()
{
	struct sigaction	sig;

	ft_putstr("PID: ");
	ft_putnbr(getpid());
	write(0, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_action;
	if (sigaction(SIGUSR1, &sig, NULL))
	{
		ft_putstr("Signal error!\n");
		exit (2);
	}
	if (sigaction(SIGUSR2, &sig, NULL))
	{
		ft_putstr("Signal error!\n");
		exit (2);
	}
	while (1)
		pause();
	return (0);
}
