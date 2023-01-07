/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:59:31 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 16:40:01 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

# define MAX INT_MAX
# define MIN INT_MIN

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

long long	ft_my_atio(char *str, int i, int sign);
int			ft_count_words(char *s, char c);
long long	ft_atoi(char *str);
size_t		ft_strlen(char *s);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
void		ft_free(char **str);
char		**ft_my_split(char *s, char c, int start, int end);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
size_t		ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_swap(t_list **stack);
void		ft_swap_abs(t_list **stack_a, t_list **stack_b, char c);
int			ft_push(t_list **stack_recv, t_list **stack_givn);
void		ft_push_ab(t_list **stack_a, t_list **stack_b, char c);
int			ft_rotate(t_list **stack);
void		ft_rotate_abr(t_list **stack_a, t_list **stack_b, char c);
void		ft_reverse_rotate_abr(t_list **stack_a, t_list **stack_b, char c);
int			ft_reverse_rotate(t_list **stack);
int			ft_onlyspaces(char *av);
int			ft_digit(char **av);
int			ft_longer(char **av);
int 		ft_duplicat(char **av);
int			ft_parsing(t_list **stack_a, char **av);
char		**ft_joinargv(char **av);
void		ft_free_tab(char **ss);
void		ft_push_swap(t_list **stack_a, t_list **stack_b);
int 		ft_get_min(t_list *stack);
int			ft_is_sort_rev(t_list *stack);
int			ft_is_sort(t_list *stack);
void		ft_sort_rev(t_list **stack_a, t_list **stack_b);
void		ft_sort_three(t_list **stack_a);
void		ft_sort_five(t_list **stack_a, t_list **stack_b);
void		ft_sort(t_list **stack_a, t_list **stack_b);
int			ft_is_up_down(t_list *stack);
int			*ft_lst_to_arr(t_list *stack);
int			ft_get_max(int *arr, t_list *stack);
int			*ft_get_lis(t_list **stack);
void		ft_free_stack(t_list **stack); // ba9i makhademta
int			*ft_get_content(t_list **stack);
void		set_index(t_list **stack);
int			ft_get_index_of_max(int *arr, int max);
void		best_move_lis(t_list **stack);

#endif
