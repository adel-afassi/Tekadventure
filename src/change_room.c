/*
** change_room.c for  in /home/Quentss/Work/graphic/tekadventure_tmp/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 12:04:35 2017 Quentin AMARAL
** Last update Sun May 28 18:09:37 2017 Quentin AMARAL
*/

#include <stdio.h>
#include "tekad.h"

int	is_on_door(t_game *game)
{
  int	ok;
  int	max_x;
  int	min_x;
  int	max_y;
  int	min_y;
  int	pos_x;
  int	pos_y;

  ok = 0;
  pos_x = game->chara->pos.x;
  pos_y = game->chara->pos.y;
  max_x = game->actual_room->door->max_x;
  min_x = game->actual_room->door->min_x;
  max_y = game->actual_room->door->max_y;
  min_y = game->actual_room->door->min_y;
  if (pos_x < max_x && pos_x > min_x)
    ok = 1;
  if (ok == 1 && pos_y < max_y && pos_y > min_y)
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
}

int	change_actual_room_bis(int where, t_game *game)
{
  int	can_open;

  if (game->actual_room->door_room != NULL &&
      game->actual_room->door_room->is_final == 0)
    can_open = 1;
  else if (is_end(game) == EXIT_SUCCESS)
    can_open = 1;
  if (where == 4)
    {
      if (can_open == 1)
	{
	  sfMusic_play(game->sounds->door);
	  game->actual_room = game->actual_room->door_room;
	  game->chara->pos = get_middle_window();
	  if (game->actual_room->is_final == 1)
	    game->chara->pos.y = (WINDOW_HEIGHT - CHARA_HEIGHT * CHARA_SCALE) - 20;
	  else
	    return (spawn_enemy(game));
	}
      else
	sfMusic_play(game->sounds->door_not_open);
    }
  return (EXIT_SUCCESS);
}

int	change_actual_room(int where, t_game *game)
{
  if (game->actual_room->enemy != NULL)
    return (EXIT_SUCCESS);
  if (where == 1)
    {
      game->actual_room = game->actual_room->left_room;
      game->chara->pos.x = WINDOW_WIDTH -
	((SPRITE_WIDTH / NB_OBJS_ON_LINE) * CHARA_SCALE) - 35;
      return (spawn_enemy(game));
    }
  else if (where == 2)
    {
      game->actual_room = game->actual_room->right_room;
      game->chara->pos.x = 35;
      return (spawn_enemy(game));
    }
  else if (where == 3)
    {
      game->actual_room = game->actual_room->bot_room;
      game->chara->pos.y = WINDOW_HEIGHT / 2;
      sfMusic_play(game->sounds->door);
      return (spawn_enemy(game));
    }
  return (change_actual_room_bis(where, game));
}

int	change_room(t_game *game)
{
  int	k;
  int	j;

  j = (WINDOW_HEIGHT - CHARA_HEIGHT * CHARA_SCALE) - 10;
  k = WINDOW_WIDTH - ((SPRITE_WIDTH / NB_OBJS_ON_LINE) * CHARA_SCALE);
  if (game->chara->pos.x < 30 && game->actual_room->left_room != NULL)
    change_actual_room(1, game);
  else if (game->chara->pos.x > k - 30 && game->actual_room->right_room != NULL)
    change_actual_room(2, game);
  else if (game->chara->pos.y > j && game->actual_room->bot_room != NULL)
    change_actual_room(3, game);
  else if (game->actual_room->door != NULL && is_on_door(game) == EXIT_SUCCESS)
    change_actual_room(4, game);
  return (EXIT_SUCCESS);
}
