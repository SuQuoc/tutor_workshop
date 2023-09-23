
#include "../workshop.h"

//nm -help
//ulimit can limit v_memory, fds, etc

int main (int argc , char **argv)
{

	if (argc != 2)
	{
		printf("ulimit memory: 1\n");
		printf("ulimit fd: 2\n");
		printf("funchecker: 3\n");
		return (0);
	}
	if (argv[1][0] == '1')
	{
		mem_limit();
	}
	else if (argv[1][0] == '2')
	{
		filedescriptor();
	}
	else if (argv[1][0] == '3')
	{
		printf("funchecker?\n");
		char **arr = alloc_arr(10, 10);
		free(arr);
	}
	return (0);
}

//printf("ulimit -a: shows u the limitations of your terminal\n");
//printf("ulimit -v: limits the memory in kbytes (address space)\n");

void mem_limit(void)
{
	printf("Buffer size: %d kbytes\n", BUF_SIZE / 1024);//debugging
	
	char *str = NULL;
	char *copy1 = NULL;
	char *copy2 = NULL;

	str = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!str)
		return ;
	fill_str(str, "1 CHOCOBO !!!\n");
	printf("str: %s\n", str);
	
	
	copy1 = (char *)malloc(sizeof(char) * BUF_SIZE);
	fill_str(copy1, "2 CHOCOBOS !!!\n");
	printf("copy1: %s\n", copy1);
	

	copy2 = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!copy2)
		return ;
	fill_str(copy2, "3 CHOCOBOS !!!\n");
	printf("copy2: %s\n", copy2);

	return ;
}


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



void filedescriptor (void)
{
	int fd1 = open("README.md", O_RDONLY);
	int fd2 = open("README.md", O_RDONLY);
	int fd3 = open("README.md", O_RDONLY);
	int fd4 = open("README.md", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
	{
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		ft_putstr_fd("failed to open file!\n", 2);
		return ;
	}

	ft_putstr_fd("Successfully opened all files!\n", 2);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return ;
}

char **alloc_arr(int rows, int len)
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
}



void free_2d_arr(char **arr, int rows)
{
	int i = 0;

	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}