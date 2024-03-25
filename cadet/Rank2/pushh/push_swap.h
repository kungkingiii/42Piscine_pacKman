/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:42:44 by utente            #+#    #+#             */
/*   Updated: 2024/03/25 19:13:54 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_number
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_count;
	bool				above_median;
	bool				cheapest;
	struct s_stack_number	*target_number;
	struct s_stack_number	*next;
	struct s_stack_number	*prev;
}	t_stack_number;

char			**ft_split(char *str, char separator);

void			free_matrix(char **argv);
void			error_free(t_stack_number **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_number **stack);
int				check_error_repeat(t_stack_number *a, int nbr);
int				error_syntax(char *str_nbr);

void			check_error(t_stack_number **a, char **argv, bool flag_argc_2);
void			init_numbers(t_stack_number *a, t_stack_number *b);
void			set_current_position(t_stack_number *stack);
void			set_price(t_stack_number *a, t_stack_number *b);
void			set_cheapest(t_stack_number *b);

void			append_number(t_stack_number **stack, int nbr);
bool			first_is_less(t_stack_number *stack);
int				stack_len(t_stack_number *stack);
void			finish_rotation(t_stack_number **s, t_stack_number *n, char c);
t_stack_number	*find_last_number(t_stack_number *head);
t_stack_number	*find_smallest(t_stack_number *stack);
t_stack_number	*return_cheapest(t_stack_number *stack);

void			handle_three(t_stack_number **a);
void			handle_five(t_stack_number **a, t_stack_number **b);
void			push_swap(t_stack_number **a, t_stack_number **b);

void			sa(t_stack_number **a, bool checker);
void			sb(t_stack_number **b, bool checker);
void			ss(t_stack_number **a, t_stack_number **b, bool checker);
void			ra(t_stack_number **a, bool checker);
void			rb(t_stack_number **b, bool checker);
void			rr(t_stack_number **a, t_stack_number **b, bool checker);
void			rra(t_stack_number **a, bool checker);
void			rrb(t_stack_number **b, bool checker);
void			rrr(t_stack_number **a, t_stack_number **b, bool checker);
void			pa(t_stack_number **a, t_stack_number **b, bool checker);
void			pb(t_stack_number **b, t_stack_number **a, bool checker);

#endif
