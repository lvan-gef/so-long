/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 16:26:41 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 23:16:17 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_node
{
	int	row;
	int	col;
}	t_node;

typedef struct s_bfs
{
	t_node	*nodes;
	int		front;
	int		rear;
	bool	**visited;
}	t_bfs;

typedef struct s_game
{
	int			px;
	int			py;
	int			c;
	int			e;
	int			rows;
	int			cols;
	int			counter;
	int			img_s;
	int			img_c;
	char		**map;
	char		**src_img;
	int			dir;
	mlx_t		*mlx;
	mlx_image_t	**assets;
	mlx_image_t	*display_c;
}	t_game;

// map stuff
void			read_map(t_game *game, char *file);
void			valid_map(t_game *game);

// get path stuff
void			imgs_path(t_game *game);

// read map utils stuff
void			add_spacing(t_game *game, char *line, int fd);

// init stuff
t_game			*init_game(void);
void			init_assets(t_game *game);

// reso stuff
void			check_resolution(t_game *game);

// render stuff
void			run_game(t_game *game);
void			render_item(t_game *game, mlx_image_t *img,
					size_t col, size_t row);

// hook stuff
void			my_keyhook(mlx_key_data_t keydata, void *param);

// hook utils
void			update_txt(t_game *game);
void			set_txt(t_game *game);

// handle state stuff
int				handle_state(t_game *game);
int				handle_player(t_game *game, int dir);

// handle state utils stuff
int				animation(t_game *game, int indx);
void			disable_player(t_game *game);
int				enable_player(t_game *game, int index);
int				idle_player(t_game *game, int indx);

// free stuff
char			**sl_free_map(char **map);
char			**sl_free_map_i(t_game *game, int i);
void			sl_free_game(t_game *game);

// stop game stuff
void			stop_game(t_game *game, int errc);
void			init_error(t_game *game, char *msg);
void			build_error(t_game *game, char *msg, char *line, int fd);
void			path_error(t_game *game, t_bfs *bfs, char *msg);

// util stuff
size_t			len_arr(void **elements);
mlx_texture_t	*load_png(t_game *game, const char *file);
mlx_image_t		*to_png(t_game *game, mlx_texture_t **textu, int i);

// bfs stuff
int				find_path(t_game *game);

// bfs util stuff
t_node			*create_node(int row, int col);
bool			**create_visited(const t_game *game);

// bfs free stuff
int				bfs_free_q(t_bfs *bfs);
void			bfs_free_nodes(void **nodes);

// bfs queue
void			enqueue(t_bfs *q, const t_node *node);
t_node			dequeue(t_bfs *q);
bool			is_empty(const t_bfs *q);
t_node			*find_neighbors(t_game *game, t_bfs *q,
					t_node current, int dir);

#endif
