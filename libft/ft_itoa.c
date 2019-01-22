/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:27:56 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 16:41:27 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocation(int n, int i)
{
	char	*d;

	d = NULL;
	if (n < 0)
	{
		if (!(d = ft_strnew(i + 2)))
			return (NULL);
	}
	else if (!(d = ft_strnew(i + 1)))
		return (NULL);
	return (d);
}

char		*ft_itoa(int n)
{
	int		i;
	int		w;
	char	*s;

	w = n;
	i = ft_intsize(n);
	if (!(s = allocation(n, i)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (w < 0)
	{
		s[0] = '-';
		w *= -1;
		i++;
	}
	s[++i] = '\0';
	while (w > 9)
	{
		s[--i] = (char)(w % 10 + 48);
		w /= 10;
	}
	s[--i] = (char)(w + 48);
	return (s);
}
