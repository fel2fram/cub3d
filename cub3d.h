/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:04:34 by fde-fram          #+#    #+#             */
/*   Updated: 2020/01/27 18:02:35 by fde-fram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# define ANGLE 0.1
# define DEPL 0.1
# define PI 3.141592653
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

typedef struct				s_img
{
	void					*mlx_ptr;
	void					*mlx_win;
	void					*mlx_img;
	int						*addr;
	int						*text[5];
	int						*addrimg[5];
	int						wimg[5];
	int						himg[5];
	int						bpp;
	int						endian;
	int						sl;
	int						width;
	int						height;
}							t_img;

typedef struct				s_data
{
	t_img					data;
	int						coulsol;
	int						coulpla;
	int						key[500];
	float					w;
	float					h;
	float					devie;
	float					cosdevie;
	float					sindevie;
	float					tandevie;
	float					*depart;
	float					joueur[2];
	char					**lmurs;
	int						sizex;
	int						sizey;
	int						largs[2];
	float					montan[4];
	float					distmax[2];
}							t_data;

char						**mappe(char *nom, char *texture[4], t_data *d);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						recurs(int i, float valeury, t_data *d,
	float *joueur);
int							ft_strlen(const char *str);
char						*ft_strdup(const char *src);
void						*ft_memmove(void *dst, const void *src, size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
void						ft_bzero(void *s, size_t n);
char						*ft_strchr(const char *s, int c);
void						*ft_calloc(size_t nmemb, size_t size);
int							get_next_line(int fd, char **line);
int							affiche_tout(char *buf, char **line, int fd);
int							fin(char **buf, int err);
int							affiche_fin(char *buf, char **line, char *temp);
int							affiche(char *buf, char **line);
int							r(float *hauteur, float *largeur, char *ligne);
int							print_screen(t_data *d);
int							pref(t_data *d, char *texture[4], char *ligne);
int							getmap(t_data *d, int i, char **ligne);
int							key_press(int keycode, t_data *data);
int							key_release(int keycode, t_data *data);
int							ft_atoi(const char *str, char c, int mult);
char						*ft_split(char *s, char c);
int							check_closed(char **res, int *largs);
int							clickescape(t_data *d);
float						ab(float a);
int							dr(t_data *d);
int							checknom(char *nom);
char						**remplace(int i, char **res);
void						initjoueur(t_data *d);
void						declare(t_data *d);
int							init(t_img *data, char *texture[5],
	float w, float h);
int							freemurs(char **res, int i);
void						freeimg(t_img *data, int i);
void						freetexture(char *texture[5]);
int							save_bmp(t_data *d);
int							ft_strncmp(const char *s1, const char *s2,
	unsigned int n);
void						declare0(char *texture[5], t_data *d);
int							mlx_boucle(t_data *d, int ac);

#endif
