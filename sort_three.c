/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:05:11 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 17:34:31 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_a(t_stacks *stacks)
{
	if (stacks->stack_a->index < stacks->stack_a->next->index)
	{
		if (stacks->stack_a->index > stacks->stack_a->next->next->index)
			r_rotate_a(stacks, 1);
		else
		{
			push_b(stacks);
			swap_a(stacks, 1);
			push_a(stacks);
		}
	}
	else if (stacks->stack_a->index > stacks->stack_a->next->index
		&& stacks->stack_a->next->index < stacks->stack_a->next->next->index)
	{
		if (stacks->stack_a->index < stacks->stack_a->next->next->index)
			swap_a(stacks, 1);
		else
			rotate_a(stacks, 1);
	}
	else
	{
		swap_a(stacks, 1);
		r_rotate_a(stacks, 1);
	}
	return (1);
}

int	sort_three_b(t_stacks *stacks)
{
	if (stacks->stack_b->index < stacks->stack_b->next->index)
	{
		if (stacks->stack_b->index > stacks->stack_b->next->next->index)
			r_rotate_a(stacks, 1);
		else
		{
			push_a(stacks);
			swap_b(stacks, 1);
			push_b(stacks);
		}
	}
	else if (stacks->stack_b->index > stacks->stack_b->next->index
		&& stacks->stack_b->next->index < stacks->stack_b->next->next->index)
	{
		if (stacks->stack_b->index < stacks->stack_b->next->next->index)
			swap_b(stacks, 1);
		else
			rotate_b(stacks, 1);
	}
	else
	{
		swap_b(stacks, 1);
		r_rotate_b(stacks, 1);
	}
	return (1);
}
