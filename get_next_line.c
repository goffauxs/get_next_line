/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:05:16 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/04 12:59:49 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char 		*buf;
	static char	*save;
	int 		ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while ()
		end++;
	
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	return (-1);
}

int main()
{
	int fd;
	char *line;
	int ret;

	line = NULL;
	fd = open("maxlenul.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
}