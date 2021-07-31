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

static void	sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	index_stack(stack_a);
	if (argc <= 6)
		simple_sort(stack_a, stack_b);
	else if (argc < 50)
		sort(stack_a, stack_b);
	else if (argc == 101)
		cent_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

// The main function

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initStack(stack_a, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b, argc);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
