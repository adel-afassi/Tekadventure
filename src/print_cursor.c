/*
** print_cursor.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 19:03:30 2017 Quentin AMARAL
** Last update Sun May 28 19:03:31 2017 Quentin AMARAL
*/

#include <SFML/Window.h>
#include "tekad.h"

sfVector2f	convert_from2i_to2f(sfVector2i vector)
{
  sfVector2f	vect2;

  vect2.x = (float)vector.x;
  vect2.y = (float)vector.y;
  return (vect2);
}

sfVector2i	convert_from2f_to2i(sfVector2f vector)
{
  sfVector2i	vect2;

  vect2.x = (unsigned int)vector.x;
  vect2.y = (unsigned int)vector.y;
  return (vect2);
}

sfVector2f	convert_from2u_to2f(sfVector2u vector)
{
  sfVector2f	vect2;

  vect2.x = (float)vector.x;
  vect2.y = (float)vector.y;
  return (vect2);
}

void	print_cursor(t_pic *pic, sfRenderWindow *window)
{
  pic->scale.x = 0.1;
  pic->scale.y = 0.1;
  sfSprite_setScale(pic->sprite, pic->scale);
  sfSprite_setPosition(pic->sprite,
		       convert_from2i_to2f(sfMouse_getPositionRenderWindow(window)));
  sfRenderWindow_drawSprite(window, pic->sprite, NULL);
}
