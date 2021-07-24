/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:40:03 by shovsepy          #+#    #+#             */
/*   Updated: 2021/02/02 18:38:16 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*str1_val;
	const unsigned char	*str2_val;
	size_t				i;

	str1_val = (const unsigned char *)str1;
	str2_val = (const unsigned char *)str2;
	i = 0;
	while (i < len)
	{
		if (str1_val[i] != str2_val[i])
		{
			return (str1_val[i] - str2_val[i]);
		}
		i++;
	}
	return (0);
}
