/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:07:35 by vkist-si          #+#    #+#             */
/*   Updated: 2023/02/22 22:07:39 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	ft_atoi_long(char *str)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (0);
	if ((*str == 45) || (*str == 43))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if (nbr > (LLONG_MAX - (*str - 48)) / 10 && sign == 1)
			exit_with_error("exit", "numeric argument required", 2);
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return (nbr * sign);
}
