/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:11:16 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/09 20:24:28 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	n;
	int	only_printer;

	n = 0;
	only_printer = 1;
	while (str[n] != '\0')
	{
		if (!(str[n] >= 32 && str[n] <= 126))
		{
			only_printer = 0;
		}
		n++;
	}
	if (n == 0 || only_printer == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
