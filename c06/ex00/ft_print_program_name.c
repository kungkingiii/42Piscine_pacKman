/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:08:57 by Hallykmr          #+#    #+#             */
/*   Updated: 2023/07/28 15:49:15 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[argc - argc][i] != '\0')
	{
		write(1, &argv[argc - argc][i], 1);
		i++;
	}
	write(1, "\n,", 1);
	i++;
}
