/*
** str_to_wordtab_util.c for  in /Users/quentss/Tek/Shell/42sh/src/util/
**
** Made by Quentin AMARAL
** Login   <quentin.amaral@epitech.eu>
**
** Started on  Thu May 11 12:29:27 2017 Quentin AMARAL
** Last update Sun May 28 18:10:02 2017 adel
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "tekad.h"

char	**malloc_tab(char *str, char *separ)
{
  char	**tab;
  int	i;
  int	k;

  k = 0;
  i = 0;
  while (str != NULL && str[i] != 0)
    {
      if (find_separ(str, separ, i) == EXIT_SUCCESS)
	{
	  i += my_strlen(separ) - 1;
	  k += 1;
	}
      i += 1;
    }
  if ((tab = malloc(sizeof(char *) * (k + 2))) == NULL)
    return (NULL);
  return (tab);
}

char	*add_elem_str(char *str, char c)
{
  int	i;
  char	*new_str;

  i = 0;
  while (str != NULL && str[i] != 0)
    i += 1;
  if ((new_str = malloc(sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (str != NULL && str[i] != 0)
    {
      new_str[i] = str[i];
      i += 1;
    }
  free(str);
  new_str[i] = c;
  new_str[i + 1] = 0;
  return (new_str);
}

char	*next_str(char *str, char *sep, int *i)
{
  char	*new_str;

  new_str = NULL;
  while (str[*i] != 0)
    {
      if (find_separ(str, sep, *i) == EXIT_SUCCESS)
	{
	  *i += my_strlen(sep);
	  return (new_str);
	}
      new_str = add_elem_str(new_str, str[*i]);
      *i += 1;
    }
  return (new_str);
}

int	malloc_str(char **tab, char *str, char *sep)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str != NULL && str[i] != 0)
    {
      if ((tab[j] = next_str(str, sep, &i)) == NULL)
	return (EXIT_ERROR);
      j += 1;
    }
  tab[j] = 0;
  return (EXIT_SUCCESS);
}
