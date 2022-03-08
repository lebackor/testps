/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:36:56 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 18:41:19 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (!check_notnb(av, ac) || !fill_list(ac, av, &a))
		return (ft_printf("Error\n"));
	if (is_tried(&a) || ft_strlenlist(&a) < 2)
		return (ft_degage(&a));
	if (ft_strlenlist(&a) > 2)
		init_algo(&a, &b);
	else
	{
		if (a->content > a->next->content)
			swap_x(&a, 'a');
	}
	return (ft_degage(&a));
}

int	fill_list(int ac, char **av, t_pile **a)
{
	int			i;
	long long	nb;

	i = 0;
	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		*a = ft_addback(a, nb);
		if (!check_duplicates_or_limits(*a))
			return (0);
	}
	return (1);
}

int	is_tried(t_pile **a)
{
	t_pile	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

int	ft_strlenlist(t_pile **a)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	if (!(*a))
		return (0);
	tmp = *a;
	while ((tmp)->next)
	{
		(tmp) = (tmp)->next;
		i++;
	}
	if (tmp->next == NULL && (tmp->content || tmp->content == 0))
		i++;
	return (i);
}

int	ft_degage(t_pile **a)
{
	t_pile	*tmp;

	tmp = *a;
	if (*a)
	{
		while ((*a))
		{
			tmp = (*a)->next;
			free(*a);
			(*a) = (tmp);
		}
	}
	return (1);
}
