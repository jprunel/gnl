/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:18:58 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 16:31:56 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*r;

	i = 0;
	if (!(r = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s && s[i++])
		r[i - 1] = f(s[i - 1]);
	return (r);
}
