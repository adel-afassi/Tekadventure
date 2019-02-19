/*
** get_next_line_comment.c for  in /home/Quentss/Work/graphic/parse/src
** 
** Made by Quentin AMARAL
** Login   <Quentss@epitech.net>
** 
** Started on  Wed May 24 23:30:13 2017 Quentin AMARAL
** Last update Thu May 25 16:50:11 2017 Quentin AMARAL
*/

#include <unistd.h>
#include <stdlib.h>
#include "tekad.h"

char	*my_get_next_line(int fd)
{
  char	*s;

  if ((s = get_next_line(fd)) == NULL)
    return (NULL);
  if (s[0] == ';')
    {
      free(s);
      return (my_get_next_line(fd));
    }
  else
    return (s);
}
