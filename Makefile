NAME = so_long

CC = cc
GFLAGS = -Wall -Werror -Wextra -Wshadow -Wpedantic

SRCDIR = src/
BNS_SRCDIR = bonus/
OBJDIR = obj/
BNS_OBJDIR = bns_obj/

BNS_SRCFILES = bfs.c bfs_free.c bfs_queue.c bfs_utils.c check_resolution.c free_me.c handle_exit.c handle_state.c handle_state_utils.c hooks.c hooks_utils.c init.c prep_textures.c read_map.c read_map_utils.c render_map.c so_long.c utils.c valid_map.c
SRCFILES = bfs.c bfs_free.c bfs_queue.c bfs_utils.c check_resolution.c free_me.c handle_exit.c handle_state.c handle_state_utils.c hooks.c init.c prep_textures.c read_map.c render_map.c so_long.c utils.c valid_map.c

SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)
BNS_SRCOBJ = $(BNS_SRCFILES:%.c=$(BNS_OBJDIR)%.o)

LIBMLX = ./MLX42
LIBFT = ./libft
HEADERS = -I include -I $(LIBMLX)/include -I $(LIBFT)/headers

.PHONY: all bonus libft libmlx clean fclean re

all: libmlx libft $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBMLX)
	$(MAKE) -C $(LIBFT)
	# $(CC) $(GFLAGS) $(SRCOBJ) $(LIBMLX)/libmlx42.a -g3 -fsanitize=address $(LIBFT)/libft.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	$(CC) $(GFLAGS) $(SRCOBJ) $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm -o $(NAME)


bonus: $(BNS_SRCOBJ)
	$(MAKE) -C $(LIBMLX)
	$(MAKE) -C $(LIBFT)
	# $(CC) $(GFLAGS) $(BNS_SRCOBJ) $(LIBMLX)/libmlx42.a -g3 -fsanitize=address $(LIBFT)/libft.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	$(CC) $(GFLAGS) $(BNS_SRCOBJ) $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p obj
	$(CC) -c $(GFLAGS) -o $@ $<

$(BNS_OBJDIR)%.o: $(BNS_SRCDIR)%.c
	@mkdir -p bns_obj
	$(CC) -c $(GFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBMLX)
	$(MAKE) clean -C $(LIBFT)
	rm -rf obj
	rm -rf bns_obj

fclean: clean
	$(MAKE) fclean -C $(LIBMLX)
	$(MAKE) fclean -C $(LIBFT)
	rm -f so_long

re: fclean all

