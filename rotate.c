/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:07:34 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 17:00:36 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stacks->stack_a_count < 2)
		return (0);
	first = stacks->stack_a;
	second = first->next;
	last = first->prev;
	last->prev->next = first;
	first->next = last;
	first->prev = last->prev;
	second->prev = last;
	last->next = second;
	last->prev = first;
	stacks->stack_a = second;
	if (!keep_result(stacks, "ra\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}

int	rotate_b(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stacks->stack_b_count < 2)
		return (0);
	first = stacks->stack_b;
	second = first->next;
	last = first->prev;
	last->prev->next = first;
	first->next = last;
	first->prev = last->prev;
	second->prev = last;
	last->next = second;
	last->prev = first;
	stacks->stack_b = second;
	if (!keep_result(stacks, "rb\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}

int	rotate_rr(t_stacks *stacks)
{
	if (!rotate_a(stacks) || !rotate_b(stacks))
		return (0);
	if (!keep_result(stacks, "rr\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}
