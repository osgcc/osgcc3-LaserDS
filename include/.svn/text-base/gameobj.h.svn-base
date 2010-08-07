#ifndef _GAMEOBJ_H_
#define _GAMEOBJ_H_

#include "utils.h"
#include "laser.h"
#include "camera.h"

enum GameObjType
{
	GAMEOBJ_Laser,
	GAMEOBJ_Mirror,
	GAMEOBJ_Target,
	GAMEOBJ_Splitter,
	GAMEOBJ_SmallTarget,
	GAMEOBJ_SmallOnly,
	GAMEOBJ_ShallowMirror,

	GAMEOBJ_NUMOBJ
};

const bool isMovableObj[] =
{
	false, // Laser
	true,  // Mirror
	false, // Target
	true,  // Splitter
	false, // SmallTarget
	false, // SmallOnly
	true,  // ShallowMirror
};

struct GameObj
{
	private: static int* textures;
	public: static void setupTextures();

private:
	int mX, mY;
	int mDir;
	int mType;
	Laser::Point* mPoint;
	int mTexture;
	
	struct Input
	{
		int dir, width;
		rgb color;
	} mInputs[2];
	
	int mNumInputs;

public:
	GameObj(int x, int y, int dir, int type) :
		mX(x), mY(y), mDir(dir), mType(type), mPoint(null), mTexture(textures[type]), mNumInputs(0)
	{}
	
	GameObj()
	{}

	int type();
	void position(int x, int y);
	int x();
	int y();
	void direction(int dir);
	int direction();
	void draw(Camera& camera);
	void reset();

	int accept(int dir, int width, rgb color, int& outDir1, int& outWidth1, rgb& outColor1, int& outDir2, int& outWidth2, rgb& outColor2);

private:
	void addInput(int dir, int width, rgb color);
};

#endif