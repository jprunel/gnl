/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:19:58 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/22 17:00:42 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_with_eol(char *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return ((s && s[i] && s[i] == '\n') ? (i + 1) : 0);
}

int	get_next_line(const int fd, char **line)
{
	static char *str;
	char		*tmp;
	static int	status;

	if (!str && !(str = ft_strnew(BUFF_SIZE)))
		return (-1);
ft_putendl("\n\n ********* GNL CALL ***********");
ft_putstr("str = "); ft_putendl(str);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (str && (ft_with_eol(str)))
	{
		tmp = ft_strcpy(tmp, str);
		//tmp = ft_strncpy(tmp, str, (ft_with_eol(str)));
		str = str + ft_with_eol(str);
		tmp[ft_with_eol(tmp) - 1] = '\0';
		*line = tmp;
		ft_putstr("str = "); ft_putendl(str);
		ft_putstr("tmp = "); ft_putendl(tmp);
		return (1);
	}
	if (status && status < BUFF_SIZE && !str[0])
	{
		*line = str;
		return (0);
	}
	if (((status = read(fd, tmp, BUFF_SIZE)) < 0))
		return (-1);
	if (status == 0)
		return (0);
	str = ft_strjoin(str, tmp);
	free(tmp);
	if (get_next_line(fd, line))
		return (1);
	return (2);
}
