#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

// Stack

typedef struct	s_list
{
        int value;
		int	index;
        struct s_list *next;
}				t_list;

// Util functions

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	ft_lstdel(t_list *head, int value);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

void	ft_error(char *msg);
void	ft_check_args(char **argv);
int		is_sorted(t_list **stack);

// Algorithm utils

void	index_stack(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);

// Instruction functions

int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int	ss(t_list **stack_a, t_list **stack_b);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_b, t_list **stack_a);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);

#endif

