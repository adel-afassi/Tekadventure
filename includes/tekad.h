/*
** tekad.h for  in /home/Quentss/Work/graphic/tekadventure
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 16:40:40 2017 Quentin AMARAL
** Last update Sun May 28 22:25:13 2017 adel
*/

#ifndef TEKAD_H_
# define TEKAD_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Window.h>

# define EXIT_SUCCESS 0
# define EXIT_ERROR 84
# define LEFT 0
# define RIGHT 1
# define MONSTER_ATTACK 2
# define CONF_FILE ".my_conf"
# define INTRO_FILE ".my_intro"
# define TEK "TekAdventure"
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 720
# define SPRITE_WIDTH 150
# define SPRITE_HEIGHT 110
# define NB_LINES 2
# define NB_OBJS_ON_LINE 5
# define CHARA_DAMAGE 10
# define CHARA_SCALE 3.5
# define CHARA_WIDTH SPRITE_WIDTH / NB_OBJS_ON_LINE
# define CHARA_HEIGHT SPRITE_HEIGHT / NB_LINES
# define CHARA_SPEED 10
# define ENEMY_FREQUENCE 3
# define WIN_LOSE_TIME 10
# define EXITING "Exiting tekadventure...\n"
# define LAUNCHER "Opening launcher...\n"
# define PLAY "Playing game...\n"
# define ERR_ITEM_PICK_SOUND "Can't load item pick-up sound\n"
# define ERR_MISSING_DOOR "Expected a door but haven't\n"
# define ERR_OBJS_LOAD "Can't load an obj...\n"

typedef struct		s_pic
{
  char			*name;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfVector2f		scale;
  sfVector2f		position;
  sfVector2u		size;
}			t_pic;

typedef struct		s_scroller
{
  t_pic			*pic1;
  t_pic			*pic2;
  char			*str;
  int			speed;
  struct s_scroller	*next;
}			t_scroller;

typedef struct		s_obj
{
  t_pic			*pic_obj;
  t_pic			*pic_inv;
  int			is_find;
  sfClock		*clock;
  int			anim;
  sfVector2f		pos;
  sfVector2f		scale;
  int			id_room;
  struct s_obj		*next;
}			t_obj;

typedef struct		s_chara
{
  sfClock		*clock;
  int			sp;
  int			life;
  sfIntRect		rect;
  int			in_movement;
  sfVector2f		pos;
  sfVector2i		pos_mouse;
  sfVector2f		scale;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_chara;

typedef struct		s_door
{
  int			max_x;
  int			min_x;
  int			max_y;
  int			min_y;
}			t_door;

typedef struct		s_boss
{
  int			life;
  int			current_life;
  int			damage;
  int			rate;
  sfClock		*clock;
  t_pic			*pic;
}			t_boss;

typedef struct		s_enem
{
  sfClock		*clock;
  int			id;
  int			life;
  int			current_life;
  int			damage;
  t_pic			*pic;
  struct s_enem		*next;
}			t_enem;

typedef struct		s_room
{
  int			id;
  int			is_final;
  int			max_move_top;
  int			max_move_bot;
  struct s_room		*left_room;
  int			left_room_int;
  struct s_room		*right_room;
  int			right_room_int;
  struct s_room		*bot_room;
  int			bot_room_int;
  struct s_room		*door_room;
  int			door_room_int;
  t_door		*door;
  sfVector2f		top_left;
  sfVector2f		back_rigt;
  t_pic			*back;
  t_enem		*enemy;
  struct s_room		*next;
}			t_room;

typedef struct		s_sounds
{
  sfMusic		*music;
  sfMusic		*music_back;
  sfMusic		*item_sound;
  sfMusic		*all_item_sound;
  sfMusic		*door;
  sfMusic		*door_not_open;
  sfMusic		*footstep;
  sfMusic		*attack_voice;
  sfMusic		*monster;
  sfMusic		*chara_hit;
}			t_sounds;

typedef struct		s_text
{
  sfText		*to_boss;
  sfText		*to_find;
  sfText		*mission;
  sfText		*kill_boss;
  sfText		*life;
  sfText		*boss_life;
}			t_text;

typedef struct		s_intro
{
  sfText		*text;
  struct s_intro	*next;
}			t_intro;

typedef struct		s_game
{
  t_text		*texts;
  sfFont		*font;
  sfFont		*font2;
  sfClock		*clock;
  t_scroller		*scroller;
  t_enem		*first_enemy;
  t_room		*first_room;
  int			is_finish;
  t_room		*actual_room;
  t_chara		*chara;
  t_pic			*cursor;
  t_pic			*launcher_back;
  t_pic			*launcher_title;
  t_sounds		*sounds;
  t_obj			*first_obj;
  t_boss		*boss;
  t_intro		*first_intro;
  sfRenderWindow	*window;
  sfRenderWindow	*start_window;
}			t_game;

t_game			*load_game();
sfText			*create_text(char *, sfVector2f, int);
void			print_to_search(t_game *);
int			my_error(char *);
int			my_putstr(char *);
char			*get_next_line(int);
char			*my_get_next_line(int);
t_game			*load_game_basic(t_game *, int);
char			**my_str_to_wordtab(char *, char *);
int			my_getnbr(char *);
int			find_separ(char *, char *, int);
char			**malloc_tab(char *, char *);
int			malloc_str(char **, char *, char *);
int			my_tablen(char **);
t_pic			*create_pic(char *, char *);
int			start_game(t_game *);
void			print_cursor(t_pic *, sfRenderWindow *);
int			load_launcher(t_game *);
t_game			*create_window_game(t_game *);
int			load_page(t_game *);
int			my_game(t_game *);
int			load_room(int, t_game *, char *);
t_chara			*load_chara();
void			animation(t_chara *, t_game *);
void			event_key_up_down(t_chara *, t_room *, t_game *);
void			event_key_left_right(t_chara *, t_game *);
int			event_key(t_game *, sfEvent *);
void			event_mouse(t_game *, t_chara *);
int			change_room(t_game *);
sfVector2f		get_middle_window();
int			create_door(int, t_room *);
int			load_objects(int, t_game *);
int			add_rand_obj(t_game *);
int			aff_all(t_game *);
int			aff_obj(t_game *);
int			get_obj(t_game *);
int			is_end(t_game *);
int			load_enemy(int, t_game *, char *);
int			load_boss(int, t_game *, char *);
int			spawn_enemy(t_game *);
char			*my_strcat(char *, char *);
char			*my_itoa(int);
char			*my_strcpy(char *);
int			my_strlen(char *);
t_game			*load_font(t_game *);
int			aff_enemy(t_game *);
int			fight_enemy(t_game *);
int			fight_enemy_bis(t_game *, t_enem *);
int			win_lose(t_game *);
int			aff_boss(t_game *);
int			fight_boss(t_game *);
int			fight_boss_bis(t_game *);
int			aff_instruction(t_game *);
int			my_sleep(int);
int			load_scroller(char **, t_game *);
int			aff_scroller(t_game *);
sfVector2i		convert_from2f_to2i(sfVector2f);
void			event_mouse_left(t_chara *);
void			event_mouse_right(t_chara *);
void			event_mouse_up(t_chara *, t_room *);
void			event_mouse_down(t_chara *, t_room *);
t_game			*add_music(t_game *, char *);
t_game			*add_back_music(t_game *, char *);
t_game			*create_new_room_ter(int , t_game *, t_room *, char **);

#endif /* !TEKAD_H_ */
