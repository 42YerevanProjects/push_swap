#include "../includes/push_swap.h"
#include <stdio.h>

void	cent_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		chunk;
	int		i;
	int		distance;

	head = *stack_a;
	chunk = 20;
	i = 5;
	while (i > 0)
	{
		while (ft_lstsize(*stack_a) != 0)
		{
			if (head->index < chunk)
			{
				distance = get_distance(stack_a, head->index);
				make_top(stack_a, distance);
				pb(stack_a, stack_b);
				head = *stack_a;
			}
			else if (ft_lstsize(*stack_a) > (100 - chunk))
				head = head->next;
			else
				break ;
		}
		chunk = chunk + 20;
		i--;
	}
	i = 99;
	while (i >= 0)
	{
		head = *stack_b;
		while (ft_lstsize(*stack_b) != 0)
		{
			if (head->index == i)
			{
				distance = get_distance(stack_b, i);
				make_top(stack_b, distance);
				pa(stack_a, stack_b);
				break ;
			}
			else
				head = head->next;
		}
		i--;
	}
}
