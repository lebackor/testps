/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chaine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:22:20 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:47:51 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*create_liste(long long x)
{
	t_pile	*stack;

	stack = malloc(sizeof(t_pile));
	stack->content = x;
	stack->next = NULL;
	return (stack);
}

void	ft_put_begin(t_pile **a, t_pile **b)
{
	t_pile	*tmp1;

	tmp1 = create_liste((*a)->content);
	tmp1->next = *b;
	*b = tmp1;
	(*a) = (*a)->next;
}

t_pile	*ft_addback(t_pile **stack, long long x)
{
	t_pile	*t_pile;

	if (!(*stack))
		(*stack) = create_liste(x);
	else
	{
		t_pile = *stack;
		while (t_pile->next != NULL)
			t_pile = t_pile->next;
		t_pile->next = create_liste(x);
	}
	return (*stack);
}

void	rotate_rr(t_pile **a, t_pile **b)
{
	rotate(*&a, 'a');
	rotate(*&b, 'b');
}

void	reverse_rotate_rr(t_pile **a, t_pile **b)
{
	reverse_rotate(*&a, 'a');
	reverse_rotate(*&b, 'b');
	ft_printf("rra\nrrb\n");
}
