/*
** load_room_bis.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 19:04:44 2017 Quentin AMARAL
** Last update Sun May 28 19:04:45 2017 Quentin AMARAL
*/

#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

t_game	*create_new_room_ter(int fd, t_game *game, t_room *room, char **tab)
{
  if ((room->right_room_int = my_getnbr(tab[4])) == -1)
    return (NULL);
  room->bot_room = NULL;
  if ((room->bot_room_int = my_getnbr(tab[5])) == -1)
    return (NULL);
  room->door_room = NULL;
  room->door_room_int = 0;
  if ((room->door_room_int = my_getnbr(tab[6])) == -1)
    return (NULL);
  if ((create_door(fd, room)) == EXIT_ERROR)
    return (NULL);
  if ((room->is_final = my_getnbr(tab[7])) == -1)
    return (NULL);
  return (game);
}
