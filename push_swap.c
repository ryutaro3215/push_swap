/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:52:33 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/06 00:45:53 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

void print_stack_b(t_stacks *stacks) {
    t_node *current = stacks->stack_b;
    while (current->index != -1) {
        ft_printf("index: %d\n", current->index);
		ft_printf("number: %d\n", current->number);
		ft_printf("\n");
        current = current->next;
    }
}

void print_stack_a(t_stacks *stacks)
{
    t_node *current = stacks->stack_a;
    while (current->index != -1) {
        ft_printf("index: %d\n", current->index);
		ft_printf("number: %d\n", current->number);
		ft_printf("\n");
        current = current->next;
    }
}

int main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.collect_arg = 0;
	if (argc <= 1)
		return (0);
	if (!check_arg(&stacks, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	// if (!is_sorted(&stacks))
	// {
	// 	ft_printf("alraedy sorted\n");
	// 	free_stacks(&stacks);
	// 	return (0);
	// }
	// print_stack_a(&stacks);
	// push_b(&stacks);
	// push_b(&stacks);
	// push_b(&stacks);
	// print_stack_b(&stacks);
	// push_a(&stacks);
	free_stacks(&stacks);
	return (1);
}
