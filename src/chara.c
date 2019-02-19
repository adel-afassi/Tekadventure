/*
** chara.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:08:28 2017 Quentin AMARAL
** Last update Sun May 28 20:43:49 2017 Quentin AMARAL
*/

#include "tekad.h"

void	event_key_up_down(t_chara *chara, t_room *room, t_game *game)
{
  int	k;

  k = (WINDOW_HEIGHT - CHARA_HEIGHT * CHARA_SCALE);
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue &&
      chara->pos.y > 0 && chara->pos.y > room->max_move_top)
    {
      chara->pos.y -= CHARA_SPEED;
      chara->rect.top = CHARA_HEIGHT * 3 - chara->sp;
    }
  else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
	   (chara->pos.y < k && chara->pos.y < (k - room->max_move_bot)))
    {
      animation(chara, game);
      chara->pos.y += CHARA_SPEED;
      chara->rect.top = CHARA_HEIGHT * 3 - chara->sp;
    }
}

void	event_key_left_right(t_chara *chara, t_game *game)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
      chara->pos.x > 0)
    {
      chara->pos.x -= CHARA_SPEED;
      chara->sp = LEFT;
      chara->rect.top = CHARA_HEIGHT * 3;
    }
  else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
	   chara->pos.x <
	   (WINDOW_WIDTH - CHARA_WIDTH * CHARA_SCALE))
    {
      chara->rect.top = 0;
      animation(chara, game);
      chara->pos.x += CHARA_SPEED;
      chara->sp = RIGHT;
      chara->rect.top = CHARA_HEIGHT * 2;
    }
}

void		mouvement(t_chara *chara, t_game *game)
{
  static int	i = 0;

  (void)game;
  if (i == NB_OBJS_ON_LINE)
    {
      i = 1;
    }
  chara->rect.left = i * CHARA_WIDTH;
  i += 1;
}

void		animation(t_chara *chara, t_game *game)
{
  sfTime	time;
  sfTime	time_clock;

  (void)game;
  time = sfMilliseconds(150);
  time_clock = sfClock_getElapsedTime(chara->clock);
  if (sfTime_asMilliseconds(time_clock) >=
      sfTime_asMilliseconds(time))
    {
      mouvement(chara, game);
      sfClock_restart(chara->clock);
    }
}
