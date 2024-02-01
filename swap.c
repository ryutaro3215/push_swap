/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:47 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/01/31 13:06:06 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_a(t_stacks *stacks)
{
	t_node *tmp;

	if (stacks->stack_a_count < 2)
		return (0);
	tmp = stacks->stack_a->next;
	stacks->stack_a->next = tmp->next;
	tmp->next->prev = stacks->stack_a;
	tmp->prev = stacks->stack_a->prev;
	tmp->next = stacks->stack_a;
	stacks->stack_a->prev = tmp;
	stacks->stack_a = tmp;
	return (1);
}

int swap_b(t_stacks *stacks)
{
	t_node *tmp;

	if (stacks->stack_b_count < 2)
		return (0);
	tmp = stacks->stack_b->next;
	stacks->stack_b->next = tmp->next;
	tmp->next->prev = stacks->stack_b;
	tmp->prev = stacks->stack_b->prev;
	tmp->next = stacks->stack_b;
	stacks->stack_b->prev = tmp;
	stacks->stack_b = tmp;
	return (1);
}
// int	swap_a(t_stacks *stacks)
// {
// 	t_node	*tmp;

// 	if (stacks->stack_a_count < 2)
// 		return (0);
// 	tmp = stacks->stack_a->next;
// 	stacks->stack_a->next = tmp->next;
// 	tmp->prev = stacks->stack_a->prev;
// 	stacks->stack_a->prev = tmp;
// 	tmp->next = stacks->stack_a;
// 	tmp->next->prev = tmp;
// 	stacks->stack_a = tmp;
// 	return (1);
// }
