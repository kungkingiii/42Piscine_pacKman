/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:07:21 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/19 16:16:36 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_letter(char *str, int num)
{
	if (str[num - 1] < 48 || (str[num - 1] > 57 && str[num - 1] < 65))
	{
		if (str[num] > 96 && str[num] < 123)
		{
			str[num] = str[num] - 32;
		}
	}
	else if ((str[num - 1] > 90 && str[num - 1] < 97) || str[num - 1] > 122)
	{
		if (str[num] > 96 && str[num] < 123)
		{
			str[num] = str[num] - 32;
		}
	}
	else
	{
		if (str[num] > 64 && str[num] < 91)
		{
			str[num] = str[num] + 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	num;

	num = 0;
	while (str[num] != '\0')
	{
		ft_check_letter(str, num);
		num++;
	}
	return (str);
}
