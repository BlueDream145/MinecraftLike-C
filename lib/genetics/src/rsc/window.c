/*
** EPITECH PROJECT, 2018
** Genetics
** File description:
** Windows functions
*/

#include	"genetics.h"

float		get_ratioX(resources_t *rsc, float max)
{
	return (sfRenderWindow_getSize(rsc->window).x / max);
}

float		get_ratioY(resources_t *rsc, float max)
{
	return (sfRenderWindow_getSize(rsc->window).y / max);
}