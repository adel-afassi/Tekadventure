/*
** load.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 09:08:09 2017 Quentin AMARAL
** Last update Sun May 28 21:37:39 2017 adel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tekad.h"

t_game	*load_font(t_game *game)
{
  if (!(game->texts->life = create_text(NULL, (sfVector2f){720, 20}, 70)))
    return (NULL);
  if (!(game->texts->boss_life = create_text(NULL, (sfVector2f){250, 450}, 70)))
    return (NULL);
  sfText_setFont(game->texts->to_boss, game->font2);
  sfText_setFont(game->texts->to_find, game->font2);
  sfText_setFont(game->texts->mission, game->font2);
  sfText_setFont(game->texts->kill_boss, game->font2);
  sfText_setFont(game->texts->life, game->font2);
  sfText_setFont(game->texts->boss_life, game->font2);
  game->first_intro = NULL;
  return (game);
}

t_game	*load_game_quad(t_game *game)
{
  if ((game->sounds->monster =
       sfMusic_createFromFile("assets/sounds/monster.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  if ((game->sounds->chara_hit =
       sfMusic_createFromFile("assets/sounds/chara_hit.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  if ((game->sounds->attack_voice =
       sfMusic_createFromFile("assets/sounds/attack_voice.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  return (game);
}

t_game	*load_game_ter(t_game *game)
{
  if ((game->font2 = sfFont_createFromFile("assets/fonts/Stya.ttf")) == NULL)
    return (NULL);
  if ((game->texts = malloc(sizeof(t_text))) == NULL)
    return (EXIT_SUCCESS);
  if ((game->sounds->door_not_open =
       sfMusic_createFromFile("assets/sounds/door_not_open.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  if ((game->sounds->footstep =
       sfMusic_createFromFile("assets/sounds/footstep.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  return (load_game_quad(game));
}

t_game	*load_game_bis(t_game *game, int fd)
{
  if (load_objects(fd, game) == EXIT_ERROR)
    return (NULL);
  if (add_rand_obj(game) == EXIT_ERROR)
    return (NULL);
  if ((game->sounds->item_sound =
       sfMusic_createFromFile("assets/sounds/item_pickup.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  if ((game->sounds->all_item_sound =
       sfMusic_createFromFile("assets/sounds/all_item_pickup.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  if ((game->sounds->door =
       sfMusic_createFromFile("assets/sounds/door_sound.ogg")) == NULL)
    {
      my_error(ERR_ITEM_PICK_SOUND);
      return (NULL);
    }
  return (load_game_ter(game));
}

t_game		*load_game()
{
  t_game	*game;
  t_sounds	*sounds;
  int		fd;

  my_putstr("Loading Game...\n");
  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  if ((sounds = malloc(sizeof(t_sounds))) == NULL)
    return (NULL);
  game->sounds = sounds;
  game->clock = sfClock_create();
  if ((fd = open(CONF_FILE, O_RDONLY)) == -1)
    {
      my_error("Error: can't load conf file...\n");
      return (NULL);
    }
  game->actual_room = NULL;
  game->first_enemy = NULL;
  if ((game->chara = load_chara()) == NULL)
    return (NULL);
  if ((game = load_game_basic(game, fd)) == NULL)
    return (NULL);
  return (load_game_bis(game, fd));
}
