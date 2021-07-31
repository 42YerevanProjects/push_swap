#include "../includes/push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		distance;
	int		i;

	head = *stack_a;
	i = 0;
	while (ft_lstsize(*stack_a) != 1)
	{
		distance = get_distance(stack_a, i++);
		make_top(stack_a, distance);
		pb(stack_a, stack_b);
		head = *stack_a;
	}
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}
