#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx {
		int	y;
		int	x;

	/* -- BEAR -- */
		int	gnl;
		int	err;
		int	error_map_ber;
		int	err_tab;
		int	fd;
		int	err_img;
		int	err_mur;
		int	err_cot;
		int	err_nid;
		int	err_col;
		

	/* -- MAP -- */
		char	*path;
		int	**ber;//map
	//	int	size;//size de la map
		int	len;
		int	len_x;
		int	len_y;
		int	err_len;
		int	P_x;
		int	P_y;
		int	E_x;
		int	E_y;
		int	lon;//longeur image en pixels
		int	lar;//largeur imahe en pixels
		int	col;

	/* -- POS des chars qui bougent sur MAP -- */
		int	cot_x;//cot50
		int	cot_y;//cot50
	//	int	*sun_x;//sun50
	//	int	*sun_y;//sun50
	//	int	*gold_x;
	//	int	*gold_y;

	/* -- IMAGES.XPM -- */
		void	*mur;//tree50
		void	*sol;//grass50
		void	*obs;//buche50
		void	*cot;//cot50
		void	*sun;//sun50
		void	*nid;//exit50
		int	si_x;//size image x
		int	si_y;//size image y
		int	img_width;
		int	img_height;
	
		int	end_loop;
		int	count;
	
		void	*mlx;
		void	*win;
		void	*img;
		char	*addr;
		char	*dst;
		int	offset;//mémoire de line_lenght
		int	bits_per_pixy;
		int	line_length;
		int	endian;
		int	close;
		int	cot1_x;
		int	cot1_y;
		void	*cot1;
		void	*cot2;
		void	*cot3;
		void	*cot4;
}		t_mlx;

typedef	struct	s_trgb {
			int	t;
			int	r;
			int	g;
			int	b;
			int	trgb;
}		t_trgb;

#endif
