#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

// Stack

typedef struct	s_list
{
        int value;
        struct s_list *next;
}				t_list;

// Utils functions

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	ft_lstdel(t_list *head, int value);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

void	ft_error(char *msg);

// Instruction functions

void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_to, t_list **stack_from);

#endif

