#include "../includes/push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		chunk;
	int		distance;
	int		i;
	int		size;

	head = *stack_a;
	size = ft_lstsize(head);
	chunk = size / 5;
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
			else if (ft_lstsize(*stack_a) > (size - chunk))
				head = head->next;
			else
				break ;
		}
		chunk = 2 * chunk;
		i--;
	}
	simple_sort(stack_a, stack_b);
	i = size - 1;
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
