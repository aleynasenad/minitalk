/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:43:12 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/02/26 19:31:57 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_flag = 0;

void	flg_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		g_flag = 1;
}

void	send_char(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Error: Wrong number of arguments.");
		ft_putstr("Try: ./client <PID> <message>");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1)
	{
		ft_putstr("Error: invalid PID.\n");
		return (1);
	}
	signal(SIGUSR1, flg_handler);
	message = argv[2];
	while (*message)
		send_char(server_pid, *message++);
	send_char(server_pid, '\0');
	return (0);
}
