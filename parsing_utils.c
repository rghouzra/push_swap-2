/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:19:43 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 00:21:02 by bel-idri         ###   ########.fr       */
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



void	ft_free_tab(char **ss)
{
	size_t	i;

	i = 0;
	while (ss[i])
		free(ss[i++]);
	free(ss);
}
