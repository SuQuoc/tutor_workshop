
#ifndef WORKSHOP_H
# define WORKSHOP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUF_SIZE 200 * 1024

void mem_limit(void);
void fill_str(char *dest, char *src);
void filedescriptor (void);
char **alloc_arr(int rows, int len);
void free_2d_arr(char **arr);
void fun_and_malloc(void);




# endif