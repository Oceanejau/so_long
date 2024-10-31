/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:18:48 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:46:35 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx {
	int		y;
	int		x;

	int		gnl;
	int		err;
	int		error_map_ber;
	int		err_tab;
	int		fd;
	int		err_img;
	int		err_mur;
	int		err_cot;
	int		err_nid;
	int		err_col;
	int		err_char;

	char	*path;
	int		**ber;

	int		len;
	int		len_x;
	int		len_y;
	int		err_len;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		lon;
	int		lar;
	int		col;

	int		obsy;

	int		cot_x;
	int		cot_y;

	void	*mur;
	void	*sol;
	void	*obs;
	void	*cot;
	void	*sun;
	void	*nid;
	int		si_x;
	int		si_y;
	int		img_width;
	int		img_height;

	int		end_loop;
	int		count;

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*dst;
	int		offset;
	int		pixy;
	int		lh;
	int		en;
	int		close;
}			t_mlx;

#endif
