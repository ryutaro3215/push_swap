/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:12:59 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/01/30 23:09:58 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_node
{
	int					index;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

typedef struct s_stacks
{
	int	collect_arg;
	int	malloc_flag;
	int	arg_count;
	t_node	*stack_a;
	t_node	*stack_b;
}				t_stacks;

/*check argument*/
char **make_arg_list(t_stacks *stacks, int argc, char **argv);
int range_of_int(char *number);
int	collect_number(char *number);
int	is_number(char **arg_list);
int	check_arg(t_stacks *stacks, int argc, char **argv);
int	arg_free(char **arg_list, t_stacks *stacks, int return_value);
int	make_stack_a(t_stacks *stacks, char **arg_list);
int	push_stack(t_stacks *stacks, int index);
void	stack_free(t_node *stack);
int	get_index(char **arg_list, char *arg_num);
void print_stack_a(t_stacks *stacks);


#endif
