/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:18:54 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/02 22:43:38 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int r_rotate_a(t_stacks *stacks)
{
	t_node *last;
	t_node *second_last;
	t_node *top;

	if (stacks->stack_a_count < 2)
		return (0);
	last = stacks->stack_a->prev;
	second_last = last->prev;
	top = stacks->stack_a;
	stacks->stack_a = second_last;
	second_last->prev->next = last;
	last->prev = second_last->prev;
	last->next = second_last;
	second_last->prev = last;
	second_last->next = top;
	top->prev = second_last;
	if (!keep_result(stacks, "rra\n"))
		return (0);
	return (1);
}

int r_rotate_b(t_stacks *stacks)
{
	t_node *last;
	t_node *second_last;
	t_node *top;

	if (stacks->stack_b_count < 2)
		return (0);
	last = stacks->stack_b->prev;
	second_last = last->prev;
	top = stacks->stack_b;
	stacks->stack_b = second_last;
	second_last->prev->next = last;
	last->prev = second_last->prev;
	last->next = second_last;
	second_last->prev = last;
	second_last->next = top;
	top->prev = second_last;
	if (!keep_result(stacks, "rrb\n"))
		return (0);
	return (1);
}
