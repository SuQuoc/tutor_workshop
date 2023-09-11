#include <stdlib.h>

int main(void)
{
	char *str;

	str = malloc(sizeof(char) * -1);
	if (!str)
	{
		printf("error\n");
		exit (1);
	}
}
