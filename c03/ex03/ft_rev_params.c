/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:00:56 by chongsen          #+#    #+#             */
/*   Updated: 2023/07/27 17:46:39 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_prnc(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n,", 1);
}

void ft_rev(char *str1, char *str2)
{
    char *str;

    str = str1;
    str1 = str2;
    str2 = str;
}

int main(int argc, char **argv)
{
    int i;
    int rev;

    rev = (argc - 1) / 2;
    i = 1;
    if (argc < 2)
    {
        write(1, "\n,", 1);
    }
    else if (argc < 3)
    {
        ft_prnc(argv[1]);
    }
    while (i <= rev)
    {
        ft_rev(argv[i], argv[argc - i]);
        i++;
    }
    i = 1;
    while (i < argc)
    {
        ft_prnc(argv[i]);
        i++;
    }
}