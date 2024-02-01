/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:52:33 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/01 11:26:47 by ryutaro3205      ###   ########.fr       */
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
        ft_printf("%d\n", current->index);
        current = current->next;
    }
}

void free_stack_b(t_stacks *stacks) {
    t_node *current = stacks->stack_b;
    while (current->index != -1) {
        current = current->next;
		free(current->prev);
    }
	free(current);
}
void print_stack_a(t_stacks *stacks)
{
    t_node *current = stacks->stack_a;
    while (current->index != -1) {
        ft_printf("%d\n", current->index);
        current = current->next;
    }
}

void free_stack_a(t_stacks *stacks)
{
    t_node *current = stacks->stack_a;
    while (current->index != -1) {
        current = current->next;
		free(current->prev);
    }
	free(current);
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
	sorting(&stacks);
	return (0);
}
