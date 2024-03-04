/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:47 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 16:52:52 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->stack_a_count < 2)
		return (0);
	tmp = stacks->stack_a->next;
	stacks->stack_a->prev->next = tmp;
	tmp->next->prev = stacks->stack_a;
	stacks->stack_a->next = tmp->next;
	tmp->prev = stacks->stack_a->prev;
	tmp->next = stacks->stack_a;
	stacks->stack_a->prev = tmp;
	stacks->stack_a = tmp;
	if (!keep_result(stacks, "sa\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}

int	swap_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->stack_b_count < 2)
		return (0);
	tmp = stacks->stack_b->next;
	stacks->stack_b->prev->next = tmp;
	tmp->next->prev = stacks->stack_b;
	stacks->stack_b->next = tmp->next;
	tmp->prev = stacks->stack_b->prev;
	tmp->next = stacks->stack_b;
	stacks->stack_b->prev = tmp;
	stacks->stack_b = tmp;
	if (!keep_result(stacks, "sb\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}

int	swap_ss(t_stacks *stacks)
{
	if (!swap_a(stacks) || !swap_b(stacks))
		return (0);
	if (!keep_result(stacks, "ss\n"))
	{
		stacks->result_flag = 0;
		return (0);
	}
	return (1);
}
