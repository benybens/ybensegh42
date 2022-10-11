
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	if(nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while(nptr[i])
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
