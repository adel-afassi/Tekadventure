/*
** my_sleep.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 12:09:56 2017 Quentin AMARAL
** Last update Sun May 28 18:14:23 2017 Quentin AMARAL
*/

#include "tekad.h"

int		my_sleep(int sleep_time)
{
  sfClock	*clock;
  sfTime	time_clock;
  sfTime	time;

  clock = sfClock_create();
  time = sfSeconds(sleep_time);
  time_clock = sfClock_getElapsedTime(clock);
  while (sfTime_asMilliseconds(time_clock) <
	 sfTime_asMilliseconds(time))
    time_clock = sfClock_getElapsedTime(clock);
  return (EXIT_SUCCESS);
}
