/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:23:26 by Hallykmr          #+#    #+#             */
/*   Updated: 2024/04/03 23:30:32 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(const char *str);
int		ft_putchar(const char c);
int		ft_putunsigned_int(unsigned int n);
int		ft_putint(int n);
int		ft_puthex_int(unsigned int n, char f);
int		ft_putptr(unsigned long long ptr);

#endif
