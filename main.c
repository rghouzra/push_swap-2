/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:15:16 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 16:36:14 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	if (!ft_parsing(&stack_a, av))
		return (write(1, "Error\n", 6), 1);
	ft_push_swap(&stack_a, &stack_b);

	// if (ft_is_sort(stack_a))
	// 	printf("good");
	// else
	// 	printf("bad");
	
	printf("\na\n");
	while(stack_a)
	{
		printf("%d\n",stack_a->content);
		stack_a = stack_a->next;
	}

	printf("\nb\n");
	while(stack_b)
	{
		printf("%d\n",stack_b->content);
		stack_b = stack_b->next;
	}
	return (0);
}
