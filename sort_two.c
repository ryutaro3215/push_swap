/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:57:16 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/08 15:39:39 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a->index > stacks->stack_a->next->index)
		swap_a(stacks);
	return (1);
}
