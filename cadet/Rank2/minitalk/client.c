// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	// int	i;

// 	// i = 0;
// 	// if (argc != 3 || !ft_strlen(argv[2]))
// 	// 	handle_errors("Usage : ./clinet ServerPID Message.");
// 	// while (argv[1][i])
// 	// {
// 	// 	if (!ft_isdigit(argv[1][i]))
// 	// 		handle_errors("Server PID not digit.");
// 	// 	i++;
// 	// }
// 	printf("Client PID : %d\n", getpid());
// 	// signal(SIGUSR1, action);
// 	// signal(SIGUSR2, action);
// 	// send_to_server(ft_atoi(argv[1]), argv[2]);
// 	// while (1)
// 	// 	usleep(300);
// 	return (0);
// }

// // int	main(int argc, char **argv)
// // {
// // 	if (argc != 3 || !ft_str_isnumeric(argv[1]))
// // 	{
// // 		ft_putstr_color_fd(ANSI_COLOR_RED,
// // 			"client: invalid arguments.\n", 2);
// // 		ft_putstr_color_fd(ANSI_COLOR_YELLOW,
// // 			"correct format: [./client <PID> <STR>].\n", 2);
// // 		exit(EXIT_FAILURE);
// // 	}
// // 	signal(SIGUSR1, handler_sigusr);
// // 	signal(SIGUSR2, handler_sigusr);
// // 	send_bit(ft_atoi(argv[1]), argv[2]);
// // 	while (1)
// // 		pause();
// // }
// int	main(int argc, char	**argv)
// {
// 	int		pid;
// 	char	*str;

// 	if (argc != 3)
// 		ft_printf("Please input server pid and one message argument.\n");
// 	else
// 	{
// 		pid = ft_atoi(argv[1]);
// 		str = argv[2];
// 		sig_send_message(pid, str, ft_strlen(str));
// 	}
// }

#include "libft/include/libft.h"
#include "libft/include/ft_printf.h"
#include "libft/include/get_next_line.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static void	action(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Received sig from Server.\n");
}

static void	send_to_server(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			usleep(300);
		}
	}
	exit (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
		handle_errors("Usage : ./clinet ServerPID Message.");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			handle_errors("Server PID not digit.");
		i++;
	}
	ft_printf("Client PID : %d\n", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_to_server(ft_atoi(argv[1]), argv[2]);
	while (1)
		usleep(300);
	return (0);
}
