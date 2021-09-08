/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:22:16 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:51:02 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_count_nums(const char *str);

int	ft_atoi(const char *str)
{
	size_t	num;
	int		sign;

	sign = 1;
	while ((9 <= *str && *str <= 15) || *str == ' ')
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (ft_count_nums(str) > 12)
		return (-1);
	num = 0;
	while ('9' >= *str && *str >= '0')
	{
		num *= 10;
		num += sign * (*str - '0');
		++str;
	}
	return (num);
}

static int	ft_count_nums(const char *str)
{
	const char	**tmp;
	size_t		count;

	tmp = &str;
	count = 0;
	while ('9' >= *(*tmp) && *(*tmp) >= '0')
	{
		count++;
		++*tmp;
	}
	return (count);
}
