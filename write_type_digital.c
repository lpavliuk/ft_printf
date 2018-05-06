/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_digital.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:09:05 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/06 18:04:15 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	check_modifier_int(va_list ap, t_str *pf)
{
	intmax_t i;

	if ((MODF[0] == 'l' && MODF[1] == '\0') || TYPE == 'D')
		i = va_arg(ap, long int);
	else if (MODF[0] == 'l' && MODF[1] == 'l')
		i = va_arg(ap, long long int);
	else if (MODF[0] == 'h' && MODF[1] == '\0')
		i = (short int)va_arg(ap, int);
	else if (MODF[0] == 'h' && MODF[1] == 'h')
		i = (signed char)va_arg(ap, int);
	else if (MODF[0] == 'z' && MODF[1] == '\0')
		i = va_arg(ap, size_t);
	else if (MODF[0] == 'j' && MODF[1] == '\0')
		i = va_arg(ap, intmax_t);
	else
		i = va_arg(ap, int);
	return (i);
}

static void	write_to_buffer_digital(intmax_t i, short int n, t_str *pf)
{
	if (WIDTH < 0)
	{
		ft_putnbr_base(i, 10, 0, pf);
		while (WIDTH++ < (n * (-1)))
			write_to_buffer(pf, ' ');
	}
	else
	{
		while (WIDTH-- > n)
		{
			if (WIDTH < PREC || (ZERO && !MINUS))
				write_to_buffer(pf, '0');
			else
				write_to_buffer(pf, ' ');
		}
		ft_putnbr_base(i, 10, 0, pf);
	}
}

int			write_type_digital(va_list ap, t_str *pf)
{
	short int	n;
	intmax_t	i;

	i = check_modifier_int(ap, pf);
	n = ft_count(i);
	if (DOT || PREC)
		ZERO = 0;
	if (PREC > WIDTH)
		WIDTH = PREC;
	write_to_buffer_digital(i, n, pf);
	return (0);
}