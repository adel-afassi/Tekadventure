/*
** print_to_search.c for  in /home/youcef/delivery/MUL/tekadventure
** 
** Made by Youcef
** Login   <youcef.chergui@epitech.eu>
** 
** Started on  Sat May 27 05:29:59 2017 Youcef
** Last update Sun May 28 19:03:59 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <stdio.h>
#include "tekad.h"

int	print_life(t_game *game)
{
  char	*life;

  life = "Life: ";
  if ((life = my_strcat(life, my_itoa(game->chara->life))) == NULL)
    return (EXIT_ERROR);
  if ((life = my_strcat(life, "%")) == NULL)
    return (EXIT_ERROR);
  sfText_setString(game->texts->life, life);
  sfRenderWindow_drawText(game->window, game->texts->life, NULL);
  free(life);
  return (EXIT_SUCCESS);
}

void	print_texts(t_game *game, t_obj *obj)
{
  if (obj == NULL && game->actual_room->is_final == 0)
    sfRenderWindow_drawText(game->window, game->texts->to_boss, NULL);
  else if (game->actual_room->is_final == 1)
    sfRenderWindow_drawText(game->window, game->texts->kill_boss, NULL);
}

void	print_to_search(t_game *game)
{
  t_obj	*obj;

  obj = game->first_obj;
  if (print_life(game) == EXIT_ERROR)
    return ;
  sfRenderWindow_drawText(game->window, game->texts->mission, NULL);
  while (obj != NULL)
    {
      if (obj->is_find == 1)
	obj = obj->next;
      else if (obj != NULL)
	{
	  sfSprite_setPosition(obj->pic_inv->sprite, (sfVector2f){335, 65});
	  sfRenderWindow_drawSprite(game->window, obj->pic_inv->sprite, NULL);
	  sfRenderWindow_drawText(game->window, game->texts->to_find, NULL);
	  return ;
	}
    }
  print_texts(game, obj);
}
