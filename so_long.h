/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:07:46 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 21:07:22 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <stdio.h>

typedef struct s_data
{
	int						width;
	int						height;
	void					*img;

}							t_data;

# define DISPLAY_ERROR "The map must contain 1 exit,at least 1 \
collectible,and 1 starting position to be valid.\n"
# define DISPLAY_ERROR2 "The format name must be end with (.ber)\n"
# define DISPLAY_ERROR3 "The map must be surrounded by walls \n"
# define DISPLAY_ERROR4 "The map must be rectangular \n"

typedef struct s_imgs
{
	t_data					walls;
	t_data					floor;
	t_data					collect;
	t_data					player;
	t_data					exit_open;
	t_data					exit_close;
	t_data					enemy;
	t_data					left_image;
}							t_imgs;

typedef struct s_position_of_symbols
{
	int						dx;
	int						dy;

}							t_position_of_symbols;

typedef struct s_vars
{
	t_imgs					img;
	void					*mlx;
	void					*win;
	int						player_x;
	int						player_y;
	int						key_up;
	int						key_down;
	int						key_left;
	int						key_right;
	char					*path;
	char					**represent_env;
	int						moves;
	int						how_much_collect;
	char					**visited;
	int						fd;
	int						j;
	int						player;
	int						collectible;
	int						exit;
	int						number_of_enemy;
	t_position_of_symbols	positions;
}							t_vars;

typedef struct t_count
{
	int						countdigitis;
	int						index;
	int						strlenbuffer;
	char					*str;
}							t_c;
typedef struct t_rowandcolumn
{
	size_t					words;
	int						i;
	int						j;
	char					**ptr;
	int						nextblock;
	int						length;
}							t_rowsandcolumns;

int							check_file_ber(int count, char *path);
int							check_extension(char *extension);
int							check_walls(char *path);
int							check_is_rectangular(char *path,
								int number_of_lines);
int							get_lines(char *path);
int							check_every_line(char *path, int lines);
int							get_column(char **env);
char						**fill(char *path);
int							check_exit_and_player(char *path);
int							start_drawing(t_vars *vars);
void						init_img(t_vars *vars);
int							get_position_x(char **world);
int							get_position_y(char **world);
int							get_number_of_fish(char **world);
int							check_is_valid_collectible(char **world);
int							check_is_valid_path(char **world, t_vars vars);
char						*ft_itoa(int n);
void						*ft_memset(void *b, int c, size_t len);
char						*ft_strrchr(const char *s, int c);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strdup(const char *s1);
char						*ft_strchr(const char *s, int c);
void						*ft_calloc(size_t count, size_t size);
void						ft_bzero(void *s, size_t n);
int							check_if_therese_way(int x, int y, t_vars *vars);
int							check_if_position_is_valid(char **world);
int							key_event(int keycode, void *param);
int							animation(void *params);
void						show_info(void);
int							kill(int mouse, int x, int y, void *params);
void						ft_putstr_fd(char *s, int fd);
int							start_drawing(t_vars *vars);
void						up(t_vars *vars);
void						down(t_vars *vars);
void						right(t_vars *vars);
void						left(t_vars *vars);
int							kcheck_symbols(char *path);
void						ft_putnbr_fd(int n, int fd);
void						ft_putchar_fd(char c, int fd);
int							check_symbols(char **env);
int							exit_(void);
void						init_visited(t_vars *vars);
int							backtracking(int x, int y, t_vars *vars);
void						load_collectible_texture(t_vars *vars);
void						load_floor_texture(t_vars *vars);
void						load_player_texture(t_vars *vars);
void						load_exit_texture(t_vars *vars);
void						load_walls_texture(t_vars *vars);
void						load_enemy_texture(t_vars *vars);
int							start_drawing_bonus(t_vars *vars);
int							kill(int mouse, int x, int y, void *params);
void						show_moves(t_vars *vars);
#endif
