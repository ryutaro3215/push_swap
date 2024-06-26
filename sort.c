/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:09 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/12 00:20:22 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stacks *stacks)
{
	stacks->result_flag = 1;
	if (stacks->stack_a_count == 2)
		sort_two(stacks);
	else if (stacks->stack_a_count <= 10)
		sort_few(stacks);
	else
		sort_many(stacks);
	return (1);
}
