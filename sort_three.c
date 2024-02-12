/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:05:11 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/08 21:21:15 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_a(t_stacks *stacks)
{
	if (stacks->stack_a->index < stacks->stack_a->next->index)
	{
		if (stacks->stack_a->index > stacks->stack_a->next->next->index)
			r_rotate_a(stacks);
		else
		{
			push_b(stacks);
			swap_a(stacks);
			push_a(stacks);
		}
	}
	else if (stacks->stack_a->index > stacks->stack_a->next->index
			&& stacks->stack_a->next->index < stacks->stack_a->next->next->index)
	{
		if (stacks->stack_a->index < stacks->stack_a->next->next->index)
			swap_a(stacks);
		else
			rotate_a(stacks);
	}
	else
	{
		swap_a(stacks);
		r_rotate_a(stacks);
	}
	return (1);
}

int	sort_three_b(t_stacks *stacks)
{
	if (stacks->stack_b->index < stacks->stack_b->next->index)
	{
		if (stacks->stack_b->index > stacks->stack_b->next->next->index)
			r_rotate_a(stacks);
		else
		{
			push_a(stacks);
			swap_b(stacks);
			push_b(stacks);
		}
	}
	else if (stacks->stack_b->index > stacks->stack_b->next->index
			&& stacks->stack_b->next->index < stacks->stack_b->next->next->index)
	{
		if (stacks->stack_b->index < stacks->stack_b->next->next->index)
			swap_b(stacks);
		else
			rotate_b(stacks);
	}
	else
	{
		swap_b(stacks);
		r_rotate_b(stacks);
	}
	return (1);
}
