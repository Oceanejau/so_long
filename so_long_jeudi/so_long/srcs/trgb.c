/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:03:30 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/24 21:04:53 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(t_trgb *trgb)
{
	return (*(int *)(unsigned char [4]){trgb->b, trgb->g, trgb->r, trgb->t});
}

unsigned char	get_t(t_trgb *trgb)
{
	return (((unsigned char *)&trgb->trgb)[3]);
}

unsigned char	get_r(t_trgb *trgb)
{
	return (((unsigned char *)&trgb->trgb)[2]);
}

unsigned char	get_g(t_trgb *trgb)
{
	return (((unsigned char *)&trgb->trgb)[1]);
}

unsigned char	get_b(t_trgb *trgb)
{
	return (((unsigned char *)&trgb->trgb)[0]);
}
