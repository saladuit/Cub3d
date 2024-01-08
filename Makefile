include makerc/definitions.mk

all:	$(NAME)
.PHONY: all

$(NAME): $(MLX42) $(LIBFT) $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(MLX42) $(LIBFT) -o $(NAME)

-include $(DEPENDS)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(MLX42):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:	
	@$(RM) $(OBJS) $(DEPENDS)
	@$(MAKE) -C $(LIBFT_DIR) clean
.PHONY: clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
.PHONY: fclean

re: fclean all
.PHONY: re

debug:
	@$(MAKE) DEBUG=1
.PHONY: debug

fsan:
	@$(MAKE) FSAN=1 DEBUG=1
.PHONY: fsan

resan: fclean fsan
.PHONY: resan

rebug: fclean debug
.PHONY: rebug
