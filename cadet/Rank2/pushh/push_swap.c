/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:02 by utente            #+#    #+#             */
/*   Updated: 2024/03/25 17:49:50 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	rotate_both(t_stack_number **a,
						t_stack_number **b,
						t_stack_number *cheapest_number)
{
	while (*a != cheapest_number->target_number
		&& *b != cheapest_number)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_number **a,
								t_stack_number **b,
								t_stack_number *cheapest_number)
{
	while (*a != cheapest_number->target_number
		&& *b != cheapest_number)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_number **stack,
							t_stack_number *smallest_number,
							char stack_name)
{
	while (*stack != smallest_number)
	{
		if (stack_name == 'a')
		{
			if (smallest_number->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (smallest_number->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_numbers(t_stack_number **a, t_stack_number **b)
{
	t_stack_number	*cheapest_number;

	cheapest_number = return_cheapest(*b);
	if (cheapest_number->above_median
		&& cheapest_number->target_number->above_median)
		rotate_both(a, b, cheapest_number);
	else if (!(cheapest_number->above_median)
		&& !(cheapest_number->target_number->above_median))
		reverse_rotate_both(a, b, cheapest_number);
	finish_rotation(b, cheapest_number, 'b');
	finish_rotation(a, cheapest_number->target_number, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_number **a, t_stack_number **b)
{
	t_stack_number	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	handle_three(a);
	while (*b)
	{
		init_numbers(*a, *b);
		move_numbers(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
