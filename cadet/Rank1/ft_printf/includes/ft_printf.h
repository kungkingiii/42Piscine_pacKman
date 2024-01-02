#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int		ft_printf(const char *str, ...);
int 	ft_putstr(const char *str);
int 	ft_putchar(const char c);
int 	ft_putunsigned_int(unsigned int n);
int 	ft_putint(int n);
int 	ft_puthex_int(int n, char f);
int		ft_putptr(unsigned long long ptr);

#endif
