/*
** load_enemy.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:47:52 2017 Quentin AMARAL
** Last update Sun May 28 19:00:43 2017 Quentin AMARAL
*/

#include <stdio.h>
#include <stdlib.h>
#include "tekad.h"

int		fill_enemy(char **tab, t_enem *enem)
{
  double	scale;

  enem->next = NULL;
  if ((enem->pic = create_pic("enemy", tab[0])) == NULL)
    {
      my_error("Can't load enemy!!\n");
      return (EXIT_ERROR);
    }
  if ((enem->life = my_getnbr(tab[1])) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((enem->damage = my_getnbr(tab[2])) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((scale = my_getnbr(tab[3])) == EXIT_ERROR)
    return (EXIT_ERROR);
  enem->pic->scale.x = scale / 100;
  enem->pic->scale.y = scale / 100;
  enem->clock = sfClock_create();
  sfSprite_setScale(enem->pic->sprite, enem->pic->scale);
  return (EXIT_SUCCESS);
}

int		create_new_enemy(char **tab, t_game *game)
{
  t_enem	*enem;
  t_enem	*previous;

  if ((enem = malloc(sizeof(t_enem))) == NULL)
    return (EXIT_ERROR);
  previous = game->first_enemy;
  if (previous == NULL)
    {
      game->first_enemy = enem;
      enem->id = 1;
    }
  else
    {
      while (previous->next != NULL)
	previous = previous->next;
      previous->next = enem;
      enem->id = previous->id + 1;
    }
  return (fill_enemy(tab, enem));
}

int		fill_boss(char **tab, t_boss *boss)
{
  double	scale;

  if ((boss->pic = create_pic("boss", tab[0])) == NULL)
    {
      my_error("Can't load your boss!!\n");
      return (EXIT_ERROR);
    }
  if ((boss->life = my_getnbr(tab[1])) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((boss->damage = my_getnbr(tab[2])) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((scale = my_getnbr(tab[3])) == EXIT_ERROR)
    return (EXIT_ERROR);
  if ((boss->rate = my_getnbr(tab[4])) == EXIT_ERROR)
    return (EXIT_ERROR);
  boss->pic->scale.x = scale / 100;
  boss->pic->scale.y = scale / 100;
  boss->clock = sfClock_create();
  boss->current_life = boss->life;
  sfSprite_setScale(boss->pic->sprite, boss->pic->scale);
  return (EXIT_SUCCESS);
}

int		load_boss(int fd, t_game *game, char *str)
{
  t_boss	*boss;
  char		**tab;
  sfFloatRect	pos;

  if ((boss = malloc(sizeof(t_boss))) == NULL)
    return (EXIT_ERROR);
  if ((tab = my_str_to_wordtab(str, ":")) == NULL)
    return (EXIT_ERROR);
  free(str);
    if (my_tablen(tab) != 5)
      return (EXIT_ERROR);
  if (fill_boss(tab, boss) == EXIT_ERROR)
    return (EXIT_ERROR);
  pos = sfSprite_getGlobalBounds(boss->pic->sprite);
  boss->pic->position.x = (WINDOW_WIDTH / 2) - (pos.width/2);
  boss->pic->position.y = (WINDOW_HEIGHT / 2) - (pos.height/2);
  game->boss = boss;
  str = my_get_next_line(fd);
  free(tab);
  return (load_enemy(fd, game, str));
}

int	load_enemy(int fd, t_game *game, char *str)
{
  char	**tab;

  while (str != NULL)
    {
      if ((tab = my_str_to_wordtab(str, ":")) == NULL)
	return (EXIT_ERROR);
      if (my_tablen(tab) == 8)
	return (load_room(fd, game, str));
      else if (my_tablen(tab) != 4)
	{
	  my_error("An enemy don't have the expected nbr of arg\n");
	  free(tab);
	  return (EXIT_ERROR);
	}
      free(str);
      if (create_new_enemy(tab, game) == EXIT_ERROR)
	return (EXIT_ERROR);
      str = my_get_next_line(fd);
      free(tab);
    }
  return (EXIT_SUCCESS);
}
