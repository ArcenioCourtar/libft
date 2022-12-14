/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:18:42 by acourtar          #+#    #+#             */
/*   Updated: 2022/10/31 18:57:17 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 1 if character 'c' is a digit.
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
