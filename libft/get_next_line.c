/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:41:23 by shovsepy          #+#    #+#             */
/*   Updated: 2021/07/12 21:41:28 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_new_line(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strchr_stack;
	int			i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
	{
		if (!strchr_stack[i++])
			return (0);
	}
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = *stack;
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static void	add_heap_to_static(char **s, char *buf)
{
	char		*tmp;

	tmp = *s;
	if (!tmp)
		*s = ft_strdup(buf);
	else
	{
		*s = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
}

static	int	ft_exit(char **line)
{
	*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		heap[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= MAX_FD || (read(fd, s[fd], 0) < 0))
		return (-1);
	ret = read(fd, heap, BUFF_SIZE);
	while (ret > 0)
	{
		heap[ret] = '\0';
		add_heap_to_static(&s[fd], heap);
		if (verify_new_line(&s[fd], line))
			return (1);
		ret = read(fd, heap, BUFF_SIZE);
	}
	if (!s[fd] || s[fd][0] == '\0')
		return (ft_exit(line));
	if (s[fd])
		if (verify_new_line(&(s[fd]), line))
			return (1);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (1);
}