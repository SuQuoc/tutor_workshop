
#include "../workshop.h"

void fill_str(char *dest, char *src)
{
	int i = 0;

	if (src == NULL)
		return ;
	while (src[i])
	{
		dest[i] = src[i];
		i++;	
	}
	dest[i] = '\0';	
}

void 	free_2d_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* char **alloc_arr(int rows, int len)
{
	char **arr;
	int i;
	
	arr = malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (NULL);

	i = 0;
	while (i < rows)
	{
		arr[i] = malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (NULL);
		arr[i][0] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
} */