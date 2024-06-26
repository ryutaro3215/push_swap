/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:52:33 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/15 23:41:27 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

void	print_stack_a(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->stack_a;
	ft_printf("stack_a:\n");
	while (current->index != -1)
	{
		ft_printf("index: %d\n", current->index);
		ft_printf("number: %d\n", current->number);
		ft_printf("\n");
		current = current->next;
	}
}

void	print_stack_b(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->stack_b;
	ft_printf("stack_b:\n");
	while (current->index != -1)
	{
		ft_printf("index: %d\n", current->index);
		ft_printf("number: %d\n", current->number);
		ft_printf("\n");
		current = current->next;
	}
}

void	print_stack(t_stacks *stacks)
{
	print_stack_a(stacks);
	print_stack_b(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.collect_arg = 0;
	if (argc <= 1)
		return (0);
	if (!check_arg(&stacks, argc, argv))
		return (my_error(&stacks, 2, "Error\n"));
	if (is_ascending(stacks.stack_a))
		return (my_error(&stacks, 1, "already sorted\n"));
	sort(&stacks);
	if (stacks.result_flag == 0)
		return (my_error(&stacks, 2, "Error\n"));
	int	count = 0;
	int	i = 0;
	while (stacks.result_list[i] != '\0')
	{
		if (stacks.result_list[i] == '\n')
			count++;
		i++;
	}
	ft_printf("%s", stacks.result_list);
	ft_printf("count: %d\n", count);
	free_stacks(&stacks);
	return (0);
}
