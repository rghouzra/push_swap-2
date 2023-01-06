/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:19:43 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/06 23:19:45 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_joinargv(char **av)
{
	char	*s;
	char	**ss;
	size_t	i;

	i = 1;
	s = ft_strdup(" ");
	while (av[i])
	{
		if (av[i][0] == '\0' || ft_onlyspaces(av[i]))
		{
			if (s)
				free(s);
			return (NULL);
		}
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i++]);
	}
	if (!s)
		return (NULL);
	ss = ft_split(s, ' ');
	return (free(s), ss);
}

void	frees(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (*stack)
	{
		*stack = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}

void	free_tab(char **ss)
{
	size_t	i;

	i = 0;
	while (ss[i])
		free(ss[i++]);
	free(ss);
}
