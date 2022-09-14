# get_next_line
Simple function to parse files line by line

## About
The function works using a static buffer that gets modified everytime the function is called.

The size of the buffer can be modified in the header file

## Example usage
```C
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	int i = 0;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("line [%d]: %s", i, line);
		i++;
		free(line);
	}
	close(fd);
}
```
