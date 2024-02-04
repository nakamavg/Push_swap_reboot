/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:55:53 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/03 23:34:33 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(const char *str)
{
	int		operator;
	char	*og;
	long	output;

	og = ft_strdup(str);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	operator = 1;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str++ == '-')
			operator *= -1;
	}
	output = 0;
	while (ft_isdigit(*str))
		output = output * 10 + (*str++ - '0');
	return (free(og), output * operator);
}

void	free_str(char **str, int max_idx)
{
	int	idx;

	idx = 0;
	while (idx < max_idx)
		free(str[idx++]);
}
