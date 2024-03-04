/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:38 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 17:04:27 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;

	if (stacks->stack_b_count == 0)
		return (0);
	first = stacks->stack_b;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	stacks->stack_b = second;
	first->next = stacks->stack_a;
	first->prev = stacks->stack_a->prev;
	stacks->stack_a->prev->next = first;
	stacks->stack_a->prev = first;
	stacks->stack_a = first;
	stacks->stack_b_count--;
	stacks->stack_a_count++;
	if (!keep_result(stacks, "pa\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}

int	push_b(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;

	if (stacks->stack_a_count == 0)
		return (0);
	first = stacks->stack_a;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	stacks->stack_a = second;
	first->next = stacks->stack_b;
	first->prev = stacks->stack_b->prev;
	stacks->stack_b->prev->next = first;
	stacks->stack_b->prev = first;
	stacks->stack_b = first;
	stacks->stack_a_count--;
	stacks->stack_b_count++;
	if (!keep_result(stacks, "pb\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}
