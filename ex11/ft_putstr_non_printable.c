/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:43:50 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/14 11:31:25 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_str(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (str[i] >= 32 && str[i] <= 126)
		{
			write_str(str[i]);
		}
		else
		{
			write_str('\\');
			write_str("0123456789abcdef"[c / 16]);
			write_str("0123456789abcdef"[c % 16]);
		}
		i++;
	}
}
