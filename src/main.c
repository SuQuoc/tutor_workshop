
#include "../workshop.h"


//nm -help


//ulimit can limit heap, etc

int main (void)
{
	char *str = NULL;
	char *ft_str_copy = NULL;
	char *str_copy = NULL;

	ft_printf("CHOCOBOS !!!\n");
	printf("CHOCOBOS !!!\n");

	str = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!str)
		return (1);

	ft_str_copy = ft_strdup(str);
	if (!ft_str_copy)
		return (1);

	str_copy = strdup(str);
	if (!str_copy)
	{
		free(str);
		free(ft_str_copy);
		return (1);
	}
	return (0);
}