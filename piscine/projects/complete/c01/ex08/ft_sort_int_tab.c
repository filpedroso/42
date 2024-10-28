/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:45:41 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/24 18:39:41 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	small;
	int	temp;
	int	i;

	small = 0;
	i = 1;
	if (size <= 1)
	{
		return ;
	}
	while (i < size)
	{
		if (tab[i] < tab[small])
		{
			small = i;
		}
		i++;
	}
	temp = tab[0];
	tab[0] = tab[small];
	tab[small] = temp;
	ft_sort_int_tab(tab + 1, size - 1);
}

/*int	main(void)
{
	int arr[] = {1, 7, 3, 24, 9, 6, 2};
	ft_sort_int_tab(arr, 7);
	for (int j = 0; j < 7; j++) printf("%i", arr[j]);
}*/
