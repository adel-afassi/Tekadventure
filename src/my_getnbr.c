/*
** my_getnbr.c for  in /home/Quentss/Work/graphic/tekadventure_parse/parse/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Thu May 25 02:14:27 2017 Quentin AMARAL
** Last update Fri May 26 12:00:47 2017 Quentin AMARAL
*/

#include "tekad.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_error("Error: not a number. Integer positive expected");
	  return (-1);
	}
      nbr = nbr * 10;
      nbr += str[i] - '0';
      i += 1;
    }
  return (nbr);
}
