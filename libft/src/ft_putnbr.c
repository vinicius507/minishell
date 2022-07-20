/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:06:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/07 16:06:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_DIGITS 10

void	ft_putnbr(int n)
{
	int		counter;
	int		digits;
	char	nbr[MAX_DIGITS];

	digits = 1;
	counter = n / 10;
	while (counter)
	{
		counter /= 10;
		digits++;
	}
	if (n < 0)
		ft_putchar('-');
	else
		n *= -1;
	nbr[digits] = '\0';
	while (digits--)
	{
		nbr[digits] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	counter = -1;
	ft_putstr(nbr);
}
