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

	if (is_sorted(stack_a))
	{
		free(stack_a);
		free(stack_b);
		ft_error("Stack is already sorted!");
	}

	index_stack(stack_a);

	if (argc < 6)
		simple_sort(stack_a, stack_b);

	if (is_sorted(stack_a))
		ft_putendl_fd("sorted yay", 1);
	else 
		ft_putendl_fd("fail", 1);

	free(stack_a);
	free(stack_b);
	return (0);
}
