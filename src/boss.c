/*
** boss.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 02:40:58 2017 Quentin AMARAL
** Last update Sun May 28 18:20:02 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <stdio.h>
#include "tekad.h"

int		fight_boss_bis(t_game *game)
{
  sfTime	time;
  sfTime	time_clock;

  time = sfSeconds(1 / game->boss->rate);
  time_clock = sfClock_getElapsedTime(game->boss->clock);
  if (sfTime_asMilliseconds(time_clock) >= sfTime_asMilliseconds(time))
    {
      game->chara->life -= game->boss->damage;
      sfMusic_play(game->sounds->chara_hit);
      sfClock_restart(game->boss->clock);
    }
  return (EXIT_SUCCESS);
}

int		fight_boss(t_game *game)
{
  int		attack;

  attack = 0;
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    attack = 1;
  if (attack != 0)
    {
      game->boss->current_life -= (CHARA_DAMAGE) / attack;
      sfMusic_play(game->sounds->attack_voice);
    }
  if (game->boss->current_life <= 0)
    game->boss->life = 0;
  return (EXIT_SUCCESS);
}

int		aff_boss(t_game *game)
{
  char		*life;

  life = "BOSS LIFE: ";
  if ((life = my_strcat(life, my_itoa(game->boss->current_life))) == NULL)
    return (EXIT_ERROR);
  if ((life = my_strcat(life, " / ")) == NULL)
    return (EXIT_ERROR);
  if ((life = my_strcat(life, my_itoa(game->boss->life))) == NULL)
    return (EXIT_ERROR);
  sfText_setString(game->texts->boss_life, life);
  sfText_setPosition(game->texts->life, (sfVector2f){400, 350});
  sfSprite_setScale(game->boss->pic->sprite,
		    game->boss->pic->scale);
  sfSprite_setPosition(game->boss->pic->sprite,
		       game->boss->pic->position);
  sfRenderWindow_drawSprite(game->window,
			    game->boss->pic->sprite, NULL);
  sfRenderWindow_drawText(game->window, game->texts->boss_life, NULL);
  free(life);
  return (EXIT_SUCCESS);
}
