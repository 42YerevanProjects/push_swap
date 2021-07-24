#include "../includes/push_swap.h"

// Swaps first two elements of a stack | sa and sb

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;

	head = *stack;
	next = head->next;
	if (ft_lstsize(head) < 2)
		return ;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	head->value = next->value;
	next->value = tmp_val;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

// Takes the first element of one stack and puts it at the top of another | pa and pb

void	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	head_to = *stack_to;
	head_from = *stack_from;
	if (ft_lstsize(head_from) == 0)
		return ;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
}
