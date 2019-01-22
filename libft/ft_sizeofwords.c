/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofwords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:57:03 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 16:27:20 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sizeofwords(char *s, char c)
{
	int		*sizes;
	int		i;
	int		cursor;
	int		wordsize;

	i = 0;
	cursor = 0;
	wordsize = 0;
	if (!(sizes = (int *)malloc(sizeof(int) * (ft_nbwords(s, c) + 1))))
		return (NULL);
	while (s && s[i])
		if (s && s[i] && s[i] == c)
			i++;
		else if (s && s[i] && s[i] != c && ++cursor)
		{
			while (s && s[i] && s[i] != c && ++i)
				wordsize++;
			sizes[cursor - 1] = wordsize;
			wordsize = 0;
		}
	sizes[cursor] = '\0';
	return (sizes);
}
