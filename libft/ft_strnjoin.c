/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:26:22 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 21:39:18 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char	*r;

	if (!(r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n))))
		return (NULL);
	ft_strcpy(r, s1);
	ft_strcpy(r + ft_strlen(s1), s2);
	return (r);
}
