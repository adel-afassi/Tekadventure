/*
** enemy.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 10:53:24 2017 Quentin AMARAL
** Last update Sun May 28 16:39:39 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <stdio.h>
#include "tekad.h"

int		fight_enemy_bis(t_game *game, t_enem *enem)
{
  sfTime	time;
  sfTime	time_clock;

  time = sfSeconds(MONSTER_ATTACK);
  time_clock = sfClock_getElapsedTime(enem->clock);
  if (sfTime_asMilliseconds(time_clock) >= sfTime_asMilliseconds(time))
    {
      game->chara->life -= enem->damage;
      sfMusic_play(game->sounds->chara_hit);
      sfClock_restart(enem->clock);
    }
  return (EXIT_SUCCESS);
}

int		fight_enemy(t_game *game)
{
  t_enem	*enem;
  int		attack;

  attack = 0;
  enem = game->actual_room->enemy;
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    attack = 1;
  if (attack != 0)
    {
      enem->current_life -= (CHARA_DAMAGE) / attack;
      sfMusic_play(game->sounds->attack_voice);
    }
  if (enem->current_life <= 0)
    game->actual_room->enemy = NULL;
  return (EXIT_SUCCESS);
}

int		aff_enemy(t_game *game)
{
  sfSprite_setScale(game->actual_room->enemy->pic->sprite,
		    game->actual_room->enemy->pic->scale);
  sfSprite_setPosition(game->actual_room->enemy->pic->sprite,
		       game->actual_room->enemy->pic->position);
  sfRenderWindow_drawSprite(game->window,
			    game->actual_room->enemy->pic->sprite, NULL);
  return (EXIT_SUCCESS);
}

int		spawn_enemy_bis(t_enem *enem)
{
  sfFloatRect	pos;

  pos = sfSprite_getGlobalBounds(enem->pic->sprite);
  enem->pic->position.x = ((rand() % (WINDOW_WIDTH / 2))
			   + (WINDOW_WIDTH / 4)) - (pos.width / 2);
  enem->pic->position.y = ((rand() % (WINDOW_HEIGHT / 2))
			   + (WINDOW_HEIGHT / 4)) - (pos.height / 2);
  enem->current_life = enem->life;
  sfClock_restart(enem->clock);
  return (EXIT_SUCCESS);
}

int		spawn_enemy(t_game *game)
{
  t_enem	*enem;
  int		id_enem;

  if (rand() % ENEMY_FREQUENCE != 1)
    return (EXIT_SUCCESS);
  enem = game->first_enemy;
  if (enem == NULL)
    return (EXIT_SUCCESS);
  while (enem->next != NULL)
    enem = enem->next;
  id_enem = rand() % (enem->id) + 1;
  enem = game->first_enemy;
  while (enem != NULL && enem->id != id_enem)
    enem = enem->next;
  if (enem == NULL)
    return (EXIT_ERROR);
  if (spawn_enemy_bis(enem) == EXIT_ERROR)
    return (EXIT_ERROR);
  sfMusic_play(game->sounds->monster);
  game->actual_room->enemy = enem;
  return (EXIT_SUCCESS);
}
