/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:16:44 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/13 17:18:02 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_type(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (0);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (2);
	}
	else
	{
		return (3);
	}
}

char	*ft_strcapitalize(char *str)
{
	int		n;
	char	c;
	int		char_type_old;

	n = 0;
	while (str[n] != '\0')
	{
		c = str[n];
		if (n == 0)
		{
			if (char_type(c) == 1)
				str[n] = c - 32;
		}
		else
		{
			char_type_old = char_type(str[n - 1]);
			if ((char_type_old != 3) && char_type(c) == 0)
				str[n] = c + 32;
			else if (char_type_old == 3 && char_type(c) == 1)
				str[n] = c - 32;
		}
		n++;
	}
	return (str);
}
