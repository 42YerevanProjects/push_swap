#include "../includes/push_swap.h"

static void	sort_3(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (head->index == 0 && head->next->index != 1)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == 1)
	{
		if (head->next->index == 0)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		distance;

	head_a = *stack_a;
	distance = 0;
	while (head_a)
	{
		if (head_a->index == 3)
			break ;
		distance++;
		head_a = head_a->next;
	}
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else 
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
}
