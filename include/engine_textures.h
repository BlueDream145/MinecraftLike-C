/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Engine textures
*/

#ifndef ENGINE_TEXTURES_H_
	#define ENGINE_TEXTURES_H_

#include	"engine.h"

#define		C_BLOCKS_TEXTURES	98
#define		C_BLOCKS_LINE		14
#define		C_DIM			16

static const char	C_SP_PATH[] =	"data/block_spritesheet.png";

#define		GET_DIM_X(i)		(C_DIM * (i % C_BLOCKS_LINE))
#define		GET_DIM_Y(i)		(C_DIM * (i / C_BLOCKS_LINE))

#endif /* !ENGINE_TEXTURES_H_ */
