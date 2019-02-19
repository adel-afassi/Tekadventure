/*
** load_launcher.c for  in /home/youcef/delivery/MUL/tekadventure
** 
** Made by Youcef
** Login   <youcef.chergui@epitech.eu>
** 
** Started on  Tue May 23 21:37:15 2017 Youcef
** Last update Sun May 28 17:50:56 2017 adel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SFML/Window.h>
#include "tekad.h"

void	move_sprite(t_pic *pic, sfVector2f pos)
{
  pic->position.x = pos.x;
  pic->position.y = pos.y;
  sfSprite_setPosition(pic->sprite, pos);
  return ;
}

sfVector2u	get_sprite_size(t_pic *pic)
{
  sfVector2u	size;

  size.x = 0;
  size.y = 0;
  size = pic->size;
  return (size);
}

int	aff_sprite_launcher(t_game *g, sfText *text)
{
  sfRenderWindow_clear(g->start_window, sfBlack);
  sfRenderWindow_drawSprite(g->start_window, g->launcher_back->sprite, NULL);
  sfRenderWindow_drawSprite(g->start_window, g->launcher_title->sprite, NULL);
  print_cursor(g->cursor, g->start_window);
  sfRenderWindow_drawText(g->start_window, text, NULL);
  sfRenderWindow_display(g->start_window);
  return (EXIT_SUCCESS);
}

sfText		*create_text(char *string, sfVector2f position, int size)
{
  sfText	*text;
  sfFont	*font;

  if ((font = sfFont_createFromFile("assets/fonts/horrendo.ttf")) == NULL)
    return (NULL);
  text = sfText_create();
  sfText_setString(text, string);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, size);
  sfText_setPosition(text, position);
  return (text);
}

int		load_launcher(t_game *game)
{
  sfEvent	event;
  sfText	*text;

  if ((text = create_text("Press space to start",
			  (sfVector2f){200, 500}, 60)) == NULL)
    return (EXIT_ERROR);
  while (sfRenderWindow_isOpen(game->start_window))
    {
      while (sfRenderWindow_pollEvent(game->start_window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    {
	      sfRenderWindow_close(game->start_window);
	      return (1);
	    }
	  else if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	    return (EXIT_SUCCESS);
	}
      aff_sprite_launcher(game, text);
    }
  return (EXIT_SUCCESS);
}
