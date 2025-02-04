/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:47:15 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:47:18 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_min_itoa(char *str, int n, size_t len)
{
	str[len + 1] = '\0';
	if (n == -2147483648)
	{
		n = (n + 1) * -1;
		while (len)
		{
			str[len--] = (n % 10) + '0';
			n = n / 10;
		}
		str[0] = '-';
		str[ft_strlen(str) - 1] += 1;
		return (str);
	}
	else
	{
		n *= -1;
		while (len)
		{
			str[len--] = (n % 10) + '0';
			n = n / 10;
		}
		str[0] = '-';
		return (str);
	}
}

static size_t	ft_digit_counter(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_digit_counter(n);
	if (n >= 0)
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str[len] = '\0';
		while (len)
		{
			str[--len] = (n % 10) + '0';
			n = n / 10;
		}
	}
	else
	{
		str = malloc((len + 2) * sizeof(char));
		if (!str)
			return (NULL);
		ft_min_itoa(str, n, len);
	}
	return (str);
}
