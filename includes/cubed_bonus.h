/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:15:12 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 18:14:06 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_BONUS_H
# define CUBED_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# define W_W 1000
# define W_H 700
# define PI 3.14159265358979323846
# define PXL 1
# define SCALE 38

# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define ESC_KEY 65307
# define A_KEY 97
# define S_KEY 115
# define W_KEY 119
# define D_KEY 100
# define E_KEY 101

# define SKY_BLUE 9882076
# define ONYX 3225144
# define SNOW 16447222
# define WHITE 16777215
# define YELLOW 16776960
# define LIGHT_YELLOW 16777139
# define RED 13631488

# define SPEED 0.1

typedef struct s_img_data
{
	void	*xpm;
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;
	int		h;
	int		w;
}	t_img_data;

typedef struct s_anim
{
	t_img_data	anim1;
	t_img_data	anim2;
	t_img_data	anim3;
	t_img_data	anim4;
	t_img_data	anim5;
	t_img_data	anim6;
	t_img_data	anim7;
	t_img_data	anim8;
	t_img_data	anim9;
	t_img_data	anim10;
	t_img_data	anim11;
	t_img_data	anim12;
}	t_anim;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_img_data		new_img;
	t_img_data		n_wall;
	t_img_data		s_wall;
	t_img_data		e_wall;
	t_img_data		w_wall;
	t_img_data		d_wall;
	bool			w_key;
	bool			a_key;
	bool			s_key;
	bool			d_key;
	bool			left_key;
	bool			right_key;
	int				img_h;
	int				img_w;
	struct s_data	*dataa;
}	t_mlx;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		plane_x;
	double		plane_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			hit;
	int			side;
	double		wall_dist;
	int			wall_h;
	int			cut_ceil_wall;
	int			cut_wall_floor;
	double		time;
	double		old_time;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		wall_x;
	double		step;
}	t_ray;

typedef struct s_data
{
	int			fd;
	char		**tab_map;
	int			h;
	int			w;
	int			flag;
	char		*path_n_texture;
	char		*path_e_texture;
	char		*path_s_texture;
	char		*path_w_texture;
	char		*floor_rgb_str;
	int			floor_rgb;
	char		*ceiling_rgb_str;
	int			ceiling_rgb;
	char		player_orientation;
	double		player_x;
	double		player_y;
	double		player_dir_x;
	double		player_dir_y;
	double		player_angle;
	int			half_screen;
	int			i_anim;
	bool		door_open;
	int			door_nbr;
	int			first_collision_x;
	int			first_collision_y;
	int			begin_x;
	int			begin_y;
	int			minimap_start_x;
	int			minimap_start_y;
	t_mlx		mlx;
	t_anim		anim;
	t_ray		*ray;
	t_list		*lst_door;
}	t_data;

///// INIT STRUCT /////
void	init_var(t_data *data);
int		init_mlx(t_data *data, t_mlx *mlx);
void	init_img_data(t_data *data, t_img_data *img, char *path);

///// CHECK AND PARSING /////
void	check_config_file(t_data *data, char *map);
int		check_order_nbr_instr(t_data *data, char *map);
int		is_valid_instr(t_data *data, char *map);
void	set_all_texture(t_data *data, char *line);
int		check_all_texture(t_data *data);
int		check_first_char(char *s, char c);
int		check_char(t_data *data, char **map);
int		check_wall(t_data *data, char **map);
int		count_height(t_data *data, char *path_map);
void	get_colors_rgb(t_data *data);
int		count_char(char *s, char c);
int		line_is_map(char *str);
int		check_sizemap(t_data *data);

///// INITIALIZATION GAME /////
void	init_map(t_data *data);
void	init_player_var(t_data *data);
void	launch_game(t_data *data);
void	game_loop(t_data *d, t_ray *ray);

///// RAYCASTING //////
void	init_raycast_var(t_data *d, t_ray *ray);
void	init_raycast_var_loop(t_data *d, t_ray *ray, int x);
void	get_step_xy(t_data *d, t_ray *ray);
void	get_wall_dist(t_data *d, t_ray *ray);
void	get_wall_dist_bonus(t_data *d, t_ray *ray);
void	get_wall_height(t_data *d, t_ray *ray);

///// DRAW & TEXTURES FUNCTIONS /////
void	get_texture(t_data *data, t_ray *ray, int x);
void	get_pixel_texture(t_data *data, t_ray *ray, t_img_data wall, int x);
void	put_pixel_into_img(t_data *data, int x, int y, int color);
void	draw_one_line(t_mlx *mlx, int x1, float y2, int color);
void	draw_ceil_line(t_mlx *mlx, int x1, float y2, int color);
void	draw_lines(t_data *data, t_ray *ray, int x);

///// DISPLAY FUNCTIONS //////
void	display_config(t_data *data);
void	display_map(t_data *data);
int		count_size_tab(char **tab);

///// LOOP-HOOK /////
void	ft_hook(t_data *data);
int		check_key_status(t_data *data);
void	move_cam_left(t_data *data);
void	move_cam_right(t_data *data);
void	ft_move_front(t_data *data);
void	ft_move_back(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
void	mouse_move(t_data *data);
int		close_window(t_mlx *mlx);

///// ANIM NAVI /////
void	check_img_size_anim(t_data *data);
void	anim_loop(t_data *data);

///// DOOR CHECK /////
void	init_and_count_door(t_data *data, t_list *lst_door);
void	check_open(t_data *data, t_ray *ray);
t_list	*get_door(t_list *lst, int id);
int		find_id_door(t_list *lst, int x, int y);
t_list	*which_door(t_list *lst, int x, int y);

///// MINIMAP //////
int		minimap(t_data *data);

///// ERROR FUNCTIONS /////
void	error_exit(t_data *data, char *err_msg);
void	print_error(char *err_msg);

///// FREE FUNCTIONS /////
void	free_all(t_data *data);
void	free_split(char **tab);
void	free_list(t_list **lst);
void	free_parsing(t_data *data);
void	free_img_anim(t_data *data, t_mlx *mlx);
void	free_img_mlx(t_data *data, t_mlx *mlx);

///// UTILS FUNCTIONS /////
void	print_raycast_info(t_data *d);
void	display_config(t_data *data);
void	display_map(t_data *data);
void	display_lst(t_list *lst);

#endif
