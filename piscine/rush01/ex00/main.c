/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:43:09 by pissrith          #+#    #+#             */
/*   Updated: 2023/07/24 12:45:39 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define SIZE 5

char *ft_strcpy(char *dest, char *src);
int check_input(char *str);
int check_digit(char c);
void ft_check_rules(char *str);
char *ft_convert(char *dest);
int ft_strlen(char *str);
void run_games(int len, char *inp);
void show(int a[9][9]);

int assign_size(void)
{
	return (SIZE);
}

void solve(int a[9][9], char *s);

void assign_arr(int a[9][9], int s)
{
	int i[2];
	int d;

	d = s / 4;
	i[0] = -1;
	while (++i[0] < d)
	{
		i[1] = -1;
		while (++i[1] < d)
			a[i[0]][i[1]] = 0;
	}
	show(a);
}

int main(int argc, char *argv[])
{
	char rnum[36];
	int i;
	int result;
	int a[9][9];

	if (argc == 2)
	{
		result = check_input(argv[1]);
		if (result)
		{
			ft_strcpy(rnum, ft_convert(argv[1]));
			i = ft_strlen(argv[1]);
			if (i % 4 == 0)
			{
				assign_arr(a, i);
				solve(a, rnum);
			}
			else
				write(1, "Error", 5);
		}
		else
			write(1, "Error", 5);
	}
	else
		write(1, "Error", 5);
}
