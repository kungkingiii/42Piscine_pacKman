/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:15:13 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/25 10:56:42 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*int_to_put;

	if (*src == NULL)
		return ;
	int_to_put = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	int_to_put->prev = NULL;
	if (*dest == NULL)
	{
		*dest = int_to_put;
		int_to_put->next = NULL;
	}
	else
	{
		int_to_put->next = *dest;
		int_to_put->next->prev = int_to_put;
		*dest = int_to_put;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
