#include <nds.h>
#include <stdio.h>

#include "gameobj.h"

#include "normal_laser.h"
#include "mirror.h"
#include "target.h"
#include "splitter.h"
#include "smalltarget.h"
#include "smallonly.h"
#include "shallowmirror.h"

u32 objQuad[] =
{
	12,
	FIFO_COMMAND_PACK(FIFO_BEGIN, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	GL_QUAD,
	TEXTURE_PACK(inttot16(0), inttot16(0)),
	VERTEX_PACK(floattov16(-1), floattov16(-1)),
	TEXTURE_PACK(inttot16(16), inttot16(0)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	VERTEX_PACK(floattov16(1), floattov16(-1)),
	TEXTURE_PACK(inttot16(16), inttot16(16)),
	VERTEX_PACK(floattov16(1), floattov16(1)),
	TEXTURE_PACK(inttot16(0), inttot16(16)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_NOP, FIFO_NOP, FIFO_NOP),

	VERTEX_PACK(floattov16(-1), floattov16(1))
};

int* GameObj::textures;

void GameObj::setupTextures()
{
	textures = (int*)malloc(GAMEOBJ_NUMOBJ * sizeof(int));
	glGenTextures(GAMEOBJ_NUMOBJ, textures);

	glBindTexture(0, textures[GAMEOBJ_Laser]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)normal_laserBitmap);

	glBindTexture(0, textures[GAMEOBJ_Mirror]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)mirrorBitmap);

	glBindTexture(0, textures[GAMEOBJ_Target]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)targetBitmap);

	glBindTexture(0, textures[GAMEOBJ_Splitter]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)splitterBitmap);

	glBindTexture(0, textures[GAMEOBJ_SmallTarget]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)smalltargetBitmap);

	glBindTexture(0, textures[GAMEOBJ_SmallOnly]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)smallonlyBitmap);

	glBindTexture(0, textures[GAMEOBJ_ShallowMirror]);
	glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)shallowmirrorBitmap);
}

int GameObj::type()
{
	return mType;
}

void GameObj::position(int x, int y)
{
	mX = x;
	mY = y;
}

int GameObj::x()
{
	return mX;
}

int GameObj::y()
{
	return mY;
}

void GameObj::direction(int dir)
{
	mDir = dir;
}

int GameObj::direction()
{
	return mDir;
}

void GameObj::draw(Camera& cam)
{
	if( mX < cam.x || mX > cam.x + cam.width ||
		mY < cam.y || mY > cam.y + cam.height)
		return;

	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(31));
	glColor(ARGB16(1, 31, 31, 31));

	glPushMatrix();
		glTranslatef(mX * 2 + 1, mY * 2 + 1, MOVABLE_OBJECT_DEPTH);
		glRotateZi(DirToBrads * mDir);
		glBindTexture(0, mTexture);
		glCallList(objQuad);
	glPopMatrix(1);
}

void GameObj::reset()
{
	mNumInputs = 0;
}

int dirDiff[8][8] =
{
	{  0,  1,  2,  3, -4, -3, -2, -1 },
	{ -1,  0,  1,  2,  3, -4, -3, -2 },
	{ -2, -1,  0,  1,  2,  3, -4, -3 },
	{ -3, -2, -1,  0,  1,  2,  3, -4 },
	{ -4, -3, -2, -1,  0,  1,  2,  3 },
	{  3, -4, -3, -2, -1,  0,  1,  2 },
	{  2,  3, -4, -3, -2, -1,  0,  1 },
	{  1,  2,  3, -4, -3, -2, -1,  0 }
};

void GameObj::addInput(int dir, int width, rgb color)
{
	if(mNumInputs == 0)
	{
		mInputs[0].dir = dir;
		mInputs[0].width = width;
		mInputs[0].color = color;
		mNumInputs++;
	}
	else if(mNumInputs == 1)
	{
		mInputs[1].dir = dir;
		mInputs[1].width = width;
		mInputs[1].color = color;
		mNumInputs++;
	}
	else
		sassert(false, "too many inputs");
}

int GameObj::accept(int dir, int width, rgb color, int& outDir1, int& outWidth1, rgb& outColor1, int& outDir2, int& outWidth2, rgb& outColor2)
{
	switch(mType)
	{
		case GAMEOBJ_Laser: return 0;

		case GAMEOBJ_Mirror:
		{
			if(mNumInputs > 0)
				return 0;

			int diff = dirDiff[mDir][wrapDir(dir + 4)];

			if(diff == -1 || diff == 1)
			{
				outDir1 = wrapDir(mDir - diff);
				outWidth1 = width;
				outColor1 = color;
				addInput(dir, width, color);
				return 1;
			}

			return 0;
		}
		
		case GAMEOBJ_ShallowMirror:
		{
			if(mNumInputs > 0)
				return 0;

			int diff = dirDiff[mDir][wrapDir(dir + 4)];
			bool reflect = false;

			if(diff == -1)
			{
				reflect = true;
				diff = wrapDir(dir - 1);
			}
			else if(diff == 0)
			{
				reflect = true;
				diff = wrapDir(dir - 3);
			}
			else if(diff == 1)
			{
				reflect = true;
				diff = wrapDir(dir + 3);
			}
			else if(diff == 2)
			{
				reflect = true;
				diff = wrapDir(dir + 1);
			}
			
			if(reflect)
			{
				outDir1 = diff;
				outWidth1 = width;
				outColor1 = color;
				addInput(dir, width, color);
				return 1;
			}
		}

		case GAMEOBJ_Target:
		{
			if(mNumInputs > 0)
				return 0;

			if(mDir == wrapDir(dir + 4) && width == 4)
			{
				addInput(dir, width, color);
				return ACCEPT_WIN;
			}

			return 0;
		}

		case GAMEOBJ_SmallTarget:
		{
			if(mNumInputs > 0)
				return 0;

			if(mDir == wrapDir(dir + 4) && width == 2)
			{
				addInput(dir, width, color);
				return ACCEPT_WIN;
			}

			return 0;
		}

		case GAMEOBJ_Splitter:
		{
			if(mNumInputs == 0)
			{
				if(mDir == wrapDir(dir + 4) && width >= 4)
				{
					outDir1 = wrapDir(mDir + 2);
					outWidth1 = width / 2;
					outColor1 = color;
					outDir2 = wrapDir(mDir - 2);
					outWidth2 = width / 2;
					outColor2 = color;
					addInput(dir, width, color);
					return 2;
				}
				
				int diff = dirDiff[mDir][wrapDir(dir + 4)];

				if(diff == -2 || diff == 2)
				{
					addInput(dir, width, color);
					return 0;
				}
			}
			else if(mNumInputs == 1 && mInputs[0].width < 8 && wrapDir(mInputs[0].dir + 4) != mDir)
			{
				if(wrapDir(mInputs[0].dir + 4) == dir && mInputs[0].width == width)
				{
					addInput(dir, width, color);
					outDir1 = mDir;
					outWidth1 = width + width;
					outColor1 = color | mInputs[0].color;
					return 1;
				}
			}

			return 0;
		}
		
		case GAMEOBJ_SmallOnly:
		{
			if((mDir == dir || mDir == wrapDir(dir + 4)) && width == 2)
			{
				outDir1 = dir;
				outWidth1 = width;
				outColor1 = color;
				return 1;
			}
			
			return 0;
		}

		default: break;
	}

	sassert(false, "unhandled GameObj::accept");
	return 0;
}