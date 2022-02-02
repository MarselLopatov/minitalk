/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:21:55 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/02 20:46:50 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_zero(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (kill(pid, SIGUSR1))
			exit(1);
		usleep(800);
	}
}

void	ft_kill(int pid, char *message)
{
	int		i;
	char	symb;

	while (*message)
	{
		symb = *message;
		i = 8;
		while (i--)
		{
			if (symb >> i & 1)
			{
				if (kill(pid, SIGUSR2))
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1))
					exit(1);
			}
			pause();
			usleep(150);
		}
		message++;
	}
	send_zero(pid);
}

void	ft_handler(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signal == SIGUSR2)
		ft_putstr("Success!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc != 3)
		return (0);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	if (sigaction(SIGUSR2, &sig, NULL))
	{
		ft_putstr("Signal error!\n");
		exit (2);
	}
	if (sigaction(SIGUSR1, &sig, NULL))
	{
		ft_putstr("Signal error!\n");
		exit (2);
	}
	ft_kill(ft_atoi(argv[1]), argv[2]);
}
