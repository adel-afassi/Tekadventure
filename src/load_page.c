/*
** load_page.c for  in /home/Quentss/Work/graphic/tekadventure_tmp/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 00:52:40 2017 Quentin AMARAL
** Last update Sun May 28 18:01:46 2017 adel
*/

#include "tekad.h"

int			create_window_launcher(t_game *game)
{
  sfRenderWindow	*start_window;
  sfVideoMode		start_mode = {1024, 720, 32};

  start_window = sfRenderWindow_create(start_mode, "Launcher - TekAdventure",
				       sfResize | sfClose, NULL);
  if (start_window == NULL)
    {
      my_error("Can't load game window...\n");
      return (EXIT_ERROR);
    }
  game->start_window = start_window;
  return (EXIT_SUCCESS);
}

int	create_elements_launcher(t_game *game)
{
  game->launcher_back = create_pic("forest", "assets/bg/forest.png");
  game->launcher_title = create_pic("title", "assets/bg/title.png");
  game->is_finish = 0;
  sfRenderWindow_setMouseCursorVisible(game->start_window, sfFalse);
  return (EXIT_SUCCESS);
}

sfText		*create_text_load_page()
{
  sfText	*text;
  sfFont	*font;
  sfVector2f	position;

  position.x = 160;
  position.y = 550;
  if ((font = sfFont_createFromFile("assets/fonts/horrendo.ttf")) == NULL)
    return (NULL);
  text = sfText_create();
  sfText_setString(text, "LOADING...");
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 60);
  sfText_setPosition(text, position);
  return (text);
}

int		load_page(t_game *game)
{
  sfText	*text;

  if ((text = create_text_load_page()) == NULL)
    return (EXIT_ERROR);
  if (create_window_launcher(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  if (create_elements_launcher(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  sfRenderWindow_drawText(game->start_window, text, NULL);
  return (EXIT_SUCCESS);
}
