/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:57:36 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 16:33:01 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;

	if (!(r = ft_strnew(len)))
		return (NULL);
	r[len] = '\0';
	while (len--)
		r[len] = s[start + len];
	return (r);
}
