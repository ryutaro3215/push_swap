/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:12:59 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/11 19:08:19 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct s_node
{
	int					index;
	int					number;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

typedef struct s_stacks
{
	int		collect_arg;
	int		malloc_flag;
	int		arg_count;
	int		stack_a_count;
	int		stack_b_count;
	int		result_flag;
	char	*result_list;
	t_node	*stack_a;
	t_node	*stack_b;
}				t_stacks;

/*check argument*/
int		check_arg(t_stacks *stacks, int argc, char **argv);
char 	**make_arg_list(t_stacks *stacks, int argc, char **argv);
int		is_number(char **arg_list);
int 	range_of_int(char *number);
int		collect_number(char *number);
int		is_duplicate(char **arg_list);
int		init_stack(t_stacks *stacks, char **arg_list);
int		malloc_stacks(t_stacks *stacks);
int		make_stack_a(t_stacks *stacks, int index, char *arg_num);
int		get_index(char **arg_list, char *arg_num);
int		is_ascending(t_node *stack);
int		is_descending(t_node *stack);
/*about free*/
int		my_error(t_stacks *stacks, int er_num, char *str);
int		arg_free(char **arg_list, t_stacks *stacks, int return_value);
void	free_stack_a(t_stacks *stacks);
void	free_stack_b(t_stacks *stacks);
void	free_stacks(t_stacks *stacks);
/*swap*/
int		swap_a(t_stacks *stacks);
int 	swap_b(t_stacks *stacks);
/*rotate*/
int		rotate_a(t_stacks *stacks);
int 	rotate_b(t_stacks *stacks);
/*r_rotate*/
int 	r_rotate_a(t_stacks *stacks);
int 	r_rotate_b(t_stacks *stacks);
/*push*/
int		push_a(t_stacks *stacks);
int		push_b(t_stacks *stacks);
/*sort*/
int		sort(t_stacks *stacks);
int		sort_two(t_stacks *stacks);
int		sort_three_a(t_stacks *stacks);
int		sort_three_b(t_stacks *stacks);
int		sort_four(t_stacks *stacks);
int		sort_five(t_stacks *stacks);
int		sort_more_five(t_stacks *stacks);
int		sort_few(t_stacks *stacks);
int		sort_many(t_stacks *stacks);
// int	sort_many(t_stacks *stacks);
/*get index*/
int		get_max_index(t_node *stack);
int		get_min_index(t_node *stack);
/*result*/
int		keep_result(t_stacks *stacks, char *str);
void	print_stack_a(t_stacks *stacks);
void 	print_stack_b(t_stacks *stacks);
void	print_stack(t_stacks *stacks);



#endif
