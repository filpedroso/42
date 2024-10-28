#include "rush-02.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_str;

	dict_path = "numbers.dict";
	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 3)
	{
		dict_path = argv[1];
		number_str = argv[2];
	}
	else
		number_str = argv[1];
	if (!is_valid_number(number_str))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	help_main(dict_path, number_str);
	return (0);
}
void	help_main(char *dict_path, char *number_str)
{
	t_dict	*dict;

	dict = parse_dict(dict_path);
	if (!dict)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if (!convert_and_print(dict, number_str))
	{
		write(2, "Dict Error\n", 11);
		free_dict(dict);
		return (1);
	}
	free_dict(dict);
	return (0);
}
