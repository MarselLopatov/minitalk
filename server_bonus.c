/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:29:16 by cdoria            #+#    #+#             */
/*   Updated: 2022/01/31 01:29:17 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_ch(siginfo_t *siginfo, char ch)
{
	if (!ch)
	{
		kill (siginfo->si_pid, SIGUSR2);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_action(int signal, siginfo_t *siginfo, void *context)
{
	static int		i = 0;
	static pid_t	pid = 0;
	static char		ch = 0;

	(void)context;
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
		if (check_ch(siginfo, ch))
			return ;
		i = 0;
		ch = 0;
	}
	else
		ch <<= 1;
	usleep(150);
	kill (siginfo->si_pid, SIGUSR1);
}

int	main(void)
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
