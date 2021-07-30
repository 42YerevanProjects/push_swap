#include "../includes/push_swap.h"

static void	decrement_index(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		head->index--;
		head = head->next;
	}
}

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
	int	distance;

	distance = get_distance(stack_a, 0);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	decrement_index(stack_a);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, 0);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	decrement_index(stack_a);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
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
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
