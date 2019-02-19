/*
** str_to_wordtab.c for  in /Users/quentss/Tek/Shell/42sh/src/util/
**
** Made by Quentin AMARAL
** Login   <quentin.amaral@epitech.eu>
**
** Started on  Thu May 11 11:24:53 2017 Quentin AMARAL
** Last update Thu May 25 16:50:30 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tekad.h"

int	find_separ(char *str, char *separ, int i)
{
  int	k;

  k = 0;
  while (str != NULL && str[k] != 0)
    k += 1;
  if (k < i)
    return (EXIT_ERROR);
  k = 0;
  while (separ[k] != 0)
    {
      if (str[i + k] == 0)
	return (EXIT_ERROR);
      if (str[i + k] != separ[k])
	return (EXIT_ERROR);
      k += 1;
    }
  return (EXIT_SUCCESS);
}

char	**my_str_to_wordtab(char *str, char *separ)
{
  char	**tab;

  if ((tab = malloc_tab(str, separ)) == NULL)
    return (NULL);
  if (malloc_str(tab, str, separ) == EXIT_ERROR)
    return (NULL);
  return (tab);
}
