#include "so_long.h"
/*
int	create_trgb(t_trgb *trgb)
{
	return (trgb->t << 24 | trgb->r << 16 | trgb->g << 8 || trgb->b);
}

int	get_t(t_trgb *trgb)
{
	return ((trgb->trgb >> 24) & 0xFF);
}

int	get_r(t_trgb *trgb)
{
	return ((trgb->trgb >> 16) & 0xFF);
}

int	get_g(t_trgb *trgb)
{
	return ((trgb->trgb >> 8) & 0xFF);
}

int	get_b(t_trgb *trgb)
{
	return (trgb->trgb & 0xFF);
}
*/
///////////////////////////////

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
