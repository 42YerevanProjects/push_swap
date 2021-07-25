#include "../includes/push_swap.h"

// Swaps first two elements of a stack | sa and sb

static void	swap(t_list **stack)
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

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}

// Takes the first element of one stack and puts it at the top of another | pa and pb

static void	push(t_list **stack_to, t_list **stack_from)
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

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}

// Shift up all elements of a stack by 1. The first element becomes the last one | ra and rb

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}


// Shifts down all elements of a stack by 1. The last element becomes the first one | rra and rrb

static void	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	head = *stack;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **stack_a)
{
	reverseRotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	reverseRotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
}

