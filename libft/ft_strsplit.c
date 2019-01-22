/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:04:12 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 16:39:22 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_alloctab(int *sizes)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_inttablen(sizes) + 1))))
		return (NULL);
	ft_bzero(tab, ft_inttablen(sizes) + 1);
	while (i < (ft_inttablen(sizes) + 1) && sizes && sizes[i++])
		if (!(tab[i - 1] = ft_strnew(sizes[i - 1])))
			return (NULL);
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**r;
	int		*sizes;

	i = 0;
	j = 0;
	if (!(sizes = ft_sizeofwords((char *)s, c)))
		return (NULL);
	if (!(r = ft_alloctab(sizes)))
		return (NULL);
	while (s && s[i])
		if (s[i] == c)
			i++;
		else
		{
			if (!(ft_strncpy(r[j], s + i, sizes[j])))
				return (NULL);
			i += sizes[j];
			j++;
		}
	return (r);
}
