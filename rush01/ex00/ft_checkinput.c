/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:34:12 by pissrith          #+#    #+#             */
/*   Updated: 2023/07/24 10:19:42 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int check_input(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && !check_digit(str[i]))
		{
			return (0);
		}
		else if (i % 2 == 1 && str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
