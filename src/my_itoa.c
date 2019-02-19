/*
** my_itoa.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 12:07:58 2017 Quentin AMARAL
** Last update Sat May 27 12:08:18 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include "tekad.h"

char	*my_itoa(int nb)
{
  int	len;
  char	*str;
  int	tmp;

  tmp = nb;
  len = 0;
  if (nb == 0)
    return ("0");
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if ((str = malloc(sizeof(*str) * (len + 1))) == NULL)
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10 + '0';
      nb /= 10;
    }
  return (str);
}
