#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("sample.txt", O_RDONLY);
	char *s;

	// s = get_next_line(fd);
	// if (!s)
	// 	return (0);
	// printf("%s", s);

	while (1)
	{		s = get_next_line(fd);
		if (!s)
			return (0);
		printf("%s", s);
	}
	return (0);
}
