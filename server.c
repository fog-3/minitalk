/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:31:15 by fosuna-g          #+#    #+#             */
/*   Updated: 2024/10/15 16:37:05 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	print_serv(void)
{
	ft_putendl_fd("", 1);
	ft_putstr_fd("\033[33m     _______. _______ .______     _", 1);
	ft_putendl_fd("___    ____  _______ .______      ", 1);
	ft_putstr_fd("    /       ||   ____||   _  \\   ", 1);
	ft_putendl_fd(" \\   \\  /   / |   ____||   _  \\     ", 1);
	ft_putstr_fd("   |   (----`|  |__   |  |_)  |    \\", 1);
	ft_putendl_fd("   \\/   /  |  |__   |  |_)  |    ", 1);
	ft_putstr_fd("    \\   \\    |   __|  |      /      ", 1);
	ft_putendl_fd("\\      /   |   __|  |      /     ", 1);
	ft_putstr_fd(".----)   |   |  |____ |  |\\  \\----.", 1);
	ft_putendl_fd("  \\    /    |  |____ |  |\\  \\----.", 1);
	ft_putstr_fd("|_______/    |_______|| _| `._____|   \\", 1);
	ft_putendl_fd("__/     |_______|| _| `._____|", 1);
	ft_putendl_fd("", 1);
	ft_putstr_fd("Server PID: \033[34m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\t\t\t\t\t\033[90mCreated by: FOG\n\n>>\033[0m ", 1);
}

int	chk_end_file(unsigned char c, pid_t client_pid)
{
	if (!c)
	{
		write(1, "\n", 1);
		ft_putstr_fd("\033[90m>>\033[37m ", 1);
		kill(client_pid, SIGUSR2);
		return (1);
	}
	return (0);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (chk_end_file(c, client_pid))
		{
			client_pid = 0;
			c = 0;
			i = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_action;

	print_serv();
	s_action.sa_sigaction = handle_signal;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
	return (0);
}
