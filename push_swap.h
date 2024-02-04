/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:56:50 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 00:23:12 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	unsigned int	final_idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_dll
{
	int				len;
	struct s_node	*head;
	struct s_node	*tail;
}	t_dll;

t_dll			*parse_input(int argc, char **argv);
int				*sort_input(t_dll stack);
int				push_swap_atoi(const char *str);
void			free_str(char **str, int max_idx);
t_dll			*new_dll(void);
t_node			*new_node(int value);
void			free_dll(t_dll **dll);
void			push(t_dll *bucket, t_node *node);
t_node			*pull(t_dll *bucket);
void			push(t_dll *bucket, t_node *node);
t_node			*pull(t_dll *bucket);
void			append(t_dll *bucket, int value);
void			quicksort_stack(t_dll *main_stack, t_dll *temp_stack);
void			assign_idx(t_dll **stack, int *arr);
void			sort_three(t_dll **a);
void			sort_five(t_dll **a, t_dll **b);
void			radix_sort(t_dll **a, t_dll **b);
t_node			*find_biggest(t_dll *a);
unsigned int	find_max(t_dll **stack);
unsigned int	get_max_bits(t_dll **stack);
void			sort_on_bit(t_dll **stack_a, t_dll **stack_b, int bit);
void			move_back_to_a(t_dll **stack_a, t_dll **stack_b);
void			push_to(t_dll *from, t_dll *to, char *action);
void			swap(t_dll *bucket, char *action);
void			rotation(t_dll *bucket, char *action);
void			reverse_rotation(t_dll *bucket, char *action);
void			quicksort(int *arr, int lo, int hi);
int				is_sorted(t_dll *inp);
void			ft_error_m(void);
void			ft_error(void);

#endif
