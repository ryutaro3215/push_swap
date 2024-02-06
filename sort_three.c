/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:05:11 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/02 22:41:34 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stacks *stacks)
{
	if (stacks->stack_a->index == 0)
	{
		push_b(stacks);
		swap_a(stacks);
		push_a(stacks);
	}
	else if (stacks->stack_a->index == 1)
	{
		if (stacks->stack_a->next->index == 0)
			swap_a(stacks);
		else
			r_rotate_a(stacks);
	}
	else
	{
		if (stacks->stack_a->next->index == 0)
			rotate_a(stacks);
		else
		{
			rotate_a(stacks);
			swap_a(stacks);
		}
	}
	return (1);
}
