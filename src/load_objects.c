/*
** load_obj.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Fri May 26 17:06:10 2017 Quentin AMARAL
** Last update Sun May 28 21:45:41 2017 adel
*/

#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

int		rand_obj(t_obj *obj, t_game *game)
{
  t_room	*room;

  room = game->actual_room;
  if (room == NULL)
    {
      my_error("No map in your conf folder, can't start game\n");
      return (EXIT_ERROR);
    }
  while (room->next != NULL)
    room = room->next;
  obj->pos.x = (rand() % (WINDOW_WIDTH - 300)) + 150;
  obj->pos.y = (rand() % (WINDOW_HEIGHT - 400)) + 300;
  obj->id_room = (rand() % (room->id - 1)) + 1;
  return (EXIT_SUCCESS);
}

int		add_rand_obj(t_game *game)
{
  t_obj		*obj;

  obj = game->first_obj;
  if (obj == NULL)
    {
      my_error("Error: can't start game ");
      my_error("because you don't have objects to find\n");
      return (EXIT_ERROR);
    }
  while (obj != NULL)
    {
      if (rand_obj(obj, game) == EXIT_ERROR)
	return (EXIT_ERROR);
      obj = obj->next;
    }
  return (EXIT_SUCCESS);
}

t_game		*create_new_obj_bis(char **tab, t_obj *obj, t_game *game)
{
  double	scale;

  obj->is_find = 0;
  if ((obj->pic_obj = create_pic("an obj", tab[0])) == NULL)
    {
      my_error(ERR_OBJS_LOAD);
      return (NULL);
    }
  if ((obj->pic_inv = create_pic("an obj", tab[0])) == NULL)
    {
      my_error(ERR_OBJS_LOAD);
      return (NULL);
    }
  if ((scale = my_getnbr(tab[1])) == -1)
    {
      my_error("An object don't have a correct size\n");
      return (NULL);
    }
  obj->scale.x = scale / 100;
  obj->scale.y = scale / 100;
  obj->pic_inv->scale.x = scale / 100;
  obj->pic_inv->scale.y = scale / 100;
  sfSprite_setScale(obj->pic_inv->sprite, obj->pic_inv->scale);
  return (game);
}

t_game		*create_new_obj(char **tab, t_game *game)
{
  t_obj		*obj;
  t_obj		*previous;

  if ((obj = malloc(sizeof(t_obj))) == NULL)
    return (NULL);
  previous = game->first_obj;
  if (previous == NULL)
    game->first_obj = obj;
  else
    {
      while (previous->next != NULL)
	previous = previous->next;
      previous->next = obj;
    }
  obj->next = NULL;
  return (create_new_obj_bis(tab, obj, game));
}

int	load_objects(int fd, t_game *game)
{
  char	*str;
  char	**tab;

  while ((str = my_get_next_line(fd)) != NULL)
    {
      if ((tab = my_str_to_wordtab(str, ":")) == NULL)
	return (EXIT_ERROR);
      if (my_tablen(tab) == 5)
	return (load_boss(fd, game, str));
      else if (my_tablen(tab) != 2)
	{
	  my_error("Error: an objects don't have the expected nbr of arg\n");
	  return (EXIT_ERROR);
	}
      free(str);
      if ((game = create_new_obj(tab, game)) == NULL)
	return (EXIT_ERROR);
      free(tab);
    }
  return (EXIT_SUCCESS);
}
