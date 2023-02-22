/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:41:39 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 21:41:42 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_check_sign(const char **nptr)
{
	long double	sign;

	sign = 1.0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1.0;
		(*nptr)++;
	}
	return (sign);
}

long double	ft_atold(const char *nptr)
{
	long double	res;
	long double	decimal;
	long double	sign;

	res = 0.0;
	decimal = 0.1;
	sign = ft_check_sign(&nptr);
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	while (ft_isdigit(*nptr))
	{
		res = (res * 10.0) + *nptr++ - '0';
		if (*nptr++ == '.')
		{
			while (ft_isdigit(*nptr))
			{
				res += (*nptr++ - '0') * decimal;
				decimal *= 0.1;
			}
		}
	}
	return (sign * res);
}
