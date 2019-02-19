/*
** aff_scroller.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 19:05:12 2017 Quentin AMARAL
** Last update Sun May 28 19:05:12 2017 Quentin AMARAL
*/

#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

int		aff_scroller(t_game *game)
{
  sfFloatRect	dim;
  sfVector2f	pos1;
  sfVector2f	pos2;
  double	speed;

  speed = (float)(game->scroller->speed) / 100;
  dim = sfSprite_getGlobalBounds(game->scroller->pic1->sprite);
  pos1 = sfSprite_getPosition(game->scroller->pic1->sprite);
  pos2 = sfSprite_getPosition(game->scroller->pic2->sprite);
  if (pos1.x + dim.width <= 0)
    pos1.x = dim.width - 5;
  if (pos2.x + dim.width <= 0)
    pos2.x = dim.width - 5;
  pos1.x = pos1.x - speed;
  pos2.x = pos2.x - speed;
  sfSprite_setPosition(game->scroller->pic1->sprite, pos1);
  sfSprite_setPosition(game->scroller->pic2->sprite, pos2);
  sfRenderWindow_drawSprite(game->window, game->scroller->pic1->sprite, NULL);
  sfRenderWindow_drawSprite(game->window, game->scroller->pic2->sprite, NULL);
  return (EXIT_SUCCESS);
}

int		create_scroller(char **tab, t_scroller *scroller)
{
  sfFloatRect	dim;
  sfVector2f	pos;

  if ((scroller->pic1 = create_pic("scroller 1", tab[0])) == NULL)
    return (EXIT_ERROR);
  if ((scroller->pic2 = create_pic("scroller 2", tab[0])) == NULL)
    return (EXIT_ERROR);
  dim = sfSprite_getGlobalBounds(scroller->pic1->sprite);
  if ((scroller->speed = my_getnbr(tab[1])) == -1)
    return (EXIT_ERROR);
  if ((pos.y = my_getnbr(tab[2])) == -1)
    return (EXIT_ERROR);
  pos.x = 0;
  sfSprite_setPosition(scroller->pic1->sprite, pos);
  pos.x = dim.width - 5;
  sfSprite_setPosition(scroller->pic2->sprite, pos);
  free(tab);
  return (EXIT_SUCCESS);
}

int		load_scroller(char **tab, t_game *game)
{
  t_scroller	*scroller;
  t_scroller	*previous;

  if ((scroller = malloc(sizeof(t_scroller))) == NULL)
    return (EXIT_ERROR);
  previous = game->scroller;
  if (previous == NULL)
    game->scroller = scroller;
  else
    {
      while (previous->next != NULL)
	previous = previous->next;
      previous->next = scroller;
    }
  if (create_scroller(tab, scroller) == EXIT_ERROR)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
