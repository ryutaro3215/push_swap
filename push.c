/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:38 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/01 10:51:01 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->stack_b_count == 0)
		return (0);
	tmp = stacks->stack_b;
	stacks->stack_b->next->prev = tmp->prev;
	stacks->stack_b->prev->next = tmp->next;
	stacks->stack_b = tmp->next;
	stacks->stack_a->prev->next = tmp;
	tmp->prev = stacks->stack_a->prev;
	tmp->next = stacks->stack_a;
	stacks->stack_a->prev = tmp;
	stacks->stack_a = tmp;
	stacks->stack_b_count--;
	stacks->stack_a_count++;
	return	(1);
}

int	push_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->stack_a_count == 0)
		return (0);
	tmp = stacks->stack_a;
	stacks->stack_a->next->prev = tmp->prev;
	stacks->stack_a->prev->next = tmp->next;
	stacks->stack_a = tmp->next;
	stacks->stack_b->prev->next = tmp;
	tmp->prev = stacks->stack_b->prev;
	tmp->next = stacks->stack_b;
	stacks->stack_b->prev = tmp;
	stacks->stack_b = tmp;
	stacks->stack_a_count--;
	stacks->stack_b_count++;
	return	(1);
}
