#include "../includes/push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

// Check for the argv

static int ft_contains(int num, char **argv, int i)
{
	// check will be done after the i-th element
	i++; 
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(char **argv)
{
	int	i;
	int	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error("Error");

		if (ft_contains(tmp, argv, i))
			ft_error("Error");
		
		// TODO: handle MAX_INT and MIN_INT
		//if (tmp < -2147483648 || tmp > 2147483647)
		//	ft_error("Error");
		i++;
	}
}
