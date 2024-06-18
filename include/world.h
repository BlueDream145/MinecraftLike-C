/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Project main header
*/

#ifndef WORLD_H_
	#define WORLD_H_

#include	<math.h>

#include	"genetics.h"
#include	"engine.h"
#include	"layout.h"
#include	"resources.h"

#define		C_EXIT_SUCCESS	0
#define		C_EXIT_ERROR	84

#define		C_README_PATH	"README.md"

void		display_file(const char *path);
int		check_env(char **env);

#endif /* !WORLD_H_ */
