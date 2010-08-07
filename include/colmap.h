#ifndef _COLMAP_H_
#define _COLMAP_H_

#include "utils.h"

struct Colmap
{
private:
	int mWidth, mHeight;
	ubyte* mData;

public:
	Colmap(int w, int h);
	~Colmap();

	inline int width()
	{
		return mWidth;
	}

	inline int height()
	{
		return mHeight;
	}

	inline void set(int x, int y, ubyte idx)
	{
		mData[x + mWidth * y] = idx;
	}

	inline ubyte get(int x, int y)
	{
		return mData[x + mWidth * y];
	}

private:

};

#endif