/*
** my_string.c for  in /home/Quentss/Work/graphic/parse/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Wed May 24 22:39:07 2017 Quentin AMARAL
** Last update Sun May 28 19:03:16 2017 Quentin AMARAL
*/

#include <unistd.h>
#include "tekad.h"

int	my_putchar_fd(int fd, char c)
{
  if (write(fd, &c, 1) == -1)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != 0)
    {
      if (my_putchar_fd(1, str[i]) == EXIT_ERROR)
	return (EXIT_ERROR);
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int	my_error(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != 0)
    {
      if (my_putchar_fd(2, str[i]) == EXIT_ERROR)
	return (EXIT_ERROR);
      i += 1;
    }
  return (EXIT_SUCCESS);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != 0)
    i += 1;
  return (i);
}
