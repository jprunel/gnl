/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:08:19 by jprunel           #+#    #+#             */
/*   Updated: 2019/02/27 17:41:25 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_lb(char *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return ((s && s[i] && s[i] == '\n') ? (i + 1) : 0);
}

int	nothing_more(char **tmp, char **storage, char ***line)
{
	if (*storage && *storage[0])
	{
		**line = ft_strcpy(*tmp, *storage);
		ft_strdel(storage);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*storage;
	char		*tmp;
	int			status;

	if (!storage && !(storage = ft_strnew(BUFF_SIZE)))
		return (-1);
	MALLCHECK((tmp = ft_strnew(ft_strlen(storage) + BUFF_SIZE)));
	if (storage && storage[0] && check_lb(storage))
	{
		*line = ft_strncpy(tmp, storage, check_lb(storage) - 1);
		storage = ft_strcpy(storage, storage + check_lb(storage));
		return (1);
	}
	if ((status = read(fd, tmp, BUFF_SIZE)) < 0)
		return (-1);
	if (status == 0)
		return (nothing_more(&tmp, &storage, &line));
	storage = ft_strjoin(storage, tmp);
	ft_strdel(&tmp);
	return ((get_next_line(fd, line)) ? 1 : 0);
}
