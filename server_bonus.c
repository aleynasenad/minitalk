/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:40:15 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/02/26 18:54:34 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_putstr("\nMessage received from PID: ");
			ft_putnbr(info->si_pid);
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	taken_signal;

	taken_signal.sa_sigaction = ft_handler;
	taken_signal.sa_flags = SA_SIGINFO;
	sigemptyset(&taken_signal.sa_mask);
	if (sigaction(SIGUSR1, &taken_signal, NULL) == -1)
	{
		ft_putstr("Error: sigaction(SIGUSR1) failed\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &taken_signal, NULL) == -1)
	{
		ft_putstr("Error: sigaction(SIGUSR2) failed\n");
		return (1);
	}
	write(1, "Server PID is: ", 15);
	ft_putnbr(getpid());
	ft_putstr("\nWaiting for messages...\n");
	while (1)
		pause();
	return (0);
}
