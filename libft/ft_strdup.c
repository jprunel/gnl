/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:30:59 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/08 18:11:04 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(char *) * size)))
		return (NULL);
	cpy[size] = '\0';
	while (size-- > 0)
		cpy[size] = s1[size];
	return (cpy);
}
