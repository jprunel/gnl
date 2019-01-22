/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:44 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/15 21:38:12 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		ft_putchar_fd((char)s[i++], fd);
	ft_putchar_fd('\n', fd);
}
