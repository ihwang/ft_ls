/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:50:27 by ihwang            #+#    #+#             */
/*   Updated: 2019/10/27 15:48:08 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_digit(int n)
{
	int result;

	result = 1;
	if (!n)
		return (result);
	while (n)
	{
		n /= 10;
		result++;
	}
	return (--result);
}

static char	*assign_a(int n, char *c_fresh)
{
	int		limitation_flag;
	char	*limitation_pt;

	limitation_flag = 0;
	*c_fresh-- = '\0';
	limitation_pt = c_fresh;
	if (!n)
	{
		*c_fresh = '0';
		return (c_fresh);
	}
	else if (n == -2147483648)
	{
		n += 1;
		n *= -1;
		limitation_flag = 1;
	}
	while (n)
	{
		*c_fresh-- = (n % 10) + 48;
		n = n / 10;
	}
	*limitation_pt = limitation_flag ? '8' : *limitation_pt;
	return (c_fresh);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	char	*c_fresh;
	int		neg_flag;
	int		digit;

	neg_flag = 1;
	digit = cal_digit(n);
	if (n < 0)
	{
		n = n != -2147483648 ? n * -1 : n;
		neg_flag = -1;
		digit++;
	}
	fresh = (char*)malloc(sizeof(char) * digit + 1);
	c_fresh = fresh + digit;
	c_fresh = assign_a(n, c_fresh);
	*c_fresh = neg_flag == -1 ? '-' : *c_fresh;
	return (fresh);
}
