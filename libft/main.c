#include "libft.h"
#include <stdio.h>

int main()
{
	char arr[10];

	ft_memset(arr, 0, 10);
	for (int i = 0; i < 10 ; i++)
		printf("%d\n", arr[i]);
}
