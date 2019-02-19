/*
** start_game.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:07:05 2017 Quentin AMARAL
** Last update Sun May 28 17:36:20 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdio.h>
#include "tekad.h"

int		play_game(t_game *game)
{
  sfEvent	event;

  game->chara->pos_mouse = convert_from2f_to2i(game->chara->pos);
  while (sfRenderWindow_isOpen(game->window))
    {
      while (sfRenderWindow_pollEvent(game->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(game->window);
	  if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
	    game->chara->pos_mouse = sfMouse_getPositionRenderWindow(game->window);
	  event_key(game, &event);
	}
      if (my_game(game) == EXIT_ERROR)
	{
	  sfRenderWindow_close(game->window);
	  return (EXIT_ERROR);
	}
      if (win_lose(game) == EXIT_SUCCESS)
	sfRenderWindow_close(game->window);
    }
  return (EXIT_SUCCESS);
}

int	load_texts(t_game *game)
{
  if ((game->texts->mission = create_text("Mission:",
					  (sfVector2f){25, 10}, 60)) == NULL)
    return (EXIT_ERROR);
  if ((game->texts->to_boss = create_text("- Go to boss room !",
					  (sfVector2f){50, 80}, 40)) == NULL)
    return (EXIT_ERROR);
  if ((game->texts->to_find = create_text("- Find this object: ",
					  (sfVector2f){50, 80}, 40)) == NULL)
    return (EXIT_ERROR);
  if ((game->texts->kill_boss = create_text("- Kill the boss !! ",
					  (sfVector2f){50, 80}, 40)) == NULL)
    return (EXIT_ERROR);
  game = load_font(game);
  return (EXIT_SUCCESS);
}

int	start_game(t_game *game)
{
  int	value;

  if (create_window_game(game) == NULL)
    return (EXIT_ERROR);
  if (load_texts(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  sfMusic_play(game->sounds->music);
  sfMusic_setLoop(game->sounds->music, 1);
  value = aff_instruction(game);
  if (value == EXIT_ERROR)
    return (EXIT_ERROR);
  else if (value == 1)
    return (EXIT_SUCCESS);
  if (play_game(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
