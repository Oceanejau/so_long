/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:21:34 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/17 15:25:51 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEF_BONUS_H
# define DEF_BONUS_H

# include "so_long_bonus.h"

# ifdef __MACH__
#  define ESC		53
#  define W		13
#  define A		0
#  define S		1
#  define D		2
# endif

# ifdef __linux__
#  define ESC		65307
#  define W		119
#  define A		97
#  define S		115
#  define D		100
# endif

#endif
