/*
** aff_instruction.c for  in /home/youcef/delivery/MUL/tekadventure
** 
** Made by Youcef
** Login   <youcef.chergui@epitech.eu>
** 
** Started on  Sun May 28 21:08:16 2017 Youcef
** Last update Sun May 28 17:41:41 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include "tekad.h"

int		add_text(t_game *game, char *str)
{
  t_intro	*text;
  t_intro	*previous;
  int		pos_y;
  sfVector2f	pos;

  if ((text = malloc(sizeof(t_intro))) == NULL)
    return (EXIT_ERROR);
  previous = game->first_intro;
  pos_y = 40;
  if (previous == NULL)
    game->first_intro = text;
  else
    {
      while (previous->next != NULL)
	previous = previous->next;
      previous->next = text;
      pos = sfText_getPosition(previous->text);
      pos_y = pos.y + 45;
    }
  text->next = NULL;
  if ((text->text = create_text(str, (sfVector2f){50, pos_y}, 35)) == NULL)
    return (EXIT_ERROR);
  sfText_setFont(text->text, game->font2);
  return (EXIT_SUCCESS);
}

int	load_intro_bis(t_game *game, int type, int i, char **tab)
{
  if (type == 2 && i == 0)
    return (EXIT_ERROR);
  if (type == 1 && load_scroller(tab, game) == EXIT_ERROR)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

int	load_intro(t_game *game)
{
  int	fd;
  char	*str;
  int	type;
  char	**tab;
  int	i;

  type = 1;
  i = 0;
  if ((fd = open(INTRO_FILE, O_RDWR)) == -1)
    return (EXIT_ERROR);
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((tab = my_str_to_wordtab(str, ":")) == NULL)
	return (EXIT_ERROR);
      if (my_tablen(tab) == 1 && type == 1)
	type = 2;
      else if (my_tablen(tab) != 3 && type == 1)
	return (EXIT_ERROR);
      if (load_intro_bis(game, type, i, tab) == EXIT_ERROR)
	return (EXIT_ERROR);
      if (type == 2 && add_text(game, str) == EXIT_ERROR)
	return (EXIT_ERROR);
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int		display_inst(t_game *game)
{
  t_intro	*intro;

  intro = game->first_intro;
  sfRenderWindow_clear(game->window, sfBlack);
  aff_scroller(game);
  while (intro != NULL)
    {
      sfRenderWindow_drawText(game->window, intro->text, NULL);
      intro = intro->next;
    }
  sfRenderWindow_display(game->window);
  return (EXIT_SUCCESS);
}

int		aff_instruction(t_game *game)
{
  sfEvent	event;

  if (load_intro(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  display_inst(game);
  my_sleep(0.1);
  while (sfRenderWindow_isOpen(game->window))
    {
      while (sfRenderWindow_pollEvent(game->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    {
	      sfRenderWindow_close(game->window);
	      return (1);
	    }
	  else if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	    return (EXIT_SUCCESS);
	}
      display_inst(game);
    }
  return (1);
}
