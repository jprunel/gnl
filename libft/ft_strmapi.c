/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:27:47 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/10 11:33:15 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*r;

	i = 0;
	if (!(r = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s && s[i++])
		r[i - 1] = f(i - 1, s[i - 1]);
	return (r);
}
