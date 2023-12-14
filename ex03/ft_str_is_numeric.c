/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:05:59 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/08 18:44:14 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	n;
	int	c;
	int	not_only_digit;

	n = 0;
	not_only_digit = 0;
	while (str[n] != '\0')
	{
		c = str[n];
		if (!(c >= '0' && c <= '9'))
		{
			not_only_digit = 1;
		}
		n++;
	}
	if (n == 0 || not_only_digit == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
