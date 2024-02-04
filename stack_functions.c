/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:56:38 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 10:51:28 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_dll *from, t_dll *to, char *action)
{
	t_node	*node;

	if (!from->head || !to)
		return ;
	node = pull(from);
	push(to, node);
	ft_printf("%s\n", action);
}

void	append(t_dll *bucket, int value)
{
	t_node	*node;
	t_node	*tmp;

	if (!bucket)
		return ;
	node = new_node(value);
	if (!bucket->tail)
	{
		bucket->tail = node;
		bucket->head = node;
	}
	else
	{
		tmp = bucket->tail;
		bucket->tail = node;
		bucket->tail->prev = tmp;
		bucket->tail->prev->next = bucket->tail;
	}
	bucket->len++;
}

void	swap(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len < 2)
		return ;
	tmp = bucket->head;
	bucket->head = bucket->head->next;
	bucket->head->prev = tmp->prev;
	tmp->next = bucket->head->next;
	bucket->head->next = tmp;
	tmp->prev = bucket->head;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	if (bucket->tail == tmp)
		bucket->tail = bucket->head;
	ft_printf("%s\n", action);
}

void	rotation(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len <= 1)
		return ;
	tmp = bucket->head;
	bucket->head = tmp->next;
	tmp->prev = bucket->tail;
	tmp->prev->next = tmp;
	bucket->tail = tmp;
	tmp->next = bucket->head;
	ft_printf("%s\n", action);
}

void	reverse_rotation(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len <= 1)
		return ;
	tmp = bucket->tail;
	bucket->tail = tmp->prev;
	bucket->tail->next = bucket->head;
	tmp->prev = bucket->tail;
	tmp->next = bucket->head;
	bucket->head->prev = tmp;
	bucket->head = tmp;
	ft_printf("%s\n", action);
}
