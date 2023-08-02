/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:25:46 by chongsen          #+#    #+#             */
/*   Updated: 2023/08/02 14:05:47 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define EVEN(n) (n % 2 == 0)
#define ODD_MSG "I have an odd number of arguments.\n"
#define EVEN_MSG "I have an even number of arguments.\n"
#include <unistd.h>

typedef int t_bool;

#endif