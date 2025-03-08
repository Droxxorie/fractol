/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:14:28 by eraad             #+#    #+#             */
/*   Updated: 2025/02/27 12:14:28 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* count numbers of leading zeros int the floating part up to 3 digits
static int	ft_zerolen(double n)
{
	int	len;
	int	int_part;

	if (n == 0)
		return (0);
	len = 0;
	int_part = (int)n;
	while (int_part == 0 && len < 3)
	{
		n *= 10;
		int_part = (int)n;
		len++;
	}
	return (len - 1);
}

//* up to 3 digits
static int	ft_declen(double n)
{
	int		len;
	double	dec_part;

	len = 0;
	dec_part = fabs(n - (int)n);
	while (dec_part > 0 && len < 3)
	{
		dec_part *= 10;
		dec_part -= (int)dec_part;
		len++;
	}
	if (len > 0)
		return (len);
	return (1);
}

static void	handle_nums(double num, char **result, char **int_part,
		char **dec_part)
{
	int		zero_len;
	char	*temp;

	zero_len = ft_zerolen(fabs(num - (int)num));
	*result = ft_strjoin(*int_part, ".");
	while (zero_len > 0)
	{
		temp = ft_strjoin(*result, "0");
		*result = ft_strdup(temp);
		free(temp);
		zero_len--;
	}
	temp = ft_strjoin(*result, *dec_part);
	free(*result);
	*result = ft_strdup(temp);
	free(temp);
	if (num < 0.0)
	{
		temp = ft_strjoin("-", *result);
		free(*result);
		*result = ft_strdup(temp);
		free(temp);
	}
}

char	*ft_dbltoa(double num)
{
	int		n;
	char	*int_part;
	char	*dec_part;
	char	*result;

	n = (int)num;
	int_part = ft_itoa(abs(n));
	dec_part = ft_itoa((int)(fabs(num - n) * pow(10, ft_declen(num))) + 0.5);
	handle_nums(num, &result, &int_part, &dec_part);
	free(int_part);
	free(dec_part);
	return (result);
}
