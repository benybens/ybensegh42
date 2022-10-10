#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "./includes/libft.h"

int	main(int argc , char *argv[])
{
	(void) argc;
	(void) argv;

	char	str[] = "Hello World"; 
	char	src[] = "Source Acquisition"; 
	char	dst[] = "Destination Target"; 
	char	src2[] = "Source Acquisition"; 
	char	dst2[] = "Destination Target";
	char 	mem[] = "54542157215245847";
	char	catdst[100] = "This is now";
	char	catsrc[100] = " a concatened string, and this part should not appear";

	printf("\n********\n**** Starting test of libft.a : \n********\n");

	printf("\n----------\n---- ft_strlen :\n-----------\n");
	printf("This string : %s , count %d chars\n",str,(int)ft_strlen(str));
	
	printf("\n----------\n---- ft_isalpha :\n-----------\n");
	printf("O is alpha ? %d \n",ft_isalpha('o'));
	printf("j is alpha ? %d \n",ft_isalpha('j'));
	printf("? is alpha ? %d \n",ft_isalpha('?'));

	printf("\n----------\n---- ft_isdigit :\n-----------\n");
	printf("8 is digit ? %d \n",ft_isdigit('8'));
	printf("j is digit ? %d \n",ft_isdigit('j'));
	printf("? is digit ? %d \n",ft_isdigit('?'));

	printf("\n----------\n---- ft_isalnum :\n-----------\n");
	printf("8 is alnum ? %d \n",ft_isalnum('8'));
	printf("j is alnum ? %d \n",ft_isalnum('j'));
	printf("? is alnum ? %d \n",ft_isalnum('?'));
	printf("( is alnum ? %d \n",ft_isalnum('('));
	printf("3 is alnum ? %d \n",ft_isalnum('3'));
	printf("b is alnum ? %d \n",ft_isalnum('b'));
	
	printf("\n----------\n---- ft_isascii :\n-----------\n");
	printf("8 is ascii ? %d \n",ft_isascii('8'));
	printf("j is ascii ? %d \n",ft_isascii('j'));
	printf("? is ascii ? %d \n",ft_isascii('?'));
	printf("95 is ascii ? %d \n",ft_isascii(95));
	printf("128 is ascii ? %d \n",ft_isascii(128));
	printf("-1 is ascii ? %d \n",ft_isascii(-1));
	
	printf("\n----------\n---- ft_isprint :\n-----------\n");
	printf("15 is print ? %d \n",ft_isprint(15));
	printf("j is print ? %d \n",ft_isprint('j'));
	printf("? is print ? %d \n",ft_isprint('?'));
	printf("95 is print ? %d \n",ft_isprint(95));
	printf("128 is print ? %d \n",ft_isprint(128));
	printf("-1 is print ? %d \n",ft_isprint(-1));
	
	printf("\n----------\n---- ft_toupper :\n-----------\n");
	printf("c upper ? %c \n",ft_toupper('c'));
	printf("j upper ? %c \n",ft_toupper('j'));
	printf("? upper ? %c \n",ft_toupper('?'));
	printf("9 upper ? %c \n",ft_toupper('9'));
	printf("L upper ? %c \n",ft_toupper('L'));
	printf("m upper ? %c \n",ft_toupper('m'));

	printf("\n----------\n---- ft_tolower :\n-----------\n");
	printf("c lower ? %c \n",ft_tolower('c'));
	printf("J lower ? %c \n",ft_tolower('J'));

	printf("? lower ? %c \n",ft_tolower('?'));
	printf("9 lower ? %c \n",ft_tolower('9'));
	printf("L lower ? %c \n",ft_tolower('L'));
	printf("m lower ? %c \n",ft_tolower('m'));

	printf("\n----------\n---- ft_strchr :\n-----------\n");
	printf("c in abcdef ? %s \n",ft_strchr("abcdef",'c'));
	printf("b in abcdef ? %s \n",ft_strchr("abcdef",'b'));
	printf("e in abcdef ? %s \n",ft_strchr("abcdef",'e'));
	printf("l in abcedf ? %s \n",ft_strchr("abcedf",'l'));
	printf("\\0 in abcedf ? %s \n",ft_strchr("abcedf",'\0'));

	printf("\n----------\n---- ft_strrchr :\n-----------\n");
	printf("c in abcdeffedcba ? %s \n",ft_strrchr("abcdeffedcba",'c'));
	printf("b in abcdeffedcba ? %s \n",ft_strrchr("abcdeffedcba",'b'));
	printf("e in abcdeffedcba ? %s \n",ft_strrchr("abcdeffedcba",'e'));
	printf("l in abcedffedcba ? %s \n",ft_strrchr("abcedffedcba",'l'));
	printf("\\0 in abcedffedcba ? %s \n",ft_strrchr("abcedffedcba",'\0'));

	printf("\n----------\n---- ft_strncmp :\n-----------\n");
	printf("ft 'Hello' 'Hello' 5 ? %d \n",ft_strncmp("Hello","Hello",5));
	printf("libc 'Hello' 'Hello' 5 ? %d \n",strncmp("Hello","Hello",5));
	printf("ft 'Hello' 'Hemlo' 5 ? %d \n",ft_strncmp("Hello","Hemlo",5));
	printf("libc 'Hello' 'Hemlo' 5 ? %d \n",strncmp("Hello","Hemlo",5));
	printf("ft 'Hello' 'Hemlo' 2 ? %d \n",ft_strncmp("Hello","Hemlo",2));
	printf("libc 'Hello' 'Hemlo' 2 ? %d \n",strncmp("Hello","Hemlo",2));
	printf("ft 'ft HelloWorld' 'Hello' 15 ? %d \n",ft_strncmp("HelloWorld","Hello",15));
	printf("libc 'HelloWorld' 'Hello' 15 ? %d \n",strncmp("HelloWorld","Hello",15));
	printf("ft 'Hello' 'HelloWorld' 15 ? %d \n",ft_strncmp("Hello","HelloWorld",15));
	printf("libc 'Hello' 'HelloWorld' 15 ? %d \n",strncmp("Hello","HelloWorld",15));
	printf("ft '' 'g' 15 ? %d \n",ft_strncmp("","",15));
	printf("libc '' 'g' 15 ? %d \n",strncmp("","",15));
	printf("ft 'JOBI' 'JOBO' 0 ? %d \n",ft_strncmp("JOBI","JOBO",0));
	printf("libc 'JOBI' 'JOBO' 0 ? %d \n",strncmp("JOBI","JOBO",0));

	printf("\n----------\n---- ft_strlcpy :\n-----------\n");
	printf("This is dest : %s\n",dst);
	printf("6 charcters copied to dst ? src is %d bytes \n",(int)ft_strlcpy(dst,src,6));
	printf("This is dest : %s\n",dst);
	printf("This is dest2 : %s\n",dst2);
	printf("10 characters copied to dst ? src is %d bytes\n",(int)ft_strlcpy(dst2,src2,10));
	printf("This is dest2 : %s\n",dst2);
	
	printf("\n----------\n---- ft_strlcat :\n-----------\n");
	printf("This is dest : %s\n",catdst);
	printf("20 charcters copied to dst ? src is %d bytes \n",(int)ft_strlcat(catdst,catsrc,20));
	printf("This is dest : %s\n",catdst);
	
	printf("\n----------\n---- ft_strnstr :\n-----------\n");
	printf("Looking 'Gear' in Metal Gear Solid V , 50 first chars: %s\n",ft_strnstr("Metal Gear Solid V","Gear",50));
	printf("Looking 'Gear' in Metal Gear Solid V , 5 first chars : %s\n",ft_strnstr("Metal Gear Solid V","Gear",5));
	printf("Looking 'tal' in Metal Gear Solid V, 5 first chars : %s\n",ft_strnstr("Metal Gear Solid V","tal",5));
	printf("Looking 'Bird' in Metal Gear Solid V, 50 first chars : %s\n",ft_strnstr("Metal Gear Solid V","Bird",50));
	printf("Looking '' in Metal Gear Solid V, 50 first chars : %s\n",ft_strnstr("Metal Gear Solid V","",50));

	printf("\n----------\n---- ft_atoi :\n-----------\n");
	printf("265 : %d\n",ft_atoi("265"));
	printf("-54265 : %d\n",ft_atoi("-54265"));
	printf("0 : %d\n",ft_atoi("0"));
	printf("INT_MAX : %d\n",ft_atoi("2147483647"));
	printf("INT_MIN : %d\n",ft_atoi("-2147483648"));
	
	printf("\n----------\n---- ft_memset :\n-----------\n");
	printf("mem :  %s\n",mem);
	printf("memset 15 chars : %s\n",(char *)ft_memset(mem,'x',15));
	
	printf("\n----------\n---- ft_bzero :\n-----------\n");
	printf("mem :  %s\n",mem);
	printf("bzero 15 chars ...\n");
	ft_bzero(mem,15);
	printf("membzero :  %s\n",mem);
	
	printf("\n----------\n---- ft_memcpy :\n-----------\n");
	printf("mem :  %s\n",mem);
	ft_memcpy(mem,"abcdefghijklmnopqrstuvwxyz",5);
	printf("mem 5 chars:  %s\n",mem);
	ft_bzero(mem,15);
	printf("mem :  %s\n",mem);
	ft_memcpy(mem,"abcdefghijklmnopqrstuvwxyz",10);
	printf("mem 10 chars :  %s\n",mem);	

	printf("\n----------\n---- ft_memccpy :\n-----------\n");
	printf("mem :  %s\n",mem);
	ft_memccpy(mem,"abcdefghijklmnopqrstuvwxyz",'m',10);
	printf("mem 10 chars up to 'm':  %s\n",mem);
	printf("ft_memcpy return :  %s\n",(char *)ft_memccpy(mem,"abcdefghijklmnopqrstuvwxyz",'m',10));
	ft_bzero(mem,15);
	printf("mem :  %s\n",mem);
	ft_memccpy(mem,"abcdefghijklmnopqrstuvwxyz",'m',26);
	printf("mem cpy 26 chars up to 'm' :  %s\n",mem);
	printf("ft_memcpy return :  %s\n",(char *)ft_memccpy(mem,"abcdefghijklmnopqrstuvwxyz",'m',26));
	ft_bzero(mem,15);
	
	printf("\n----------\n---- ft_memmove :\n-----------\n");
	ft_memmove(mem,str,8);
	printf("mem move 8:  %s\n",mem);
	
	printf("\n----------\n---- ft_memchr :\n-----------\n");
	printf("mem chr in 8 , k :  %s\n",(char *)ft_memchr(mem,'k',8));
	printf("mem chr in 8 , l :  %s\n",(char *)ft_memchr(mem,'l',8));
	printf("mem chr in 2 , l :  %s\n",(char *)ft_memchr(mem,'l',2));
	
	printf("\n----------\n---- ft_memcmp :\n-----------\n");
	printf("ft 'Hello' 'Hello' 5 ? %d \n",ft_memcmp("Hello","Hello",5));
	printf("libc 'Hello' 'Hello' 5 ? %d \n",memcmp("Hello","Hello",5));
	printf("ft 'Hello' 'Hemlo' 5 ? %d \n",ft_memcmp("Hello","Hemlo",5));
	printf("libc 'Hello' 'Hemlo' 5 ? %d \n",memcmp("Hello","Hemlo",5));
	printf("ft 'Hello' 'Hemlo' 2 ? %d \n",ft_memcmp("Hello","Hemlo",2));
	printf("libc 'Hello' 'Hemlo' 2 ? %d \n",memcmp("Hello","Hemlo",2));
	
	
	int *calloc1;
	int *calloc2;
	int i = 0;
	printf("\n----------\n---- ft_calloc :\n-----------\n");
	calloc1 = ft_calloc(10,sizeof(int));
	calloc2 = calloc(10,sizeof(int));
	while( i < 10)
	{
		printf("ft calloc %d\n",calloc1[i]);
		i++;
	}
	i = 0;
	while( i < 10)
	{
		printf("calloc %d\n",calloc2[i]);
		i++;	
	}

	printf("\n----------\n---- ft_strdup :\n-----------\n");
	printf("to be copied 'HelloWorld'\n");
	printf("%s\n", ft_strdup("HelloWorld"));


	printf("\n----------\n---- ft_substr :\n-----------\n");
	printf("HelloWorld but only World : %s\n",ft_substr("HelloWorld",5,5));
	printf("HelloWorld but only Wor : %s\n",ft_substr("HelloWorld",5,3));

	printf("\n----------\n---- ft_strjoin :\n-----------\n");
	printf("One ring to rule them all + ,One ring to find them : %s\n",ft_strjoin("One ring to rule them all",", One ring to find them."));

	printf("\n----------\n---- ft_strtrim :\n-----------\n");
	printf("----hey man this string need to be trimmed----- : %s\n",ft_strtrim("----hey man this string need to be trimmed-----","-"));
	printf("---  +-*/ ** -hey man this string need to be trimmed but this * and this / should not be removed-** - //--- : %s\n", ft_strtrim("---  +-*/ ** -hey man this string need to be trimmed but this * and this / should not be removed--** - //---","+-* /"));
	
	printf("\n----------\n---- ft_split :\n-----------\n");
	printf("yassine,kieran,melissa: \n");
	char	**split;
	split = ft_split("yassine,kieran,melissa",',');
	printf("%s\n",split[0]);
	printf("%s\n",split[1]);
	printf("%s\n",split[2]);

	}
