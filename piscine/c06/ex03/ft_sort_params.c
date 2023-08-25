/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:56:32 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/28 16:00:52 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prnc(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n,", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_rev(char **str1, int i)
{
	char	*str;

	str = str1[i];
	str1[i] = str1[i + 1];
	str1[i + 1] = str;
}

void	ft_check(int argc, char **argv)
{
	int	i;
	int	c;

	i = 1;
	while (i < argc)
	{
		c = ft_strcmp(argv[i], argv[i + 1]);
		if (c > 0)
		{
			ft_rev(argv, i);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_check(argc - 1, argv);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_prnc(argv[i]);
		i++;
	}
}
