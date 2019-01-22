/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:28:47 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/08 16:44:22 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && ((unsigned char *)s)[count] != (unsigned char)c)
		count++;
	if (count != n)
		return ((void *)s + count);
	return (NULL);
}
