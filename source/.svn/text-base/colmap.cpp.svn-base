#include <nds.h>
#include <string.h>

#include "colmap.h"
#include "utils.h"

Colmap::Colmap(int w, int h) :
	mWidth(w), mHeight(h)
{
	mData = (ubyte*)malloc(w * h * sizeof(ubyte));
	memset(mData, COLLISION_NONE, w * h * sizeof(ubyte));
}

Colmap::~Colmap()
{
	free(mData);
	mData = null;
}