/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:56:45 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:11:40 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_pile **a)
{
	while (!is_tried(a))
	{
		if ((*a)->content > (*a)->next->content)
			swap_x(a, 'a');
		else if ((*a)->next->content > (*a)->next->next->content)
			reverse_rotate(a, 'a');
	}
}

void	init_algo(t_pile **a, t_pile **b)
{
	if (ft_strlenlist(a) == 3)
		algo_3(a);
	else if (ft_strlenlist(a) < 10)
		algo_5(a, b);
	else
	{
		clean_a(a, b);
		while (ft_strlenlist(b) > 1)
			find_in_b_max(a, b);
		if ((*b))
			push_t_pile(b, a, 'a');
	}
}

void	find_in_b_max(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	tmp = find_higher_nb(b);
	list_run(a, b, tmp);
}

t_pile	*find_higher_nb(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*f;

	f = *a;
	tmp = (*a)->next;
	while ((f)->next)
	{
		if ((f)->content > tmp->content)
			tmp = f;
		(f) = (f)->next;
	}
	if ((f)->content > tmp->content)
		tmp = f;
	return (tmp);
}
