/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:45:41 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/23 21:18:50 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	buf;

	i = 0;
	buf = 0;
	while (i < size - 1)
	{
		buf = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = buf;
		i++;
		size--;
	}
}

/*int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 6};
	ft_rev_int_tab(arr, 7);
	for (int j = 0; j < 7; j++) printf("%i", arr[j]);
}*/
