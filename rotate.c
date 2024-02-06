/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:07:34 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/02 22:43:01 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate_a(t_stacks *stacks)
{
	t_node *first;
	t_node *second;
	t_node *last;

	if (stacks->stack_a_count < 2)
		return (0);
	first = stacks->stack_a;
	second = first->next;
	last = first->prev;
	stacks->stack_a = second;
	second->prev = last;
	first->next = last;
	first->prev = last->prev;
	last->prev->next = first;
	last->prev = first;
	if (!keep_result(stacks, "ra\n"))
		return (0);
	return (1);
}

int rotate_b(t_stacks *stacks)
{
	t_node *first;
	t_node *second;
	t_node *last;

	if (stacks->stack_b_count < 2)
		return (0);
	first = stacks->stack_b;
	second = first->next;
	last = first->prev;
	stacks->stack_b = second;
	second->prev = last;
	first->next = last;
	first->prev = last->prev;
	last->prev->next = first;
	last->prev = first;
	if (!keep_result(stacks, "rb\n"))
		return (0);
	return (1);
}
