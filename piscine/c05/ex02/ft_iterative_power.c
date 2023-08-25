/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:20:11 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/27 17:13:03 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	i = 1;
	res = nb;
	if (power < 0)
	{
		return (0);
	}
	if ((nb == 0 && power == 0) || power == 0 || nb == 1)
	{
		return (1);
	}
	while (i < power)
	{
		nb = nb * res;
		i++;
	}
	return (nb);
}
