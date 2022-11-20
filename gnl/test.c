#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int	fd1;
	int	fd2;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
		return (1);
	printf("fd1\t: %d\n", fd1);
	fd2 = dup2(fd1, 42);
	printf("fd1\t: %d\n", fd1);
	printf("fd2\t: %d\n", fd2);
	close(fd1);
	close(fd2);

	return (0);
}
