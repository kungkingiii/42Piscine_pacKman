/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:32:28 by chongsen          #+#    #+#             */
/*   Updated: 2024/03/25 17:48:01 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack_number	*find_last_number(t_stack_number *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_number(t_stack_number **stack, int nbr)
{
	t_stack_number	*number;
	t_stack_number	*last_number;

	if (NULL == stack)
		return ;
	number = malloc(sizeof(t_stack_number));
	if (NULL == number)
		return ;
	number->cheapest = 0;
	number->next = NULL;
	number->value = nbr;
	if (NULL == *stack)
	{
		*stack = number;
		number->prev = NULL;
	}
	else
	{
		last_number = find_last_number(*stack);
		last_number->next = number;
		number->prev = last_number;
	}
}

t_stack_number	*find_smallest(t_stack_number *stack)
{
	long			smallest;
	t_stack_number	*smallest_number;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_number = stack;
		}
		stack = stack->next;
	}
	return (smallest_number);
}

t_stack_number	*return_cheapest(t_stack_number *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_number *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
