/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hallykmr <Hallykmr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:19:05 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/25 09:05:13 by Hallykmr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	if (NULL == stack)
		return ;
	centerline = stack_len(stack) / 2;
	i = 0;
	// printf("this is center %d\n", centerline);
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
		{
			// printf("this is current i %d\n", stack->current_position);
			stack->above_median = true;
		}
		else
		{
			stack->above_median = false;
			// printf("this is current %d\n", stack->above_median);	
		}
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *a,
							t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		// printf("long max%ld\n", LONG_MAX);
		current_a = a;
		while (current_a)
		{
			// printf("current_a%d current_b%d\n", current_a->value, b->value);
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	// printf("this is boolean a %d\n", a->above_median);
	set_current_position(b);
	// printf("this is boolean b %d\n", a->above_median);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
