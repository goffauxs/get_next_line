#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	int	i = 0;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("line [%d]: %s", line);
		i++;
		free(line);
	}
	close(fd);
}