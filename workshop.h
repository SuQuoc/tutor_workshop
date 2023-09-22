
#ifndef WORKSHOP_H
# define WORKSHOP_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUF_SIZE 190000 * 1000

int mem_limit(void);
void fill_str(char *str, char c, int len);
int filedescriptor (void);
char **alloc_arr(int rows, int len);


# endif