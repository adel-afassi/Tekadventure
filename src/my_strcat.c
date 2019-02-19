/*
** my_strcat.c for  in /home/Quentss/Work/graphic/tekadventure
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sat May 27 12:25:51 2017 Quentin AMARAL
** Last update Sun May 28 18:11:49 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdlib.h>
#include "tekad.h"

char	*my_strcpy(char *str)
{
  char	*new_str;
  int	i;

  i = 0;
  while (str != NULL && str[i] != 0)
    i += 1;
  if ((new_str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str != NULL && str[i] != 0)
    {
      new_str[i] = str[i];
      i += 1;
    }
  new_str[i] = 0;

  return (new_str);
}

char	*my_strcat_malloc(char *str1, char *str2)
{
  int	i;
  int	k;
  char	*new_str;

  i = 0;
  k = 0;
  while (str1 != NULL && str1[i] != 0)
    i += 1;
  while (str2 != NULL && str2[k] != 0)
    {
      i += 1;
      k += 1;
    }
  if ((new_str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  return (new_str);
}

char	*my_strcat(char *str1, char *str2)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((new_str = my_strcat_malloc(str1, str2)) == NULL)
    return (NULL);
  while (str1 != NULL && str1[i] != 0)
    {
      new_str[i] = str1[i];
      i += 1;
    }
  while (str2 != NULL && str2[k] != 0)
    {
      new_str[i] = str2[k];
      i += 1;
      k += 1;
    }
  new_str[i] = 0;
  return (new_str);
}

char	*add_to_str(char *str, char c)
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
  new_str[i] = c;
  new_str[i + 1] = 0;
  free(str);
  return (new_str);
}
