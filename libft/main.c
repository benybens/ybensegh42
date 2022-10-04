#include <stdio.h>
#include "./includes/libft.h"

int	main(int argc , char *argv[])
{
	(void) argc;
	(void) argv;

	char	str[] = "Hello World"; 

	printf("\n********\n**** Starting test of libft.a : \n********\n");
	printf("\n----------\n---- ft_strlen :\n-----------\n");
	printf("This string : %s , count %d chars\n",str,ft_strlen(str));
	printf("\n----------\n---- ft_isalpha :\n-----------\n");
	printf("O is alpha ? %d \n",ft_isalpha('o'));
	printf("j is alpha ? %d \n",ft_isalpha('j'));
	printf("? is alpha ? %d \n",ft_isalpha('?'));
}
