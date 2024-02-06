/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:09 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/01 23:40:32 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = stacks->stack_a;
	while (tmp->index != -1)
	{
		if (tmp->index > tmp->next->index && tmp->next->index != -1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	sort(t_stacks *stacks)
{
	if (stacks->stack_a_count == 2)
		sort_two(stacks);
	else if (stacks->stack_a_count == 3)
		sort_three(stacks);
	// else if (stacks->stack_a_count == 4)
	// 	sort_four(stacks);
	// else if (stacks->stack_a_count == 5)
	// 	sort_five(stacks);
	// else
	// 	sort_many(stacks);
	return (1);
}
