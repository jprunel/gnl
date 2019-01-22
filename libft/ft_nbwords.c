/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:52:46 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 14:50:40 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbwords(char const *s, char c)
{
	int	i;
	int	nbw;

	i = 0;
	nbw = 0;
	while (s && s[i])
	{
		if (s && s[i] && s[i] != c && ++nbw)
			while (s && s[i] && s[i] != c)
				i++;
		while (s && s[i] && s[i] == c)
			i++;
	}
	return (nbw);
}
