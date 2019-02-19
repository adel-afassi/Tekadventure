/*
** event_mouse.c for event_mouse in /home/yoann/Documents/EPITECH/2017/Infographie/Tekadventure/tekadventure/src
** 
** Made by Yoann
** Login   <yoann.sarkissian@epitech.eu>
** 
** Started on  Sat May 27 15:04:06 2017 Yoann
** Last update Sun May 28 17:43:05 2017 Quentin AMARAL
*/

#include "tekad.h"

void	event_mouse_left(t_chara *chara)
{
  if (chara->pos.x > (chara->pos_mouse.x + CHARA_WIDTH / 2) && chara->pos.x > 0)
    {
      chara->pos.x -= 0.2;
      chara->sp = LEFT;
      chara->rect.top = CHARA_HEIGHT * 3;
      sfSprite_setPosition(chara->sprite, chara->pos);
    }
}

void	event_mouse_right(t_chara *chara)
{
  if (chara->pos.x < (chara->pos_mouse.x - CHARA_WIDTH / 2) &&
      chara->pos.x < (WINDOW_WIDTH - CHARA_WIDTH * CHARA_SCALE))
    {
      chara->pos.x += 0.2;
      chara->sp = RIGHT;
      chara->rect.top = CHARA_HEIGHT * 2;
      sfSprite_setPosition(chara->sprite, chara->pos);
    }
}

void	event_mouse_up(t_chara *chara, t_room *room)
{
  if (chara->pos.y > (chara->pos_mouse.y + CHARA_HEIGHT / 2) &&
      chara->pos.y > 0 && chara->pos.y > room->max_move_top)
    {
      chara->pos.y -= 0.2;
      chara->rect.top = CHARA_HEIGHT * (2 + chara->sp);
      sfSprite_setPosition(chara->sprite, chara->pos);
    }
}

void	event_mouse_down(t_chara *chara, t_room *room)
{
  int	k;

  k = (WINDOW_HEIGHT - CHARA_HEIGHT * CHARA_SCALE);
  if (chara->pos.y < (chara->pos_mouse.y - CHARA_HEIGHT / 2) &&
      (chara->pos.y < k && chara->pos.y < (k - room->max_move_bot)))
    {
      chara->pos.y += 0.2;
      chara->rect.top = CHARA_HEIGHT * (2 + chara->sp);
      sfSprite_setPosition(chara->sprite, chara->pos);
    }
}
