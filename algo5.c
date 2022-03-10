/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:44:38 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 16:56:29 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_run_5(t_pile **a, t_pile **b, t_pile *high)
{
	int	r;
	int	rr;

	r = list_begin(a, high);
	rr = list_end(high);
	if (r <= rr)
		ft_run_r_5(a, b, high);
	else
		ft_run_rr_5(a, b, high);
	return ;
}

void	algo_5(t_pile **a, t_pile **b)
{
	t_pile	*low;

	while (ft_strlenlist(a) > 3)
	{
		low = find_lowest_nb(a);
		list_run_5(a, b, low);
	}
	algo_3(a);
	while (ft_strlenlist(b))
		push_t_pile(b, a, 'a');
}

t_pile	*find_lowest_nb(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*f;

	f = *a;
	tmp = (*a)->next;
	while ((f)->next)
	{
		if ((f)->content < tmp->content)
			tmp = f;
		(f) = (f)->next;
	}
	if ((f)->content < tmp->content)
		tmp = f;
	return (tmp);
}

void	ft_run_r_5(t_pile **a, t_pile **b, t_pile *high)
{
	t_pile	*tmp;

	tmp = *a;
	while (tmp->next && tmp != high)
		rotate(a, 'a');
	if (tmp == high)
		push_t_pile(a, b, 'b');
}

void	ft_run_rr_5(t_pile **a, t_pile **b, t_pile *high)
{
	t_pile	*tmp;

	tmp = *a;
	while (tmp != high && tmp->next)
	{
		tmp = *a;
		if (tmp == high)
		{
			push_t_pile(a, b, 'b');
			return ;
		}
		reverse_rotate(a, 'a');
	}
}
