#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			character = 'z';
	char			*string = '\0';
	char			*pointer = "";
	int				integer = INT_MIN;
	unsigned int	u_int = UINT_MAX;
	int				hex = 0xffffff;
	int				result;

	ft_printf("\nft_printf:\n");
	result = ft_printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	ft_printf("\nft_printf return value: %d\n", result);

	printf("\n\nprintf:\n");
	result = printf("\nChar: %c\nString: %s\nPointer: %p\nInt: %d\n"
	"Unsigned int: %u\nPercent: %%\nLower Hex: %x\nUpper Hex: %X\n",
		character, string, pointer, integer, u_int, hex, hex);
	printf("\nprintf return value: %d\n", result);
}