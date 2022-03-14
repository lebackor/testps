/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:28:37 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:32:32 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_x(t_pile **stack, char c)
{
	t_pile	*t1;
	t_pile	*t2;

	t1 = (*stack)->next;
	t2 = *stack;
	t2->next = t2->next->next;
	t1->next = t2;
	*stack = t1;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	swap_ss(t_pile **a, t_pile **b, char c)
{
	swap_x(*&a, c);
	swap_x(*&b, c);
}

void	push_t_pile(t_pile **stack1, t_pile **stack2, char c)
{
	t_pile	*tmp;

	tmp = *stack1;
	if (!*stack2)
	{
		*stack2 = create_liste((*stack1)->content);
		(*stack1) = (*stack1)->next;
		if (tmp != NULL)
			free(tmp);
		if (c == 'a')
			ft_printf("pa\n");
		else if (c == 'b')
			ft_printf("pb\n");
		return ;
	}
	ft_put_begin(stack1, stack2);
	if (tmp != NULL)
		free(tmp);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
	return ;
}

void	rotate(t_pile **stack, char c)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	(*stack) = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp->next->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_pile **stack, char c)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = (*stack);
	(*stack) = tmp2;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
