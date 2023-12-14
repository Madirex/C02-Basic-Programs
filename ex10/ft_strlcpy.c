/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:29:09 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/14 17:29:25 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_length(char *str)
{
	int	count;

	count = 0;
	while (*(str + count))
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	if (size == 0)
		return (string_length(src));
	while (count < size - 1 && *(src + count))
	{
		*(dest + count) = *(src + count);
		count++;
	}
	*(dest + count) = '\0';
	return (string_length(src));
}
