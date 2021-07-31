#include "../includes/push_swap.h"

static void	treat_stack_a(t_list **stack_a, t_list **stack_b, int chunk)
{
	t_list	*head;
	int		distance;

	head = *stack_a;
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
}

static void	treat_stack_b(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*head;
	int		distance;

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
}

void	cent_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		chunk;

	chunk = 20;
	i = 5;
	while (i-- > 0)
	{
		treat_stack_a(stack_a, stack_b, chunk);
		chunk = 2 * chunk;
	}
	if (!is_sorted(stack_a))
		sa(stack_a);
	i = 99;
	while (i >= 0)
		treat_stack_b(stack_a, stack_b, i--);
}
