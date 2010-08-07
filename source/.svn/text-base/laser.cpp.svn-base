#include <nds.h>
#include <stdio.h>

#include "laser.h"

u16 laserTexData[] =
{
	0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210,
	0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6,
	0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C,
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,

	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
	0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C, 0xF39C,
	0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6, 0xDAD6,
	0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210, 0xC210,
};

u32 laserQuad[] =
{
	12,
	FIFO_COMMAND_PACK(FIFO_BEGIN, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	GL_QUAD,
	TEXTURE_PACK(inttot16(0), inttot16(0)),
	VERTEX_PACK(floattov16(0), floattov16(0.5)),
	TEXTURE_PACK(inttot16(8), inttot16(0)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_TEX_COORD, FIFO_VERTEX_XY, FIFO_TEX_COORD),

	VERTEX_PACK(floattov16(1), floattov16(0.5)),
	TEXTURE_PACK(inttot16(8), inttot16(8)),
	VERTEX_PACK(floattov16(1), floattov16(-0.5)),
	TEXTURE_PACK(inttot16(0), inttot16(8)),

	FIFO_COMMAND_PACK(FIFO_VERTEX_XY, FIFO_NOP, FIFO_NOP, FIFO_NOP),

	VERTEX_PACK(floattov16(0), floattov16(-0.5))
};

int Laser::mTexture;

void Laser::setupTexture()
{
	glGenTextures(1, &mTexture);
	glBindTexture(0, mTexture);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, (u8*)laserTexData);
}

// ---------------------------------------------------------------------
// Laser::Point
Laser::Point::Point()
{
}

void Laser::Point::init(short x, short y, ubyte width, rgb color)
{
	mX = x;
	mY = y;
	mWidth = width;
	mColor = color;
	mNumChildren = 0;
	mLeft = null;
}

rgb Laser::Point::color()
{
	return mColor;
}

// ---------------------------------------------------------------------
// Laser
Laser::Laser()
{
	mRoot = point(0, 0, 0, 0);
	mFreeList = null;
}

Laser::Point* Laser::root()
{
	return mRoot;
}

Laser::Point* Laser::point(short x, short y, ubyte width, rgb color)
{
	Laser::Point* ret;

	if(mFreeList)
	{
		ret = mFreeList;
		mFreeList = ret->mLeft;
	}
	else
		ret = new Point();

	ret->init(x, y, width, color);
	return ret;
}

void Laser::freePoint(Laser::Point* p)
{
	if(p->mNumChildren > 0)
	{
		freePoint(p->mLeft);

		if(p->mNumChildren > 1)
			freePoint(p->mRight);
	}
	
	p->mLeft = mFreeList;
	mFreeList = p;
}

void Laser::freeChildren(Point* p)
{
	if(p->mNumChildren > 0)
	{
		freeChildren(p->mLeft);
		freePoint(p->mLeft);

		if(p->mNumChildren > 1)
		{
			freeChildren(p->mRight);
			freePoint(p->mRight);
		}

		p->mNumChildren = 0;
	}
}

void Laser::addChild(Point* psrc, Point* pdest)
{
	if(psrc->mNumChildren == 0)
	{
		psrc->mNumChildren = 1;
		psrc->mLeft = pdest;
		calcDirAndLen(psrc, pdest, &psrc->mLeftDir, &psrc->mLeftLen);
	}
	else if(psrc->mNumChildren == 1)
	{
		psrc->mNumChildren = 2;
		psrc->mRight = pdest;
		calcDirAndLen(psrc, pdest, &psrc->mRightDir, &psrc->mRightLen);
	}
	else
		sassert(false, "too many children");
}

void Laser::calcDirAndLen(Point* psrc, Point* pdest, ubyte* dir, int32* len)
{
	short dx = pdest->mX - psrc->mX;
	short dy = pdest->mY - psrc->mY;

	if(dx == 0)
	{
		// Vertical

		if(dy > 0)
			*dir = DIR_DOWN;
		else
			*dir = DIR_UP;

		*len = inttof32(abs(dy));
	}
	else if(dy == 0)
	{
		// Horizontal

		if(dx < 0)
			*dir = DIR_LEFT;
		else
			*dir = DIR_RIGHT;

		*len = inttof32(abs(dx));
	}
	else if(dx > 0)
	{
		// Right Diagonal

		if(dy > 0)
			*dir = DIR_DOWN_RIGHT;
		else
			*dir = DIR_UP_RIGHT;

		*len = mulf32(inttof32(dx), floattof32(SQRT_2));
	}
	else
	{
		// Left Diagonal

		if(dy > 0)
			*dir = DIR_DOWN_LEFT;
		else
			*dir = DIR_UP_LEFT;

		*len = mulf32(inttof32(-dx), floattof32(SQRT_2));
	}
}

void Laser::draw()
{
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(1));
	glBindTexture(0, mTexture);

	glPushMatrix();
		glTranslatef(1, 1, LASER_DEPTH);
		drawLaser(mRoot);
	glPopMatrix(1);
}

void Laser::drawLaser(Laser::Point* psrc)
{
	while(psrc->mNumChildren == 1)
	{
		drawSegment(psrc, 0);
		psrc = psrc->mLeft;
	}

	if(psrc->mNumChildren == 2)
	{
		drawSegment(psrc, 0);
		drawLaser(psrc->mLeft);
		drawSegment(psrc, 1);
		drawLaser(psrc->mRight);
	}
}

void Laser::drawSegment(Laser::Point* psrc, int child)
{
	glPushMatrix();
		short srcx = psrc->mX, srcy = psrc->mY;

		glTranslatef(srcx * 2, srcy * 2, 0);

		if(child == 0)
		{
			glRotateZi(DirToBrads * psrc->mLeftDir);
			glScale3f32(psrc->mLeftLen * 2, psrc->mLeft->mWidth << 9, 1);
			glColor(psrc->mLeft->mColor);
		}
		else
		{
			glRotateZi(DirToBrads * psrc->mRightDir);
			glScale3f32(psrc->mRightLen * 2, psrc->mRight->mWidth << 9, 1);
			glColor(psrc->mRight->mColor);
		}

		glCallList(laserQuad);
	glPopMatrix(1);
}