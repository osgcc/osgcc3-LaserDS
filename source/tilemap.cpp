#include <nds.h>
#include <string.h>

#include <stdio.h>

#include "tilemap.h"

u32 tileQuad[] =
{
	12,
	FIFO_COMMAND_PACK(FIFO_BEGIN, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	GL_QUAD,
	TEXTURE_PACK(inttot16(0), inttot16(0)),
	VERTEX_PACK(floattov16(0), floattov16(0)),
	TEXTURE_PACK(inttot16(16), inttot16(0)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	VERTEX_PACK(floattov16(2), floattov16(0)),
	TEXTURE_PACK(inttot16(16), inttot16(16)),
	VERTEX_PACK(floattov16(2), floattov16(2)),
	TEXTURE_PACK(inttot16(0), inttot16(16)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_NOP, FIFO_NOP, FIFO_NOP),

	VERTEX_PACK(floattov16(0), floattov16(2))
};

// ---------------------------------------------------------------------
// Tilemap
Tilemap::Tilemap(int w, int h, int* textures) :
	mWidth(w), mHeight(h), mTextures(textures)
{
	mTiles = (ubyte*)malloc(w * h * sizeof(ubyte));
	memset(mTiles, 0, w * h * sizeof(ubyte));
}

Tilemap::~Tilemap()
{
	free(mTiles);
	mTiles = null;
}

void Tilemap::draw(Camera& camera)
{
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(31));
	glColor(ARGB16(1, 31, 31, 31));

	int x1 = camera.x;
	int x2 = camera.x + camera.width + 1;

	if(x1 < 0)
		x1 = 0;

	if(x2 >= mWidth)
		x2 = mWidth - 1;

	int y1 = camera.y;
	int y2 = camera.y + camera.height + 1;

	if(y1 < 0)
		y1 = 0;

	if(y2 >= mHeight)
		y2 = mHeight - 1;

	int w = (x2 - x1 + 1) * 2;

	glPushMatrix();
	glTranslatef(x1 * 2 + w, (y1 - 1) * 2, IMMOVABLE_OBJECT_DEPTH);

	for(int y = y1; y <= y2; y++)
	{
		glTranslatef(-w, 2, 0);

		for(int x = x1; x <= x2; x++)
		{
			ubyte t = get(x, y);

			if(t != 0)
			{
				glBindTexture(0, mTextures[t]);
				glCallList(tileQuad);
			}

			glTranslatef(2, 0, 0);
		}
	}

	glPopMatrix(1);
}