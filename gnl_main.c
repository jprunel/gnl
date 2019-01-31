/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:57:45 by jprunel           #+#    #+#             */
/*   Updated: 2019/01/31 17:06:24 by jprunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char 	**line;
	int		ret;
	int 	count;

	count = 0;
	line = ft_memalloc(1);
	if (!(str = ft_strnew(15000)))
		return (0);
	line = &str;
	if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
		return (0);
ft_putendl(""); ft_putendl("======================================================");
ft_putstr("                             START with BUFF_SIZE = "); ft_putnbr(BUFF_SIZE); ft_putendl("");

	while ((ret = get_next_line(fd, line)) && ++count)
		{
			ft_putendl("----------------");
			ft_putstr("| CALL NB "); ft_putnbr(count); ft_putendl("");
			ft_putstr("| RESULT >>>>>> "); ft_putendl(*line);
			ft_putstr("| GNL RETURN >> "); ft_putnbr(ret); ft_putendl("");
			ft_putendl("-----------------"); ft_putendl(""); ft_putendl("");
		}
	ft_putendl(""); ft_putendl("=============================================");
	ft_putstr("FINAL RESULT >>>>> "); ft_putendl(*line); ft_putendl("");

	return (1);
}
