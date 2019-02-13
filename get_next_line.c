/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:19:58 by jprunel           #+#    #+#             */
/*   Updated: 2019/02/13 18:13:56 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_with_eol(char *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] && s[i] == '\n')
		return (i + 1);
	return (0);

	//return ((s && s[i] && s[i] == '\n') ? (i + 1) : 0);
}

int	get_next_line(const int fd, char **line)
{
	static char *str;
	char		*tmp;
 	int			status;

	//
			ft_putendl(""); ft_putendl("\n**** GNL START ****");
	//
	if (!str && !(str = ft_strnew(BUFF_SIZE))) ////initialize str if !str
		return (-1);
	MALLCHECK((tmp = ft_strnew(BUFF_SIZE))); ////initialize tmp
	//
			ft_putstr("str start = "); ft_putendl(str);
	//
	if (str && (ft_with_eol(str))) ///// SI str contient un \n
	{
		*line = ft_strncpy(tmp, str, (ft_with_eol(str) - 1)); ////copie str jusqu'au \n dans tmp et l'assigne a line
		str = ft_strcpy(str, str + ft_with_eol(str)); //recommence str apres le \n
		//
			ft_putstr("str end ="); ft_putendl(str);
		//
		return (1);
	}
	if ((status = read(fd, tmp, BUFF_SIZE)) < 0)
		return (-1);
	//
		ft_putendl(""); ft_putstr("status = "); ft_putnbr(status); ft_putendl("");
	//
	str = ft_strjoin(str, tmp);
	if (str && str[0] && !ft_with_eol(str) && (status < BUFF_SIZE))
	{
			*line = ft_strcpy(tmp, str);
			ft_bzero(str, ft_strlen(str));
			return (1);
	}
	ft_strdel(&tmp);
	//
		ft_putstr("ft_with_eol() res = "); ft_putnbr(ft_with_eol(str)); ft_putendl("");
	//
	if ((status < BUFF_SIZE) && !str[0])
		return (0);
	if (!get_next_line(fd, line))
		return (0);
	return (1);
}
