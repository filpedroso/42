int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	i = -1;
	sign = 1;
	while (is_space(str[++i]))
		;
	while (str[i] == '-' || str[i] == '+')
	{
		sign = calculate_sign(sign, str[i]);
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		result = calculate_result(result, &str[i]);
	}
	return (result * sign);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	calculate_sign(int sign, char c)
{
	if (c == '-')
	{
		sign = -sign;
	}
	return (sign);
}

int	calculate_result(int result, char *str)
{
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}