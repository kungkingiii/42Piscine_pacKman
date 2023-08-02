/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:29:21 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/26 12:57:37 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(char *str, int i, int count, int toi)
{
	int	a;

	a = str[i] - '0';
	toi = toi + a;
	if (str[i + 1] < 48 || str[i + 1] > 57)
	{
		if (count != 0 && count % 2 != 0)
		{
			toi = toi * -1;
		}
	}
	else
	{
		toi = toi * 10;
	}
	return (toi);
}

int	ft_atoi(char *str)
{
	int	i;
	int	toi;
	int	count;

	i = -1;
	toi = 0;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] > 47 && str[i] < 58)
		{
			toi = ft_count(str, i, count, toi);
			if (str[i + 1] < 48 || str[i + 1] > 57)
				return (toi);
		}
		else if (str[i] == 45)
		{
			if (str[i + 1] == 32 || (str[i + 1] > 8 && str[i + 1] < 14))
				return (toi);
			count++;
		}
		else if (str[i] < 9 || (str[i] > 13 && str[i] != 32 && str[i] != 43))
			return (toi);
	}
	return (toi);
}
/*
int main()
{
     printf("%d\n", atoi("   1234  gg77"));
     printf("%d\n", ft_atoi("+4567"));
}
*/
