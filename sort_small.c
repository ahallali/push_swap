/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:34 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 00:00:45 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->a [0] > stack->a[1] && stack->a[1] < stack->a[2] \
	&& stack->a[0] < stack->a[2])
		sa(stack->a, 3, 3);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2] \
	&& stack->a[0] > stack->a[2])
	{
		sa(stack->a, 3, 3);
		rra(stack, 1);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] \
	&& stack->a[0] > stack->a[2])
		ra(stack, 1);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] \
	&& stack->a[0] < stack->a[2])
	{
		sa(stack->a, 3, 3);
		ra(stack, 1);
	}
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] \
		&& stack->a[0] > stack->a[2])
		rra(stack, 1);
}

void	sort_4(t_stack *stack)
{
	int	min;

	min = min_stack(stack->a, 4);
	if (min <= stack->lena / 2)
	{
		while (min > 1)
		{
			ra(stack, 1);
			min--;
		}
	}
	else
	{
		while (min <= stack->lena)
		{
			rra(stack, 1);
			min++;
		}
	}
	pb(stack);
	sort_3(stack);
	pa(stack);
}

void	sort_5(t_stack *stack)
{
	int	min;

	min = min_stack(stack->a, 5);
	if (min <= stack->lena / 2)
	{
		while (min > 1)
		{
			ra(stack, 1);
			min--;
		}
	}
	else
	{
		while (min <= stack->lena)
		{
			rra(stack, 1);
			min++;
		}
	}
	pb(stack);
	sort_4(stack);
	pa(stack);
}
