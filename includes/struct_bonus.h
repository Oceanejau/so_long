/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:45:52 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/17 15:15:01 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

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
	int		fo_a;
	int		fo_a_x;
	int		fo_a_y;
	int		fo_b;
	int		fo_b_x;
	int		fo_b_y;
	char	*toa;
	int		fo;
	int		obsy;

	int		cot_x;
	int		cot_y;

	void	*mur;
	void	*sol;
	void	*obs;
	void	*cot;
	void	*sun;
	void	*nid;
	void	*fox;
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
