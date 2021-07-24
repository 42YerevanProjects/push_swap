/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:41:08 by shovsepy          #+#    #+#             */
/*   Updated: 2021/02/02 20:04:56 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_val;
	unsigned char		*src_val;
	size_t				i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dest_val = (unsigned char *)dest;
	src_val = (unsigned char *)src;
	while (i < n)
	{
		dest_val[i] = src_val[i];
		i++;
	}
	return (dest);
}
