/*
** load_game_window.c for  in /home/Quentss/Work/graphic/tekadventure_tmp/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Thu May 25 23:33:05 2017 Quentin AMARAL
** Last update Sun May 28 17:48:06 2017 adel
*/

#include "tekad.h"

t_game		*create_window_game(t_game *game)
{
  sfVideoMode	mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

  game->window = sfRenderWindow_create(mode, TEK, sfResize | sfClose, NULL);
  sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
  return (game);
}
