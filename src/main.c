
#include "../workshop.h"

int main (int argc , char **argv)
{

	if (argc != 2)
	{
		printf("ulimit fd: 1\n");
		printf("ulimit memory: 2\n");
		printf("funchecker: 3\n");
		return (0);
	}
	if (argv[1][0] == '1')
	{
		filedescriptor();
	}
	else if (argv[1][0] == '2')
	{
		mem_limit();
	}
	else if (argv[1][0] == '3')
	{
		fun_and_malloc();
	}
	return (0);
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


	free(str);
	free(copy1);
	free(copy2);
	return ;
}





void fun_and_malloc(void)
{
	printf("funcheck\n");
	char **arr = ft_split("Hello and weclome to the workshop.", ' ');
	//do smth with arr
	free_2d_arr(arr);
}
