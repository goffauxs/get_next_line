/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:05:16 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/06 16:06:00 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_count_chars(char **line, char *buf, int *buf_count, int *line_count)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	*buf_count = i;
	i = 0;	
	while (*line && (*line)[i] && (*line)[i] != '\n')
		i++;
	*line_count = i;
}

int	ft_add_to_line(char **line, char *buf, int buf_count, int line_count)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(sizeof(char) * (buf_count + line_count + 1));
	if (!tmp)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		tmp[i++] = (*line)[j++];
	j = 0;
	while (buf[j] && buf[j] != '\n')
		tmp[i++] = buf[j++];
	tmp[i] = buf[j];
	i = 0;
	while (buf[j])
		buf[i++] = buf[++j];
	free(*line);
	*line = tmp;
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	int			ret;
	int			buf_count;
	int			line_count;
	
	*line = NULL;
	buf_count = 0;
	line_count = 0;
	ret = ft_add_to_line(line, buf, buf_count, line_count);
	while (ret != -1 && (*line)[ret] != '\n')
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 1)
			return (ret);
		buf[ret] = '\0';
		ft_count_chars(line, buf, &buf_count, &line_count);
		ret = ft_add_to_line(line, buf, buf_count, line_count);
	}
	if (ret == -1)
		return (-1);
	(*line)[ret] = '\0';
	return (1);
}

int main()
{
	int fd;
	char *line;
	int ret;
	int i;

	i = 0;
	line = NULL;
	fd = open("maxlenul.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("line 1: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("line 2: %s\n", line);
	ret = get_next_line(fd, &line);
	printf("line 3: %s\n", line);
}