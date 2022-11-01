/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:28 by acourtar          #+#    #+#             */
/*   Updated: 2022/11/01 08:55:25 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str, int i);
static int	state_changer(const char *nptr, int i, int s, int *negativenum);

// TODO: JUST USE THREE WHILE LOOPS LMAO
// Return int equivalent of string 'nptr'.
int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				s;
	int				negativenum;
	int				number;

	i = 0;
	number = 0;
	s = 0;
	negativenum = 0;
	while (i < ft_strlen(nptr))
	{
		s = state_changer(nptr, i, s, &negativenum);
		if (s == 2)
		{
			number *= 10;
			number += nptr[i] - '0';
		}
		else if (s == 3)
			break ;
		i++;
	}
	if (negativenum == 1)
		number *= -1;
	return (number);
}

// Similar to the other 'isx' functions, but checks for spaces and
// space-like characters.
// Why isn't this part of libft?????? cringe.
static int	ft_isspace(const char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\f')
		return (1);
	if (str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		return (1);
	return (0);
}

// Tracks what characters have been seen earlier so it can
// start or stop tracking actual numbers.
static int	state_changer(const char *nptr, int i, int s, int *negativenum)
{
	if (ft_isspace(nptr, i) && s == 0)
		return (0);
	else if (nptr[i] == '+' && s == 0)
		return (1);
	else if (nptr[i] == '-' && s == 0)
	{
		*negativenum = 1;
		return (1);
	}
	else if (nptr[i] >= '0' && nptr[i] <= '9' && (s == 1 || s == 0 || s == 2))
		return (2);
	else
		return (3);
}
