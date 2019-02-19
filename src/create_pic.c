/*
** main.c for  in /home/youcef/delivery/MUL/tekadventure/srcs
** 
** Made by Youcef
** Login   <youcef.chergui@epitech.eu>
** 
** Started on  Thu May 18 03:46:00 2017 Youcef
** Last update Thu May 25 16:49:51 2017 Quentin AMARAL
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "tekad.h"

t_pic		*create_pic(char *name, char *path)
{
  t_pic		*img;

  if ((img = malloc(sizeof(t_pic))) == NULL)
    return (NULL);
  if ((img->texture = sfTexture_createFromFile(path, NULL)) == NULL)
    return (NULL);
  if ((img->sprite = sfSprite_create()) == NULL)
    return (NULL);
  img->name = name;
  sfSprite_setTexture(img->sprite, img->texture, sfTrue);
  img->size = sfTexture_getSize(img->texture);
  img->scale.x = 1;
  img->scale.y = 1;
  sfSprite_setScale(img->sprite, img->scale);
  return (img);
}
