/*
** objects.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 19:13:25 2017 Quentin AMARAL
** Last update Sun May 28 17:57:36 2017 adel
*/

#include <stdio.h>
#include "tekad.h"

int		aff_obj(t_game *game)
{
  t_obj		*obj;

  obj = game->first_obj;
  while (obj != NULL && obj->is_find == 1)
    obj = obj->next;
  if (obj == NULL)
    return (EXIT_SUCCESS);
  if (obj->id_room == game->actual_room->id)
    {
      sfSprite_setScale(obj->pic_obj->sprite, obj->scale);
      sfSprite_setPosition(obj->pic_obj->sprite, obj->pos);
      sfRenderWindow_drawSprite(game->window, obj->pic_obj->sprite, NULL);
      return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}

int	is_on_obj(t_game *game, t_obj *obj)
{
  int	ok;
  int	chara_x;
  int	chara_y;
  int	obj_x;
  int	obj_y;

  ok = 0;
  chara_x = game->chara->pos.x;
  chara_y = game->chara->pos.y + (CHARA_HEIGHT / 2);
  obj_x = obj->pos.x;
  obj_y = obj->pos.y;
  if (chara_x < obj_x + 60 && chara_x > obj_x - 60)
    ok = 1;
  if (ok == 1 && chara_y < obj_y + 100 && chara_y > obj_y - 100)
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
}

int	get_obj(t_game *game)
{
  t_obj	*obj;

  obj = game->first_obj;
  while (obj != NULL && obj->is_find == 1)
    obj = obj->next;
  if (obj == NULL)
    return (EXIT_SUCCESS);
  if (obj->id_room != game->actual_room->id)
    return (EXIT_SUCCESS);
  if (is_on_obj(game, obj) == EXIT_ERROR)
    return (EXIT_SUCCESS);
  obj->is_find = 1;
  if (obj->next == NULL)
    sfMusic_play(game->sounds->all_item_sound);
  else
    sfMusic_play(game->sounds->item_sound);
  return (EXIT_SUCCESS);
}
