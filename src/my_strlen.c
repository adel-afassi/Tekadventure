/*
** my_strlen.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 12:26:11 2017 Quentin AMARAL
** Last update Sat May 27 12:26:56 2017 Quentin AMARAL
*/

#include "tekad.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != 0)
    i += 1;
  return (i);
}
