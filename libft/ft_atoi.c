/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:30:29 by jprunel           #+#    #+#             */
/*   Updated: 2016/12/02 11:36:59 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (((int)str[i] > 8 && (int)str[i] < 14) || str[i] == ' ')
			i++;
		if (ft_isdigit((int)str[i]) || str[i++] == '+')
		{
			while (str[i] && ft_isdigit((int)str[i]))
				res = (res * 10) + ((int)str[i++] - 48);
			return (res);
		}
		else if (str[i - 1] == '-')
		{
			while (str[i] && ft_isdigit((int)str[i]))
				res = (res * 10) + ((int)str[i++] - 48);
			return (-res);
		}
		else
			return (0);
	}
	return (0);
}
