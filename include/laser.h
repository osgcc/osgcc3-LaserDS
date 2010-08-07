#ifndef _LASER_H_
#define _LASER_H_

#include "utils.h"

struct Laser
{
	private: static int mTexture;
	public: static void setupTexture();

	struct Point
	{
		friend class Laser;

	private:
		short mX, mY;
		ubyte mWidth; // measured in eighths
		rgb mColor;

		ubyte mNumChildren;
		Point* mLeft, *mRight;
		ubyte mLeftDir;
		ubyte mRightDir;
		int32 mLeftLen;
		int32 mRightLen;

		Point();

	public:
		void init(short x, short y, ubyte width, rgb color);
		rgb color();
	};

private:
	Point* mRoot;
	Point* mFreeList;

public:
	Laser();
	Point* root();
	Point* point(short x, short y, ubyte width, rgb color);
	void freeChildren(Point* p);
	void addChild(Point* p, Point* left);
	void draw();

private:
	void calcDirAndLen(Point* psrc, Point* pdest, ubyte* dir, int32* len);
	void drawLaser(Laser::Point* psrc);
	void drawSegment(Laser::Point* psrc, int child);
	void freePoint(Point* p);
};

#endif