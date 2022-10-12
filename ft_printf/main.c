
#include "./includes/ft_printf.h"

int main()
{
	int nbr;

	ft_printf("-----Starting test of libftprintf.a------\n");
	ft_printf("1/ This is a simple string\n");
	nbr = 15;
	ft_printf("2/ This is a string with one param, int -> %d\n",nbr);
	nbr = 0;
	ft_printf("2/ This is a string with one param, int -> %d\n",nbr);
	nbr = -98;
	ft_printf("2/ This is a string with one param, int -> %d\n",nbr);
	nbr = 124546;
	ft_printf("2/ This is a string with one param, int -> %d\n",nbr);
}
