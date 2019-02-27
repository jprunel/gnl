/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:08:19 by jprunel           #+#    #+#             */
/*   Updated: 2019/02/25 19:21:32 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_lb(char *s)
{
	int i;

	i = 0;
	while (s && s[i] != '\n')
		i++;
	if (s && s[i] && s[i] == '\n')
		return (i + 1);
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static char *storage;
	char 		*tmp;
	int			status;

	if (!storage && !(storage = ft_strnew(BUFF_SIZE))) ////initialize str if !str
		return (-1);
	MALLCHECK((tmp = ft_strnew(ft_strlen(storage) + BUFF_SIZE))); ////initialize tmp
	if(check_lb(storage))
	{
		*line = ft_strncpy(tmp, storage, check_lb(storage - 1));
		storage = ft_strcpy (storage, storage + check_lb(storage));
		return (1);
	}
	if ((status = read(fd, tmp, BUFF_SIZE)) < 0)
		return (-1);
	if (status == 0)
	{
		if (storage)
		{
			*line = ft_strcpy(tmp, storage);
			ft_strdel(&storage);
			return (1);
		}
		else
			return (0);
	}
	storage = ft_strjoin(storage, tmp); //potentially not freeing
	get_next_line(fd, line);
	return (0);
}
