/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:39:56 by packmanich        #+#    #+#             */
/*   Updated: 2024/04/10 00:33:25 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft_printf.h"
#include <signal.h>

static int	g_recieve_sig;

void	sig_handler(int signum, siginfo_t *info, void	*context)
{
	static int	count;

	(void)context;
	(void)info;
	(void)signum;
	g_recieve_sig = 1;
	if (signum == SIGUSR2)
		count++;
	else if (signum == SIGUSR1)
		ft_printf("%d bytes received\n", count / 8);
}

int	char_to_bin(char c, int pid)
{
	int	bit;
	int	bit_idx;

	bit_idx = 7;
	while (bit_idx >= 0)
	{
		bit = 0;
		if ((c >> bit_idx) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_recieve_sig == 0)
		{
			if (bit == 50)
			{
				ft_printf("No response from server.\n");
				exit(1);
			}
			bit++;
			usleep(300);
		}
		g_recieve_sig = 0;
		bit_idx--;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	int					i;
	int					pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("need only 3 argument for send message!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	i = 0;
	while (i < ft_strlen(str))
	{
		char_to_bin(str[i], pid);
		i++;
	}
	char_to_bin('\0', pid);
	return (0);
}
