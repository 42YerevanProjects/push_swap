#include "../includes/push_swap.h"

int	do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
		return (sa(stack_a));
	if (!(ft_strcmp(line, "sb")))
		return (sb(stack_b));
	if (!(ft_strcmp(line, "ss")))
		return (ss(stack_a, stack_b));
	if (!(ft_strcmp(line, "pa")))
		return (pa(stack_a, stack_b));
	if (!(ft_strcmp(line, "pb")))
		return (pb(stack_a, stack_b));
	if (!(ft_strcmp(line, "ra")))
		return (ra(stack_a));
	if (!(ft_strcmp(line, "rb")))
		return (rb(stack_b));
	if (!(ft_strcmp(line, "rr")))
		return (rr(stack_a, stack_b));
	if (!(ft_strcmp(line, "rra")))
		return (rra(stack_a));
	if (!(ft_strcmp(line, "rrb")))
		return (rrb(stack_b));
	if (!(ft_strcmp(line, "rrr")))
		return (rrr(stack_a, stack_b));
	return (1);
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

static void	initStack(t_list **stack, char **argv)
{
	t_list	*new;
	int		i;

	i = 0;
	while (argv[1][i])
	{
		new = ft_lstnew(ft_atoi(argv[1][i]));
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initStack(stack_a, argv);
	while (get_next_line(0, &line))
	{
		if (do_commands(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}
