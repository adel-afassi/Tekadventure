/*
** my_game.c for  in /home/yoann/Documents/EPITECH/2017/Infographie/Tekadventure/tekadventure/src
** 
** Made by Yoann
** Login   <yoann.sarkissian@epitech.eu>
** 
** Started on  Sun May 28 14:17:34 2017 Yoann
** Last update Sun May 28 20:45:47 2017 Quentin AMARAL
*/

#include <stdio.h>
#include "tekad.h"

int		is_end(t_game *game)
{
  t_obj		*obj;

  obj = game->first_obj;
  while (obj->next != NULL)
    obj = obj->next;
  if (obj->is_find == 1)
    return (EXIT_SUCCESS);
  else
    return (EXIT_ERROR);
}

int	aff_all(t_game *game)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setScale(game->chara->sprite, game->chara->scale);
  animation(game->chara, game);
  sfSprite_setTextureRect(game->chara->sprite, game->chara->rect);
  sfRenderWindow_drawSprite(game->window, game->actual_room->back->sprite,
			    NULL);
  if (game->actual_room->enemy != NULL)
    aff_enemy(game);
  aff_obj(game);
  if (game->actual_room->is_final == 1)
    aff_boss(game);
  sfRenderWindow_drawSprite(game->window, game->chara->sprite, NULL);
  print_to_search(game);
  print_cursor(game->cursor, game->window);
  sfRenderWindow_display(game->window);
  return (EXIT_SUCCESS);
}

int	event_key(t_game *game, sfEvent *event)
{
  game->chara->in_movement = 0;
  if (event->type == sfEvtKeyPressed)
    {
      game->chara->pos_mouse = convert_from2f_to2i(game->chara->pos);
      game->chara->in_movement = 1;
      event_key_up_down(game->chara, game->actual_room, game);
      event_key_left_right(game->chara, game);
    }
  if (event->type == sfEvtKeyReleased)
    {
      game->chara->in_movement = 0;
      game->chara->rect.top = 0 + (game->chara->sp * CHARA_HEIGHT);
    }
  if (game->actual_room->enemy != NULL)
    if (fight_enemy(game) == EXIT_ERROR)
      return (EXIT_ERROR);
  if (game->actual_room->is_final == 1)
    if (fight_boss(game) == EXIT_ERROR)
      return (EXIT_ERROR);
  sfSprite_setPosition(game->chara->sprite, game->chara->pos);
  return (EXIT_SUCCESS);
}

int	my_game(t_game *game)
{
  if (change_room(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  if (get_obj(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  if (game->actual_room->is_final == 1)
    if (fight_boss_bis(game) == EXIT_ERROR)
      return (EXIT_ERROR);
  if (game->actual_room->enemy != NULL
      && fight_enemy_bis(game, game->actual_room->enemy) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((game->chara->pos.x + (CHARA_WIDTH / 2) != game->chara->pos_mouse.x) ||
      (game->chara->pos.y + (CHARA_HEIGHT / 2) != game->chara->pos_mouse.y))
    {
      game->chara->in_movement = 1;
      event_mouse_left(game->chara);
      event_mouse_right(game->chara);
      event_mouse_up(game->chara, game->actual_room);
      event_mouse_down(game->chara, game->actual_room);
    }
  else
    {
      game->chara->in_movement = 0;
      game->chara->rect.top = 0 + (game->chara->sp * CHARA_HEIGHT);
    }
  return (aff_all(game));
}
