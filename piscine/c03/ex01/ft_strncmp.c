/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:31:09 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/26 12:28:54 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (s1[i] != '\0' && s2[i] == '\0' && n != 0)
	{
		return (s1[i] - 0);
	}
	while (i < n && (s2[i] != '\0' || s1[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d", ft_strncmp("ggh", "gg", 6));
	printf("%d", strncmp("ggh", "gg", 6));
}
*/
