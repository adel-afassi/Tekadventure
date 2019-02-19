/*
** lose_win.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 15:02:01 2017 Quentin AMARAL
** Last update Sun May 28 18:08:15 2017 Quentin AMARAL
*/

#include "tekad.h"

int		lose_win_h(t_game *game, sfText *text)
{
  sfText_setFont(game->texts->to_boss, game->font2);
  sfRenderWindow_clear(game->window, sfBlack);
  sfRenderWindow_drawText(game->window, text, NULL);
  sfMusic_stop(game->sounds->music);
  sfRenderWindow_display(game->window);
  my_sleep(2);
  return (EXIT_SUCCESS);
}

int		win(t_game *game)
{
  sfText	*text;
  sfClock	*clock;
  sfTime	time_clock;
  sfTime	time;

  if (game->boss->life <= 0)
    {
      clock = sfClock_create();
      time = sfSeconds(WIN_LOSE_TIME);
      if ((text = create_text("YOU WIN!!", (sfVector2f){340, 320}, 60)) == NULL)
	return (EXIT_ERROR);
      lose_win_h(game, text);
      while (sfTime_asMilliseconds(time_clock) <
	     sfTime_asMilliseconds(time))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue ||
	      sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	    break ;
	  time_clock = sfClock_getElapsedTime(clock);
	}
      return (EXIT_SUCCESS);
    }
  return (EXIT_ERROR);
}

int		lose(t_game *game)
{
  sfText	*text;
  sfClock	*clock;
  sfTime	time_clock;
  sfTime	time;

  if (game->chara->life <= 0)
    {
      clock = sfClock_create();
      time = sfSeconds(WIN_LOSE_TIME);
      if (!(text = create_text("YOU LOSE!!", (sfVector2f){330, 320}, 60)))
	return (EXIT_ERROR);
      lose_win_h(game, text);
      while (sfTime_asMilliseconds(time_clock) <
	     sfTime_asMilliseconds(time))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue ||
	      sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	    break ;
	  time_clock = sfClock_getElapsedTime(clock);
	}
      return (EXIT_SUCCESS);
    }
  return (EXIT_ERROR);
}

int	win_lose(t_game *game)
{
  if (win(game) == EXIT_SUCCESS)
    return (EXIT_SUCCESS);
  if (lose(game) == EXIT_SUCCESS)
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
}
