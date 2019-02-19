/*
** main.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:07:40 2017 Quentin AMARAL
** Last update Sun May 28 21:33:00 2017 adel
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "tekad.h"

int	destroy_game(t_game *game)
{
  my_putstr(EXITING);
  sfRenderWindow_destroy(game->window);
  sfMusic_destroy(game->sounds->music);
  sfMusic_destroy(game->sounds->item_sound);
  sfMusic_destroy(game->sounds->door);
  sfMusic_destroy(game->sounds->door_not_open);
  sfMusic_destroy(game->sounds->all_item_sound);
  sfMusic_destroy(game->sounds->attack_voice);
  sfMusic_destroy(game->sounds->footstep);
  sfMusic_destroy(game->sounds->chara_hit);
  sfMusic_destroy(game->sounds->monster);
  my_putstr("Exit\n");
  return (EXIT_SUCCESS);
}

int		main(void)
{
  t_game	*game;
  int		ret;

  srand(time(0));
  if ((game = load_game()) == NULL)
    return (EXIT_ERROR);
  my_putstr(LAUNCHER);
  sfMusic_play(game->sounds->music_back);
  sfMusic_setLoop(game->sounds->music_back, 1);
  if (load_page(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((ret = load_launcher(game)) == EXIT_ERROR)
    return (EXIT_ERROR);
  sfMusic_pause(game->sounds->music_back);
  if (ret == EXIT_SUCCESS)
    {
      sfRenderWindow_close(game->start_window);
      sfRenderWindow_destroy(game->start_window);
      sfMusic_destroy(game->sounds->music_back);
      my_putstr(PLAY);
      if (start_game(game) == EXIT_ERROR)
	return (EXIT_ERROR);
    }
  return (destroy_game(game));
}
