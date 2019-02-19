/*
** load_room.c for  in /home/Quentss/Work/graphic/tekadventure_tmp/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 09:03:58 2017 Quentin AMARAL
** Last update Sun May 28 21:41:31 2017 adel
*/

#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

t_game	*create_new_room_bis(int fd, t_game *game, t_room *room, char **tab)
{
  room->next = NULL;
  room->is_final = 0;
  room->enemy = NULL;
  if ((room->back = create_pic("a room", tab[0])) == NULL)
    {
      my_error("Can't load a room background..\n");
      return (NULL);
    }
  if ((room->max_move_top = my_getnbr(tab[1])) == -1)
    return (NULL);
  if ((room->max_move_bot = my_getnbr(tab[2])) == -1)
    return (NULL);
  room->left_room = NULL;
  if ((room->left_room_int = my_getnbr(tab[3])) == -1)
    return (NULL);
  room->right_room = NULL;
  if ((room->right_room_int = my_getnbr(tab[4])) == -1)
    return (NULL);
  room->bot_room = NULL;
  return (create_new_room_ter(fd, game, room, tab));
}

t_game		*create_new_room(int fd, t_game *game, char **tab)
{
  t_room	*room;
  t_room	*previous;

  if ((room = malloc(sizeof(t_room))) == NULL)
    return (NULL);
  if (game->actual_room == NULL)
    {
      game->actual_room = room;
      room->id = 1;
    }
  else
    {
      previous = game->actual_room;
      while (previous->next != NULL)
	previous = previous->next;
      previous->next = room;
      room->id = previous->id + 1;
    }
  room->door = NULL;
  return (create_new_room_bis(fd, game, room, tab));
}

t_room		*room_int_to_ptr(t_game *game, int id_room)
{
  t_room	*room;

  room = game->actual_room;
  while (room != NULL)
    {
      if (room->id == id_room)
	return (room);
      room = room->next;
    }
  return (room);
}

int		link_room_ptr(t_game *game)
{
  t_room	*room;

  if ((room = game->actual_room) == NULL)
    {
      my_error("Error: no room to start...\n");
      return (EXIT_ERROR);
    }
  while (room->next != NULL)
    {
      room->left_room = room_int_to_ptr(game, room->left_room_int);
      room->right_room = room_int_to_ptr(game, room->right_room_int);
      room->bot_room = room_int_to_ptr(game, room->bot_room_int);
      room->door_room = room_int_to_ptr(game, room->door_room_int);
      room = room->next;
    }
  return (EXIT_SUCCESS);
}

int	load_room(int fd, t_game *game, char *s)
{
  char	**tab;

  while (s != NULL)
    {
      if ((tab = my_str_to_wordtab(s, ":")) == NULL)
	return (EXIT_ERROR);
      free(s);
      if (my_tablen(tab) != 8)
	{
	  my_error("A room haven't the expected nbr of arg\n");
	  free(tab);
	  return (EXIT_ERROR);
	}
      else if ((game = create_new_room(fd, game, tab)) == NULL)
	return (EXIT_ERROR);
      s = my_get_next_line(fd);
      free(tab);
    }
  if (link_room_ptr(game) == EXIT_ERROR)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
