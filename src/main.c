#include "../includes/push_swap.h"

static void	initStack(t_list **stack, char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
}

static void printStacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (head_a || head_b)
	{
		 if (head_a != NULL)
		{
			ft_putnbr_fd(head_a->value, 1);
			ft_putstr_fd("    ", 1);
			head_a = head_a->next;
		}
		else
			ft_putstr_fd("     ", 1);
		if (head_b != NULL)
		{
			ft_putnbr_fd(head_b->value, 1);
			ft_putendl_fd("", 1);
			head_b = head_b->next;
		}
		else
			ft_putendl_fd(" ", 1);
	}

	ft_putendl_fd("-    -", 1);
	ft_putendl_fd("a    b", 1);
}

// The main function

int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));

	initStack(stack_a, argv);
//	initStack(stack_b, argv);

	printStacks(stack_a, stack_b);
	ft_putendl_fd("-------------------\n", 1);
//	pb(stack_a, stack_b);
//	pb(stack_a, stack_b);
//	pa(stack_a, stack_b);
//	ra(stack_a);
//	ra(stack_a);
//	sa(stack_a);
//	sb(stack_b);
//	rrr(stack_a, stack_b);
//	rrb(stack_b);
//	rra(stack_a);

	ft_putendl_fd("", 1);
	ft_putendl_fd("-------------------\n", 1);
	printStacks(stack_a, stack_b);

	free(stack_a);
	free(stack_b);
	return (0);
}
