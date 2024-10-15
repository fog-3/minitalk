/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:31:07 by fosuna-g          #+#    #+#             */
/*   Updated: 2024/10/15 17:10:41 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	help_message(void)
{
	ft_putendl_fd("\tYou have tu pass the PID of the Server and a string", 1);
	ft_putendl_fd("Example of use:", 1);
	ft_putendl_fd("\t./client 2201 \"Hello world!!\"", 1);
}

void	chk_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putstr_fd("\033[31mError: \033[0mthe ", 1);
			ft_putendl_fd("type of the arguments are wrong", 1);
			help_message();
			exit(0);
		}
		i++;
	}
}

/*Se usará SIGUSR1 como valor 0 y SIGUSR2 como valor 1
  y así enviaremos las letras en un formato binario*/
static void	send_message(char *pid, char *str)
{
	int		i;
	char	c;

	chk_pid(pid);
	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(ft_atoi(pid), SIGUSR2);
			else
				kill(ft_atoi(pid), SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i-- > 0)
	{
		kill(ft_atoi(pid), SIGUSR1);
		usleep(100);
	}
}

static void	signal_handler(int sig)
{
	static int	rec = 0;

	if (sig == SIGUSR1)
		rec++;
	else
	{
		ft_putstr_fd("Confirmation signals received: ", 1);
		ft_putnbr_fd(rec, 1);
		write(1, "\n", 1);
		ft_putendl_fd("\033[32mMessage sent successfully\033[0m", 1);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		send_message(argv[1], argv[2]);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("\033[31mError: \033[0mThere ", 1);
		ft_putendl_fd("are not enough parameters", 1);
		help_message();
	}
	return (0);
}
