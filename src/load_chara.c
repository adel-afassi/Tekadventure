/*
** load_chara.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:07:59 2017 Quentin AMARAL
** Last update Sat May 27 11:55:28 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdlib.h>
#include "tekad.h"

sfVector2f	get_middle_window()
{
  sfVector2f	position;

  position.x = (WINDOW_WIDTH - ((SPRITE_WIDTH / NB_OBJS_ON_LINE)
				* CHARA_SCALE)) / 2;
  position.y = (WINDOW_HEIGHT - ((SPRITE_HEIGHT / NB_OBJS_ON_LINE)
				 * CHARA_SCALE)) / 2;
  return (position);
}

t_chara		*load_chara()
{
  t_chara	*chara;

  if ((chara = malloc(sizeof(t_chara))) == NULL)
    return (NULL);
  if ((chara->texture =
       sfTexture_createFromFile("assets/img/chara.png", NULL)) == NULL)
    return (NULL);
  if ((chara->sprite = sfSprite_create()) == NULL)
    return (NULL);
  chara->scale.x = CHARA_SCALE;
  chara->scale.y = CHARA_SCALE;
  sfSprite_setScale(chara->sprite, chara->scale);
  chara->clock = sfClock_create();
  chara->pos = get_middle_window();
  chara->rect.top = 0;
  chara->rect.left = 0;
  chara->life = 100;
  chara->rect.width = CHARA_WIDTH;
  chara->rect.height = CHARA_HEIGHT;
  sfSprite_setTexture(chara->sprite, chara->texture, sfTrue);
  sfSprite_setTextureRect(chara->sprite, chara->rect);
  sfSprite_setPosition(chara->sprite, chara->pos);
  return (chara);
}
