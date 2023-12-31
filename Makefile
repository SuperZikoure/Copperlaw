##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

NAME	=	my_rpg
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)

BUTTONS		=	buttons
DATA		=	data
FETCH		=	$(DATA)/fetch
SCRIPTS		=	scripts
GUI			=	gui
MAPS		=	maps
MOVEMENT	=	movement
SCENES		=	scenes
GAME_SCENE	=	$(SCENES)/game
MAINM_SCENE	=	$(SCENES)/main_menu
MENU_SCENE	=	$(SCENES)/menu
INVENTORY_SCENE	=	$(SCENES)/inventory
TRANSITIONS	=	$(SCENES)/transitions
OPT_SCENE	=	$(SCENES)/option
SCREESHOTS	=	screenshots
UTILS		=	utils
PARTICLE	=	particle

SRC	=	$(BUTTONS)/create_button.c \
		$(BUTTONS)/find_button.c \
		$(BUTTONS)/mainmenu_functions.c \
		$(BUTTONS)/manage_button.c \
		$(BUTTONS)/option_functions.c \
		$(BUTTONS)/use_item.c \
		$(FETCH)/fetch_image.c \
		$(FETCH)/fetch_anim.c \
		$(FETCH)/fetch_oldest_dialogue_response.c \
		$(GUI)/create_gui.c \
		$(GUI)/display_cursor.c \
		items/use_items1.c \
		items/use_items2.c \
		$(INVENTORY_SCENE)/inventory_scene.c \
		$(MAPS)/create_map.c \
		$(MAPS)/read_map_from_file.c \
		$(MOVEMENT)/change_animation.c \
		$(MOVEMENT)/manage_collisions.c \
		$(MOVEMENT)/manage_dash.c \
		$(MOVEMENT)/move_player.c \
		$(MOVEMENT)/set_idle_animation.c \
		$(MOVEMENT)/slow_down_player.c \
		$(GAME_SCENE)/analyse_movement_keys.c \
		$(GAME_SCENE)/barman_shop.c \
		$(GAME_SCENE)/check_click.c \
		$(GAME_SCENE)/compute_dialogue_interactions.c \
		$(GAME_SCENE)/compute_game_interactions.c \
		$(GAME_SCENE)/display_cursor_trail.c \
		$(GAME_SCENE)/display_mobs.c \
		$(GAME_SCENE)/door_sound.c \
		$(GAME_SCENE)/fire_balls.c \
		$(GAME_SCENE)/game_scene.c \
		$(GAME_SCENE)/update_stats.c \
		$(GAME_SCENE)/player_management.c \
		$(GAME_SCENE)/set_player_position.c \
		$(GAME_SCENE)/update_game_gui.c \
		$(GAME_SCENE)/manage_monster.c \
		$(GAME_SCENE)/manage_coins.c \
		$(MAINM_SCENE)/display_parallax.c \
		$(MAINM_SCENE)/main_menu_scene.c \
		$(MAINM_SCENE)/parallax_position.c \
		$(SCENES)/how_to_play/how_to_play_scene.c \
		$(SCENES)/credits/credits_scene.c \
		$(MENU_SCENE)/menu_scene.c \
		$(OPT_SCENE)/option_scene.c \
		$(TRANSITIONS)/game_menu.c \
		$(TRANSITIONS)/mainmenu_credits.c \
		$(TRANSITIONS)/mainmenu_game.c \
		$(TRANSITIONS)/mainmenu_howtoplay.c \
		$(TRANSITIONS)/mainmenu_option.c \
		$(SCREESHOTS)/do_screenshot.c \
		$(SCRIPTS)/intro.c \
		$(SCRIPTS)/script_list.c \
		$(SCRIPTS)/village.c \
		$(SCRIPTS)/weapon.c \
		$(UTILS)/draw_particule.c \
		$(UTILS)/get_line.c \
		$(UTILS)/my_srand.c \
		$(UTILS)/quick_sftext_create.c \
		$(UTILS)/view_utils.c \
		$(PARTICLE)/particles_system.c \
		$(PARTICLE)/desert.c \
		$(PARTICLE)/fire.c \
		$(PARTICLE)/skill.c \
		$(PARTICLE)/dash.c \
		$(PARTICLE)/trail.c \
		analyse_events.c \
		create_game_utils.c \
		create_game.c \
		create_player.c \
		destroy_game.c \
		game_loop.c \
		get_delta.c \
		global_info.c \
		manage_inputs.c \
		manage_intersections.c \
		scene_system.c

SRC_LIB	=	stdio my string graph inv dialogues particle\
			csfml-graphics csfml-system csfml-window csfml-audio \
			m

LIB_PATHS	=	lib/stdio lib/my lib/string lib/graph lib/lib_inventory lib/dialogues lib/particle

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)
LIBRARIES	=	$(SRC_LIB:%=-l%)
LIB_PATHS_FLAG	=	$(LIB_PATHS:%=-L$(ROOT_PATH)%)

CFLAGS	=	-Wall -Wextra -Werror -I $(INCL_PATH)
LDFLAGS	=	$(LIB_PATHS_FLAG) $(LIBRARIES)
DEBUG_FLAGS	=	-g3 -gdwarf-4

MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	build_libs $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  ____                            _                   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" / ___|___  _ __  _ __   ___ _ __| |    __ ___      __"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   / _ \| '_ \| '_ \ / _ \ '__| |   / _\` \ \ /\ / /"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |__| (_) | |_) | |_) |  __/ |  | |__| (_| |\ V  V / "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \____\___/| .__/| .__/ \___|_|  |_____\__,_| \_/\_/  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"           |_|   |_|                                  "$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

build_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make -C $$MAKE_PATH $(MAKE_RULE) -s ; \
	done

clean_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make $(CLEAN_RULE) -C $$MAKE_PATH -s ; \
	done
	@make $(CLEAN_RULE) -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"

clean: clean_libs
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run: build_libs
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_THEME)" \
		LIB_PATHS="$(LIB_PATHS)" \
		LIBRARIES="$(LIBRARIES)"
	@$(ECHO) $(TESTS_THEME)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) build_libs message clean_libs clean fclean re debug tests_run
