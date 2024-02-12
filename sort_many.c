/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:17:19 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/12 21:05:55 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_many(t_stacks *stacks)
{
	int	quarter;
	int counter;
	int	max_index;
	int	i;

	max_index = get_max_index(stacks->stack_a);
	counter = 0;
	i = 0;
	quarter = stacks->stack_a_count / 8;
	while (i < 8)
	{
		while (counter < quarter * i)
		{
			if (stacks->stack_a->index < quarter * i)
			{
				push_b(stacks);
				counter++;
			}
			else
				rotate_a(stacks);
		}
		i++;
	}
	while (stacks->stack_a->index != -1)
			push_b(stacks);
	while (stacks->stack_b->index != -1)
	{
		if (stacks->stack_b->index == max_index)
		{
			push_a(stacks);
			max_index--;
		}
		else if (stacks->stack_b->index == max_index - 1
			&& stacks->stack_b->next->index == max_index)
			swap_b(stacks);
		else if (stacks->stack_b->prev->index == max_index)
			r_rotate_b(stacks);
		else
			rotate_b(stacks);
	}
	return (1);
}
