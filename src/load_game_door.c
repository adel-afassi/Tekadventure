/*
** load_game_door.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 14:38:19 2017 Quentin AMARAL
** Last update Sun May 28 21:43:49 2017 adel
*/

#include <stdlib.h>
#include "tekad.h"

t_door		*create_new_door(char **tab)
{
  t_door	*door;

  if ((door = malloc(sizeof(t_door))) == NULL)
    return (NULL);
  door->max_x = my_getnbr(tab[0]);
  door->min_x = my_getnbr(tab[1]);
  door->max_y = my_getnbr(tab[2]);
  door->min_y = my_getnbr(tab[3]);
  if (door->max_x == -1 || door->min_x == -1
      || door->max_y == -1 || door->min_y == -1)
    {
      my_error("One of the room have non integer number as a door coordonate");
      my_error("\n");
      return (NULL);
    }
  return (door);
}

int	create_door(int fd, t_room *room)
{
  char	*s;
  char	**tab;

  if (room->door_room_int == 0)
    return (EXIT_SUCCESS);
  if ((s = my_get_next_line(fd)) == NULL)
    {
      my_error(ERR_MISSING_DOOR);
      return (EXIT_ERROR);
    }
  if ((tab = my_str_to_wordtab(s, ":")) == NULL)
    return (EXIT_ERROR);
  if (my_tablen(tab) != 4)
    {
      my_error(ERR_MISSING_DOOR);
      return (EXIT_ERROR);
    }
  if ((room->door = create_new_door(tab)) == NULL)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
