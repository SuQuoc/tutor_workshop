
#include "../workshop.h"

//nm -help
//ulimit can limit v_memory, fds, etc

int main (int argc , char **argv)
{

	if (argc != 2)
	{
		printf("ulimit v_mem: 1\n");
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
		char **arr = alloc_arr(5, 10);
		free(arr);
	}
	return (0);
}

void mem_limit(void)
{
	char *str;
	char *copy1 = NULL;
	char *copy2 = NULL;

	printf("ulimit -a: shows u the limitations of your terminal\n");
	
	printf("ulimit -v: limits the memory in kbytes\n");
	
	printf("the address space shows u the bytes available\n");


	ft_printf("CHOCOBOS !!!\n");

	printf("buffer Size: %d\n", BUF_SIZE);
	str = (char *)malloc(sizeof(char) * BUF_SIZE);
	//if (!str)
	//	return (1);
	fill_str(str, 'a', 10);
	printf("str: %s\n", str);

	
	//copy2 = ft_strdup(str);
	//if (!copy2)
	//	return (1);
	//printf("copy2: %s\n", copy2);

	
	copy1 = strdup(str);
	if (!copy1)
	{
		free(str);
		free(copy2);
		return ;
	}
	printf("copy: %s\n", copy1);


	free(str);
	free(copy1);
	free(copy2);
	printf("CHOCOBOS !!!\n");
	return ;
}


void fill_str(char *str, char c, int len)
{
	int i = 0;

	while (i < len)
	{
		str[i] = c;
		i++;	
	}
	str[i] = '\0';	
}



void filedescriptor (void)
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file1.txt", O_RDONLY);
	int fd3 = open("file1.txt", O_RDONLY);
	int fd4 = open("file1.txt", O_RDONLY);

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