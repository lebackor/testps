/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:34:13 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:46:29 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_put_tab(t_pile **a)
{
	char		**str;
	t_pile		*tmp;
	int			i;

	tmp = *a;
	i = 0;
	str = malloc(sizeof(char *) * ft_strlenlist(a) + 2);
	while (tmp->next)
	{
		str[i] = ft_itoa(tmp->content);
		tmp = tmp->next;
		i++;
	}
	if ((tmp->content && tmp->next == NULL)
		|| (tmp->next == NULL && tmp->content == 0))
	{
		str[i] = ft_itoa(tmp->content);
		str[++i] = NULL;
		return (str);
	}
	str[++i] = NULL;
	return (str);
}

void	clean_a(t_pile **a, t_pile **b)
{
	while (ft_strlenlist(a) > 2)
		begin_median(a, b);
	if ((*a)->content > (*a)->next->content)
		swap_x(a, 'a');
}

void	begin_median(t_pile **a, t_pile **b)
{
	char		**str;
	int			i;
	int			j;

	j = 0;
	str = ft_put_tab(a);
	i = trie_tab(str, a);
	if ((*a)->content == i)
	{
		rotate(a, 'a');
		return ;
	}
	while (j < ft_strlenlist(a))
	{
		if ((*a)->content < i)
			push_t_pile(a, b, 'b');
		else
			rotate(a, 'a');
		j++;
	}
}

int	trie_tab(char **str, t_pile **a)
{
	int			i;
	int			j;
	char		*swp;

	i = 0;
	j = ft_strlenlist(a) - 1;
	while (j > 0)
	{
		if (ft_atoi(str[i]) > ft_atoi(str[j]))
		{
			swp = str[i];
			str[i] = str[j];
			str[j] = swp;
			i++;
		}
		else
			i++;
		if (i == j)
		{
			i = 0;
			j--;
		}
	}
	return (ft_return(a, str));
}

int	ft_return(t_pile **a, char **str)
{
	int	i;

	if (ft_strlenlist(a) > 100)
	{
		i = ft_atoi(str[(ft_strlenlist(a)) / 7]);
		ft_free_table(str);
	}
	else
	{
		i = ft_atoi(str[(ft_strlenlist(a)) / 3]);
		ft_free_table(str);
	}
	return (i);
}
