
#include "../workshop.h"


//nm -help


//ulimit can limit heap, etc

int main (void)
{
	char *str;
	char *ft_str_copy = NULL;
	char *str_copy = NULL;

	ft_printf("CHOCOBOS !!!\n");
	printf("CHOCOBOS !!!\n");

	str = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!str)
		return (1);
	
	int i = 0;
	while (i < BUF_SIZE)
	{
		if (i == 10)
		{
			str[i] = '\0';	
			break;
		}
		str[i] = 'a';
		i++;	
	}
	printf("str: %s\n", str);



	ft_str_copy = ft_strdup(str);
	if (!ft_str_copy)
		return (1);
	printf("ft_str_copy: %s\n", ft_str_copy);

	str_copy = strdup(str);
	if (!str_copy)
	{
		free(str);
		free(ft_str_copy);
		return (1);
	}
	printf("str_copy: %s\n", str_copy);


	free(str);
	free(ft_str_copy);
	free(str_copy);
	return (0);
}