/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_o_x_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:42:10 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/07 13:19:21 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_hash(t_str *pf)
{
	if ((TYPE == 'o' || TYPE == 'O') && HASH)
		BUFFER[N++] = '0';
}

static void	write_to_buffer_un_digital(uintmax_t un_i, short int n, t_str *pf)
{
	if (WIDTH < 0)
	{
		check_hash(pf);
		if (TYPE == 'o' || TYPE == 'O')
			ft_unputnbr_base(un_i, 8, 0, pf);
		else
			ft_unputnbr_base(un_i, 16, 0, pf);
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
		check_hash(pf);
		if (TYPE == 'o' || TYPE == 'O')
			ft_unputnbr_base(un_i, 8, 0, pf);
		else
			ft_unputnbr_base(un_i, 16, 0, pf);
	}
}

int		write_type_o_x_p(va_list ap, t_str *pf)
{
	short int	n;
	uintmax_t	un_i;

	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'o' || TYPE == 'O')
	{
		un_i = check_modifier_un_int(ap, pf);
		if (TYPE == 'o' || TYPE == 'O')
			n = ft_count(un_i, 8);
		else
			n = ft_count(un_i, 16);
		if ((TYPE == 'o' || TYPE == 'O') && HASH)
			n++;
	}
	if (DOT || PREC)
		ZERO = 0;
	if (PREC > WIDTH)
		WIDTH = PREC;
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'o' || TYPE == 'O')
		write_to_buffer_un_digital(un_i, n, pf);
	return (0);
}