#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include "utils.h"
#include "camera.h"

struct Tilemap
{
private:
	int mWidth, mHeight;
	ubyte* mTiles;
	int* mTextures;

public:
	Tilemap(int w, int h, int* textures);
	~Tilemap();
	
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
		mTiles[x + mWidth * y] = idx;
	}

	inline ubyte get(int x, int y)
	{
		return mTiles[x + mWidth * y];
	}

	void draw(Camera& camera);

private:

};

#endif