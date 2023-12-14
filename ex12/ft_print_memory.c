/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:41:11 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/14 12:32:39 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	write_hex_address(int r, unsigned long address)
{
	char			hex_buffer[19];
	unsigned long	mask;
	int				i;
	unsigned long	digit;

	mask = 0xF000000000000000UL;
	i = 0;
	while (i < 16)
	{
		digit = (address & mask) >> (60 - (i * 4));
		hex_buffer[i] = "0123456789abcdef"[digit];
		mask >>= 4;
		i++;
	}
	hex_buffer[16] = ':';
	write(1, hex_buffer, 17);
	return (r);
}

int	add_aditional_space(int j, int size, int aditional_space)
{
	if (j < size)
	{
		if (j % 2 == 0 || j >= size)
			write(1, " ", 1);
	}
	else
	{
		if (aditional_space)
		{
			write(1, " ", 1);
			aditional_space = 0;
		}
		else
		{
			aditional_space = 1;
		}
		write(1, "  ", 2);
	}
	return (aditional_space);
}

char	get_value(unsigned char value)
{
	char	hex_chars[17];
	int		n;
	char	hex_buffer[2];

	n = 0;
	while (n < 10)
	{
		hex_chars[n] = n + '0';
		n++;
	}
	hex_chars[10] = 'a';
	hex_chars[11] = 'b';
	hex_chars[12] = 'c';
	hex_chars[13] = 'd';
	hex_chars[14] = 'e';
	hex_chars[15] = 'f';
	hex_chars[16] = '\0';
	hex_buffer[0] = hex_chars[(value >> 4) & 0x0F];
	hex_buffer[1] = hex_chars[value & 0x0F];
	write(1, hex_buffer, 2);
	if (value < 32 || value > 126)
		value = '.';
	return ((char)value);
}

void	print_array(char *arr, int size)
{
	int	i;

	i = 0;
	write(1, " ", 1);
	while (i < size)
	{
		if (arr[i] != '\0')
		{
			write(1, &arr[i], 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			print_buffer[17];
	int				aditional_space;

	i = 0;
	aditional_space = 0;
	while (i < size && size != 0)
	{
		j = write_hex_address(i, (unsigned long)((unsigned char *)addr + i));
		while (j < i + 16)
		{
			aditional_space = add_aditional_space(j, size, aditional_space);
			if (j < size)
				print_buffer[j % 16] = get_value(((unsigned char *)addr)[j]);
			else
				print_buffer[j % 16] = '\0';
			j++;
		}
		print_array(print_buffer, 16);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
