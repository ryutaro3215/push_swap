/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:22:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 16:55:53 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_four(t_stacks *stacks)
{
	int	min_index;

	min_index = get_min_index(stacks->stack_a);
	if (stacks->stack_a_count < 4)
		return (0);
	while (stacks->stack_a_count != 3)
	{
		if (stacks->stack_a->index == min_index)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
	if (!is_ascending(stacks->stack_a))
		sort_three_a(stacks);
	sort_three_a(stacks);
	push_a(stacks);
	return (1);
}

int	sort_five(t_stacks *stacks)
{
	int	min_index;

	min_index = get_min_index(stacks->stack_a);
	if (stacks->stack_a_count < 5)
		return (0);
	while (stacks->stack_a_count != 3)
	{
		if (stacks->stack_a->index == min_index
			|| stacks->stack_a->index == min_index + 1)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
	if (!is_ascending(stacks->stack_a))
		sort_three_a(stacks);
	if (is_ascending(stacks->stack_b))
		swap_b(stacks);
	push_a(stacks);
	push_a(stacks);
	return (1);
}

int	sort_more_five(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->stack_a_count > 5)
	{
		if (stacks->stack_a->index == i)
		{
			push_b(stacks);
			i++;
		}
		else
			rotate_a(stacks);
	}
	sort_five(stacks);
	while (stacks->stack_b_count != 0)
		push_a(stacks);
	return (1);
}

int	sort_few(t_stacks *stacks)
{
	if (stacks->stack_a_count == 3)
		sort_three_a(stacks);
	else if (stacks->stack_a_count == 4)
		sort_four(stacks);
	else if (stacks->stack_a_count == 5)
		sort_five(stacks);
	else
		sort_more_five(stacks);
	return (1);
}
