#ifndef _LEVELDATA_H_
#define _LEVELDATA_H_

struct GameObjDesc
{
	int x, y, dir, type;
};

struct Level
{
	int w, h;
	int* tileData;
	int numGameObjs;
	GameObjDesc* gameObjs;
	const char* desc;
};

int level0tiledata[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

GameObjDesc level0gameobjs[] =
{
	{4, 3, DIR_RIGHT, GAMEOBJ_Laser},
	{6, 7, DIR_DOWN_LEFT, GAMEOBJ_Mirror},
	{8, 8, DIR_UP, GAMEOBJ_Target}
};

const char* level0desc =
"Hi! Welcome. This is a game of  "
"lasers and mirrors. You can see "
"the laser beam in the middle.   "
"The triangular thing is a       "
"mirror. The point of the game   "
"is to get the laser into the    "
"target, which is marked with,   "
"well, a target.                 "
"                                "
"You can move mirrors by dragging"
"them with the stylus. To finish "
"this level, just drag the mirror"
"into the path of the laser to   "
"redirect the beam into the      "
"target.";

Level level0 =
{
	14, 10,
	level0tiledata,
	sizeof(level0gameobjs) / sizeof(GameObjDesc), level0gameobjs,
	level0desc
};

int level1tiledata[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

GameObjDesc level1gameobjs[] =
{
	{5, 3, DIR_DOWN_LEFT, GAMEOBJ_Laser},
	{2, 2, DIR_RIGHT, GAMEOBJ_Mirror},
	{7, 10, DIR_UP, GAMEOBJ_Mirror},
	{15, 1, DIR_LEFT, GAMEOBJ_Mirror},
	{12, 4, DIR_DOWN_RIGHT, GAMEOBJ_Target}
};

const char* level1desc =
"Some levels are bigger than what"
"will fit on-screen. To deal with"
"this, you can move your view. If"
"you hold the stylus in your     "
"right hand, you can use the d-  "
"pad, and if you're a lefty, you "
"can use the ABXY buttons.       "
"                                "
"Furthermore, you can get a      "
"better view of the level overall"
"by zooming out. To do that, hold"
"the L or R button.              "
"                                "
"Navigate this large map and drag"
"the mirrors to direct the laser.";

Level level1 =
{
	20, 16,
	level1tiledata,
	sizeof(level1gameobjs) / sizeof(GameObjDesc), level1gameobjs,
	level1desc
};

int level2tiledata[] =
{
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
};

GameObjDesc level2gameobjs[] =
{
	{1, 1, DIR_RIGHT, GAMEOBJ_Laser},
	{5, 1, DIR_UP_RIGHT, GAMEOBJ_Mirror},
	{5, 8, DIR_UP_LEFT, GAMEOBJ_Mirror},
	{10, 8, DIR_DOWN_LEFT, GAMEOBJ_Mirror},
	{10, 2, DIR_RIGHT, GAMEOBJ_Mirror},
	{17, 2, DIR_DOWN, GAMEOBJ_Mirror},
	{17, 8, DIR_UP, GAMEOBJ_Target}
};

const char* level2desc =
"You won't always get such nicely"
"oriented mirrors. Usually they  "
"won't be pointed the way you    "
"need them to be. To solve this  "
"level, you'll have to turn the  "
"mirrors.                        "
"                                "
"To turn a mirror, tap and hold  "
"a mirror and press left/right or"
"Y/A. Let go of the mirror when  "
"you're done turning it.         "
"                                "
"You shouldn't have to move any  "
"mirrors to solve this level.";

Level level2 =
{
	20, 10,
	level2tiledata,
	sizeof(level2gameobjs) / sizeof(GameObjDesc), level2gameobjs,
	level2desc
};

int level3tiledata[] =
{
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

GameObjDesc level3gameobjs[] =
{
	{2, 10, DIR_UP_LEFT, GAMEOBJ_Laser},
	{1, 1, DIR_LEFT, GAMEOBJ_Mirror},
	{2, 1, DIR_UP_RIGHT, GAMEOBJ_Mirror},
	{7, 11, DIR_UP, GAMEOBJ_Mirror},
	{8, 12, DIR_RIGHT, GAMEOBJ_Mirror},
	{9, 12, DIR_LEFT, GAMEOBJ_Mirror},
	{12, 2, DIR_DOWN_LEFT, GAMEOBJ_Mirror},
	{19, 13, DIR_DOWN, GAMEOBJ_Mirror},
	{17, 3, DIR_UP_RIGHT, GAMEOBJ_Target}
};

const char* level3desc =
"You're on your own this level.  "
"Use what you've learned so far  "
"to complete it.";

Level level3 =
{
	20, 14,
	level3tiledata,
	sizeof(level3gameobjs) / sizeof(GameObjDesc), level3gameobjs,
	level3desc
};

int level4tiledata[] =
{
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
};

GameObjDesc level4gameobjs[] =
{
	{7, 8, DIR_UP, GAMEOBJ_Laser},
	{7, 2, DIR_RIGHT, GAMEOBJ_Splitter},
	{8, 2, DIR_RIGHT, GAMEOBJ_Mirror},
	{6, 2, DIR_RIGHT, GAMEOBJ_Mirror},
	{2, 2, DIR_DOWN, GAMEOBJ_SmallTarget},
	{12, 8, DIR_UP, GAMEOBJ_SmallTarget}
};

const char* level4desc =
"In this level, we're introducing"
"the splitter. Like it sounds,   "
"it will split a laser into two  "
"beams. But it conserves energy: "
"If you split a laser in two,    "
"each split beam will have only  "
"half the power of the original. "
"Also, small beams can't be split"
"any further.                    "
"                                "
"Targets only accept certain     "
"powers of lasers. Notice the    "
"little targets on either side.  "
"These will only accept small    "
"lasers. And also notice that    "
"there are now two targets. You  "
"have to get a laser to every one"
"to complete the level.";

Level level4 =
{
	15, 10,
	level4tiledata,
	sizeof(level4gameobjs) / sizeof(GameObjDesc), level4gameobjs,
	level4desc
};

int level5tiledata[] =
{
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
};

GameObjDesc level5gameobjs[] =
{
	{0, 3, DIR_RIGHT, GAMEOBJ_Laser},

	{0, 0, DIR_LEFT, GAMEOBJ_Splitter},
	{1, 0, DIR_UP_LEFT, GAMEOBJ_Mirror},
	{2, 0, DIR_UP_LEFT, GAMEOBJ_Mirror},
	{3, 0, DIR_UP_LEFT, GAMEOBJ_Mirror},
	{4, 0, DIR_UP_LEFT, GAMEOBJ_Mirror},

	{5, 3, DIR_RIGHT, GAMEOBJ_SmallOnly},
	{5, 7, DIR_RIGHT, GAMEOBJ_SmallOnly},

	{7, 2, DIR_LEFT, GAMEOBJ_Splitter},
	{7, 3, DIR_UP_LEFT, GAMEOBJ_Mirror},
	{7, 4, DIR_UP_LEFT, GAMEOBJ_Mirror},

	{11, 6, DIR_LEFT, GAMEOBJ_Target}
};

const char* level5desc =
"Small lasers can get places that"
"larger lasers can't. The pipe-  "
"like objects only allow small   "
"lasers to pass through (and only"
"in one direction).              "
"                                "
"But wait, what's the splitter   "
"doing on the right side?  Well, "
"splitters can actually undo a   "
"split. If you aim two small     "
"lasers at its sides, it will re-"
"join them into a normal-sized   "
"laser.";

Level level5 =
{
	12, 10,
	level5tiledata,
	sizeof(level5gameobjs) / sizeof(GameObjDesc), level5gameobjs,
	level5desc
};

int level6tiledata[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0,
	1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0,
	1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
};

GameObjDesc level6gameobjs[] =
{
	{0, 8, DIR_RIGHT, GAMEOBJ_Laser},

	{1, 1, DIR_RIGHT, GAMEOBJ_ShallowMirror},
	{4, 8, DIR_RIGHT, GAMEOBJ_ShallowMirror},

	{11, 9, DIR_UP, GAMEOBJ_Target}
};

const char* level6desc =
"Here are some new mirrors which "
"can be a bit tricky to use.     "
"They reflect lasers at a shallow"
"or steep angle. You can use them"
"to get some interesting angles.";

Level level6 =
{
	12, 10,
	level6tiledata,
	sizeof(level6gameobjs) / sizeof(GameObjDesc), level6gameobjs,
	level6desc
};

const Level levels[] =
{
	level0,
	level1,
	level2,
	level3,
	level4,
	level5,
	level6,
};

#endif