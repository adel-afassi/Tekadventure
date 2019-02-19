/*
** get_next_line.c for  in /home/Quentss/Work/graphic/tekadventure/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Sun May 28 20:49:41 2017 Quentin AMARAL
** Last update Sun May 28 20:49:42 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*cp;

  i = 0;
  while (str[i] != '\0')
    i++;
  cp = malloc(sizeof(char) * (i + size));
  if (cp == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      cp[i] = str[i];
      i++;
    }
  cp[i] = '\0';
  free(str);
  return (cp);
}

char		get_char(const int fd)
{
  static char	buff[READ_SIZE];
  static int	i;
  static int	b;
  static int	r;
  char		c;

  if (i == r)
    {
      i = 0;
      b = 0;
      r = 0;
    }
  if (b == 0)
    {
      r = read(fd, buff, READ_SIZE);
      if (r <= 0)
	return (0);
      b = 1;
    }
  if (b == 1)
    {
      c = buff[i];
      i++;
    }
  return (c);
}

char	*get_next_line(const int fd)
{
  char	c;
  char	*ret;
  int	i;
  int	b;

  i = 0;
  b = 0;
  if ((ret = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  ret[0] = 0;
  ret[1] = 0;
  if (fd < 0)
    return (NULL);
  while ((c = get_char(fd)) != '\n' && c != '\0')
    {
      b = 1;
      ret[i] = c;
      ret[i + 1] = 0;
      ret = my_realloc(ret, 2);
      i++;
    }
  if (c == 0 && b == 0)
    return (NULL);
  return (ret);
}
