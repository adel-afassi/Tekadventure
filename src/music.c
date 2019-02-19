/*
** music.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 19:04:30 2017 Quentin AMARAL
** Last update Sun May 28 19:04:31 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

t_game	*add_music(t_game *game, char *str)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(str, ":")) == NULL)
    return (NULL);
  if (my_tablen(tab) != 2)
    {
      my_error("Wrong number of arg for music line\n");
      return (NULL);
    }
  if ((game->sounds->music = sfMusic_createFromFile(tab[1])) == NULL)
    {
      my_error("Can't load the music file...\n");
      return (NULL);
    }
  sfMusic_setVolume(game->sounds->music, 40);
  return (game);
}

t_game	*add_back_music(t_game *game, char *str)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(str, ":")) == NULL)
    return (NULL);
  if (my_tablen(tab) != 2)
    {
      my_error("Wrong number of arg for back music line\n");
      return (NULL);
    }
  if ((game->sounds->music_back = sfMusic_createFromFile(tab[1])) == NULL)
    {
      my_error("Can't load the back music file...\n");
      return (NULL);
    }
  return (game);
}
