/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:15:43 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/25 14:01:25 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *str, char *to_find, int si, int ti)
{
	while (to_find[ti] != '\0')
	{
		if (str[si] == to_find[ti])
		{
			ti++;
			si++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	si;
	int	ti;
	int	r;

	r = 0;
	si = 0;
	ti = 0;
	if (to_find[ti] == '\0')
	{
		return (&str[si]);
	}
	while (str[si] != '\0')
	{
		if (str[si] == to_find[ti])
		{
			r = ft_check(str, to_find, si, ti);
			if (r == 1)
				return (&str[si]);
		}
		si++;
	}
	return (0);
}
