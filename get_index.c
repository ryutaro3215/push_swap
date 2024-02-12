/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:46:12 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/09 20:55:10 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack->index != -1)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_min_index(t_node *stack)
{
	int	min;

	min = stack->index;
	while (stack->index != -1)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
