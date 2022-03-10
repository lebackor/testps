/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:32 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:16:04 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_run(t_pile **a, t_pile **b, t_pile *high)
{
	int	r;
	int	rr;

	r = list_begin(b, high);
	rr = list_end(high);
	if (r <= rr)
		ft_run_r(a, b, high);
	else
		ft_run_rr(a, b, high);
	return ;
}

void	ft_run_r(t_pile **a, t_pile **b, t_pile *high)
{
	t_pile	*tmp;
	t_pile	*t;

	tmp = *b;
	while (tmp->next && tmp != high)
		rotate(b, 'b');
	if (tmp == high)
	{
		t = *b;
		push_t_pile(b, a, 'a');
		free(t);
	}
}

void	ft_run_rr(t_pile **a, t_pile **b, t_pile *high)
{
	t_pile	*tmp;
	t_pile	*t;

	tmp = *b;
	while (tmp != high && tmp->next)
	{
		tmp = *b;
		if (tmp == high)
		{
			t = *b;
			push_t_pile(b, a, 'a');
			free(t);
			return ;
		}
		reverse_rotate(b, 'b');
	}
}

int	list_begin(t_pile **a, t_pile *high)
{
	int			i;
	t_pile		*tmp;

	i = 0;
	tmp = *a;
	while (tmp->next && tmp != high)
	{
		if (tmp->content == high->content)
			return (i);
		tmp = tmp->next;
		i++;
	}
	if (tmp->next == NULL && tmp != high)
		return (0);
	return (i);
}

int	list_end(t_pile *high)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = high;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
