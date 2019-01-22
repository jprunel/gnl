/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:23:36 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/08 16:25:49 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (dst < src)
		while (i++ < len)
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
