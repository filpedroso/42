/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:07:53 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/10 21:08:28 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}
/* int main(void) {
    int *range;
    int size;
    int i;

    // Test case 1: Normal range
    size = ft_ultimate_range(&range, 3, 10);
    if (size == -1) {
        printf("Memory allocation failed for range (3, 10)\n");
    } else if (size == 0) {
        printf("Range is empty for min: 3, max: 10\n");
    } else {
        printf("Range from 3 to 10: ");
        for (i = 0; i < size; i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
    }
    free(range);

    // Test case 2: min >= max
    size = ft_ultimate_range(&range, 10, 3);
    if (size == 0) {
        printf("Range is empty for min: 10, max: 3\n");
    } else {
        printf("Test case failed for min: 10, max: 3\n");
    }

    // Test case 3: min == max
    size = ft_ultimate_range(&range, 5, 5);
    if (size == 0) {
        printf("Range is empty for min: 5, max: 5\n");
    } else {
        printf("Test case failed for min: 5, max: 5\n");
    }

    // Test case 4: Large range
    size = ft_ultimate_range(&range, -5, 5);
    if (size == -1) {
        printf("Memory allocation failed for range (-5, 5)\n");
    } else if (size == 0) {
        printf("Range is empty for min: -5, max: 5\n");
    } else {
        printf("Range from -5 to 5: ");
        for (i = 0; i < size; i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
    }
    free(range);

    // Test case 5: Small range
    size = ft_ultimate_range(&range, 0, 1);
    if (size == -1) {
        printf("Memory allocation failed for range (0, 1)\n");
    } else if (size == 0) {
        printf("Range is empty for min: 0, max: 1\n");
    } else {
        printf("Range from 0 to 1: ");
        for (i = 0; i < size; i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
    }
    free(range);

    return 0;
} */