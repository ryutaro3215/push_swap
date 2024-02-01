/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:07:34 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/01/31 15:20:58 by ryutaro3205      ###   ########.fr       */
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
	return (1);
}

int rotate_b(t_stacks *stacks)
{
	t_node *first;
	t_node *second;
	t_node *sentinel;

	if (stacks->stack_b_count < 2)
		return (0);
	first = stacks->stack_b;
	second = first->next;
	sentinel = first->prev;
	stacks->stack_b = second;
	second->prev = sentinel;
	first->next = sentinel;
	first->prev = sentinel->prev;
	sentinel->prev->next = first;
	sentinel->prev = first;
	return (1);
}
