/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:08:50 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/08 18:45:41 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	n;
	int	c;
	int	detected_char;

	n = 0;
	detected_char = 0;
	while (str[n] != '\0')
	{
		c = str[n];
		if (!(c >= 'a' && c <= 'z'))
		{
			detected_char = 1;
		}
		n++;
	}
	if (n == 0 || detected_char == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
