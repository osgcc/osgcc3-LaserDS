#ifndef _UTILS_H_
#define _UTILS_H_

#include <nds.h>

typedef u8 ubyte;
typedef u16 ushort;
typedef u32 uint;

#define SQRT_2 1.4142135623730950488016887242097
#define FIFO_VERTEX_XY REG2ID(GFX_VERTEX_XY)
#define null NULL

#define DIR_RIGHT 0
#define DIR_DOWN_RIGHT 1
#define DIR_DOWN 2
#define DIR_DOWN_LEFT 3
#define DIR_LEFT 4
#define DIR_UP_LEFT 5
#define DIR_UP 6
#define DIR_UP_RIGHT 7

#define PLAYING_FIELD_DEPTH (-14)
#define LASER_DEPTH (-12)
#define IMMOVABLE_OBJECT_DEPTH (-10)
#define MOVABLE_OBJECT_DEPTH (-8)

#define COLLISION_NONE 0
#define COLLISION_STATIC 255

#define ACCEPT_WIN (-1)

#define INPUT_CAMERA 0
#define INPUT_ZOOM 1
#define INPUT_MOVE 2

#define MAX_LASERS 3

const int DirToBrads = (int)(DEGREES_IN_CIRCLE * 45.0 / 360.0);

inline int wrapDir(int dir)
{
	if(dir < 0)
		return dir + 8;
	else if(dir >= 8)
		return dir - 8;
	else
		return dir;
}

inline void glScale3f32(int32 x, int32 y, int32 z)
{
	MATRIX_SCALE = x;
	MATRIX_SCALE = y;
	MATRIX_SCALE = z;
}

template<typename T>
inline void clamp(T& x, T lo, T hi)
{
	if(x < lo)
		x = lo;
	else if(x > hi)
		x = hi;
}

template<typename T>
inline T max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
inline T min(T a, T b)
{
	return a < b ? a : b;
}

#endif