/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:32:30 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 18:32:36 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_pile
{
	int				content;
	struct t_pile	*next;
}t_pile;

int		*ft_convert(const char *str);
t_pile	*create_liste(long long x);
t_pile	*ft_addback(t_pile **stack, long long x);
int		check_duplicates_or_limits(t_pile *liste);
int		is_sorted(t_pile *liste);
void	swap_x(t_pile **stack, char c);
void	push_t_pile(t_pile **stack1, t_pile **stack2, char c);
void	print_liste(t_pile **test);
void	rotate(t_pile **stack, char c);
void	reverse_rotate(t_pile **stack, char c);
void	swap_ss(t_pile **a, t_pile **b, char c);
void	rotate_rr(t_pile **a, t_pile **b);
void	reverse_rotate_rr(t_pile **a, t_pile **b);
int		check_notnb(char **av, int ac);
void	init_algo(t_pile **a, t_pile **b);
t_pile	*find_higher_nb(t_pile **a);
void	search_t_pile_b(t_pile **a, t_pile **b);
void	begin_median(t_pile **a, t_pile **b);
int		ft_strlenlist(t_pile **a);
int		*list_on_tab(t_pile **a);
char	**ft_put_tab(t_pile **a);
void	clean_a(t_pile **a, t_pile **b);
void	ft_put_begin(t_pile **a, t_pile **b);
int		is_tried(t_pile **a);
void	algo_3(t_pile **a);
int		fill_list(int ac, char **av, t_pile **a);
void	ft_run_r(t_pile **a, t_pile **b, t_pile *high);
void	ft_run_rr(t_pile **a, t_pile **b, t_pile *high);
int		list_begin(t_pile **a, t_pile *high);
int		list_end(t_pile *high);
void	find_in_b_max(t_pile **a, t_pile **b);
t_pile	*find_lowest_nb(t_pile **a);
void	list_run_5(t_pile **a, t_pile **b, t_pile *high);
void	ft_run_rr_5(t_pile **a, t_pile **b, t_pile *high);
void	ft_run_r_5(t_pile **a, t_pile **b, t_pile *high);
void	algo_5(t_pile **a, t_pile **b);
void	algo_3(t_pile **a);
void	list_run(t_pile **a, t_pile **b, t_pile *high);
int		trie_tab(char **str, t_pile **a);
void	split_b(t_pile **b);
int		ft_return(t_pile **a, char **str);
int		ft_degage(t_pile **a);
#endif
