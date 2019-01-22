/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:20 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/08 18:29:11 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	j = 0;
	n = ft_strlen(dst) + 1;
	i = n - 1;
	if (size < n)
		return (ft_strlen(src) + size);
	while (j < (size - n) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (n + ft_strlen(src) - 1);
}
