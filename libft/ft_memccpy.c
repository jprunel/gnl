/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:40:05 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/08 15:27:47 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy
	(void *restrict dst, const void *restrict src, int c, size_t n)
{
	size_t count;

	count = 0;
	while (count++ < n)
	{
		((char *)dst)[count - 1] = ((char *)src)[count - 1];
		if (((unsigned char *)src)[count - 1] == (unsigned char)c)
			return (dst + count);
	}
	return (NULL);
}
