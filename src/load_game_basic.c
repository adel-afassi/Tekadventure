/*
** load_game_basic.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 19:04:58 2017 Quentin AMARAL
** Last update Sun May 28 19:04:59 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

t_game	*add_cursor(t_game *game, char *str)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(str, ":")) == NULL)
    return (NULL);
  if (my_tablen(tab) != 2)
    {
      my_error("Wrong number of arg for cursor line\n");
      return (NULL);
    }
  if ((game->cursor = create_pic("cursor", tab[1])) == NULL)
    return (NULL);
  return (game);
}

t_game	*choose_what_elem(t_game *game, char *str)
{
  if (str[0] == '0')
    return (add_cursor(game, str));
  else if (str[0] == '1')
    return (add_music(game, str));
  else if (str[0] == '2')
    return (add_back_music(game, str));
  else
    {
      my_error("Element [");
      my_error(str);
      my_error("] is not an expected asset\n");
      return (NULL);
    }
}

int	verif_fill(t_game *game)
{
  if (game->sounds->music == NULL)
    {
      my_error("Missing music in your conf file...\n");
      return (EXIT_ERROR);
    }
  if (game->cursor == NULL)
    {
      my_error("Missing cursor in your conf file...\n");
      return (EXIT_ERROR);
    }
  if (game->sounds->music_back == NULL)
    {
      my_error("Missing back music in your conf file...\n");
      return (EXIT_ERROR);
    }
  return (EXIT_SUCCESS);
}

t_game	*load_game_basic(t_game *game, int fd)
{
  char	*s;
  int	i;

  i = 0;
  game->first_obj = NULL;
  game->cursor = NULL;
  game->sounds->music = NULL;
  game->sounds->music_back = NULL;
  while (i != 3)
    {
      if ((s = my_get_next_line(fd)) == NULL)
	{
	  my_error("Your conf file need more info to load the game...\n");
	  return (NULL);
	}
      if ((game = choose_what_elem(game, s)) == NULL)
	return (NULL);
      free(s);
      i += 1;
    }
  if (verif_fill(game) == EXIT_ERROR)
    return (NULL);
  return (game);
}
