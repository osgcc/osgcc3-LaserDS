#include <nds.h>
#include <string.h>
#include <stdio.h>
#include <nds\arm9\sassert.h>

#include "utils.h"
#include "laser.h"
#include "tilemap.h"
#include "camera.h"
#include "gameobj.h"
#include "colmap.h"

#include "floor.h"
#include "block.h"
#include "ring.h"
#include "title.h"
#include "thanks.h"
#include "font.h"

#include "leveldata.h"

int ringColorTable[32] =
{
	0, 0, 1, 1, 2, 3, 4, 6, 8, 10, 12, 13, 14, 14, 15, 15, 15, 14, 14, 13, 12, 10, 8, 6, 4, 3, 2, 1, 1, 0, 0
};

int laserColors[MAX_LASERS] =
{
	ARGB16(1, 31,  0,  0),
	ARGB16(1,  0, 31,  0),
	ARGB16(1,  0,  0, 31),
};

struct Game
{
	int keyHit;
	int keyReleased;
	int keyDown;
	int keyRepeat;
	touchPosition touch;
	int inputMode;

	Camera camera, tempCamera;
	int maxCamX;
	int maxCamY;

	int floorTex;
	int* staticObjTextures;
	int ringTex;

	Tilemap* staticObjects;
	Colmap* collision;

	GameObj gameObjects[256];
	int numGameObjects;
	int selectedObject;
	int selectedX, selectedY;
	int ringColorIdx;

	Laser lasers[MAX_LASERS];
	int laserObjects[MAX_LASERS];
	bool laserActive[MAX_LASERS];

	int numTargets;
	int targetsSatisfied;
	int numSwitches;
	int switchesSatisfied;

	int fadeValue;
	const char* desc;

	void resetGameState()
	{
		keyHit = 0;
		keyReleased = 0;
		keyDown = 0;
		keyRepeat = 0;
		inputMode = INPUT_CAMERA;
		numGameObjects = 0;
		selectedObject = 0;
		numTargets = 0;
		targetsSatisfied = 0;
		numSwitches = 0;
		switchesSatisfied = 0;
		fadeValue = 16;
		desc = "\0";

		for(int i = 0; i < MAX_LASERS; i++)
			laserActive[i] = false;
	}

	void init()
	{
		setupMainScreen();
		setupSubScreen();
		lcdMainOnBottom();

		Laser::setupTexture();
		GameObj::setupTextures();

		glGenTextures(1, &floorTex);
		glBindTexture(0, floorTex);
		glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128, TEXTURE_SIZE_128, 0, TEXGEN_OFF | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T, (u8*)floorBitmap);

		keysSetRepeat(15, 2);

		camera = Camera(0, 0, 16, 12);

		staticObjTextures = (int*)malloc(2 * sizeof(int));

		staticObjTextures[0] = 0;
		glGenTextures(2, staticObjTextures + 1);

		glBindTexture(0, staticObjTextures[1]);
		glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_OFF, (u8*)blockBitmap);

		glGenTextures(1, &ringTex);
		glBindTexture(0, ringTex);
		glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_32, TEXTURE_SIZE_32, 0, TEXGEN_OFF, (u8*)ringBitmap);

		inputMode = INPUT_CAMERA;
		selectedObject = 0;
		fadeValue = 16;

		BG_PALETTE_SUB[0] = RGB15(0, 10, 20);
	}

	void setupMainScreen()
	{
		videoSetMode(MODE_0_3D);
		vramSetBankA(VRAM_A_TEXTURE);
		vramSetBankB(VRAM_B_TEXTURE);
		
		REG_BLDCNT = BLEND_SRC_BG0 | BLEND_FADE_BLACK;
		REG_BLDY = 16;

		glInit();
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_ANTIALIAS);
		glEnable(GL_BLEND);

		glClearColor(0, 0, 0, 31);
		glClearPolyID(63);
		glClearDepth(0x7FFF);
		glViewport(0, 0, 255, 191);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 32, 0, 24, 0.5, 20);
		glScalef(1, -1, 1);
		glTranslatef(0, -24, 0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void setupSubScreen()
	{
		PrintConsole* console = consoleDemoInit();

		ConsoleFont font;

		font.gfx = (u16*)fontTiles;
		font.pal = (u16*)fontPal;
		font.numChars = 128;
		font.numColors =  fontPalLen / 2;
		font.bpp = 4;
		font.asciiOffset = 32;
		font.convertSingleColor = false;

		consoleSetFont(console, &font);
	}
	
	void startLevel(uint lev)
	{
		resetGameState();

		REG_BLDY = fadeValue;

		Tilemap t(levels[lev].w, levels[lev].h, staticObjTextures);
		Colmap c(levels[lev].w, levels[lev].h);
		staticObjects = &t;
		collision = &c;

		for(int i = 0; i < t.width(); i++)
		{
			for(int j = 0; j < t.height(); j++)
			{
				int tile = levels[lev].tileData[j * t.width() + i];
				t.set(i, j, tile);

				if(tile != 0)
					c.set(i, j, COLLISION_STATIC);
			}
		}

		numGameObjects = levels[lev].numGameObjs + 1;
		int laserCounter = 0;

		for(int i = 0; i < levels[lev].numGameObjs; i++)
		{
			GameObjDesc& d = levels[lev].gameObjs[i];
			gameObjects[i + 1] = GameObj(d.x, d.y, d.dir, d.type);

			sassert(c.get(d.x, d.y) == COLLISION_NONE, "trying to place obj on static");
			c.set(d.x, d.y, i + 1);

			if(d.type == GAMEOBJ_Laser)
			{
				sassert(laserCounter < MAX_LASERS, "too many lasers");
				lasers[laserCounter].root()->init(d.x, d.y, 4, laserColors[laserCounter]);
				laserActive[laserCounter] = true;
				laserObjects[laserCounter] = i + 1;
				
				if(laserCounter == 0)
				{
					// the camera clamping in processInput will take care of positioning it correctly :P
					camera.x = d.x - 8;
					camera.y = d.y - 6;
				}

				laserCounter++;
			}
			else if(d.type == GAMEOBJ_Target || d.type == GAMEOBJ_SmallTarget)
				numTargets++;
		}

		sassert(laserCounter > 0, "must have at least one laser");

		projectLasers();

		maxCamX = max(-1, t.width() - 16 + 1);
		maxCamY = max(-1, t.height() - 12 + 1);

		consoleClear();
		printf("\n\n");
		desc = levels[lev].desc;

		gameLoop();
	}

	void projectLaser(int idx)
	{
		Laser& laser = lasers[idx];
		laser.freeChildren(laser.root());

		int dir = gameObjects[laserObjects[idx]].direction();
		int x = gameObjects[laserObjects[idx]].x();
		int y = gameObjects[laserObjects[idx]].y();

		nextSquare(dir, x, y);
		laserLoop(laser, laser.root(), dir, x, y, 4, laser.root()->color());
	}

	void projectLasers()
	{
		targetsSatisfied = 0;
		switchesSatisfied = 0;

		for(int i = 0; i < numGameObjects; i++)
			gameObjects[i].reset();

		for(int i = 0; laserActive[i]; i++)
			projectLaser(i);
	}

	void laserLoop(Laser& laser, Laser::Point* p, int dir, int x, int y, int width, rgb color)
	{
		int outDir1, outDir2;
		int outWidth1, outWidth2;
		rgb outColor1, outColor2;

		while(true)
		{
			if(x < 0 || x >= collision->width() || y < 0 || y >= collision->height())
			{
				laser.addChild(p, laser.point(x, y, width, color));
				break;
			}

			int type = collision->get(x, y);

			if(type == COLLISION_STATIC)
			{
				laser.addChild(p, laser.point(x, y, width, color));
				break;
			}
			else if(type == 0)
				nextSquare(dir, x, y);
			else
			{
				Laser::Point* coll = laser.point(x, y, width, color);
				laser.addChild(p, coll);

				int numChildren = gameObjects[type].accept(dir, width, color, outDir1, outWidth1, outColor1, outDir2, outWidth2, outColor2);

				if(numChildren == ACCEPT_WIN)
				{
					targetsSatisfied++;
					break;
				}
				else if(numChildren == 0)
					break;
				else if(numChildren == 1)
				{
					dir = outDir1;
					width = outWidth1;
					color = outColor1;
					p = coll;
					nextSquare(dir, x, y);
				}
				else
				{
					int tempx = x, tempy = y;
					nextSquare(outDir1, tempx, tempy);
					laserLoop(laser, coll, outDir1, tempx, tempy, outWidth1, outColor1);
					tempx = x;
					tempy = y;
					nextSquare(outDir2, tempx, tempy);
					laserLoop(laser, coll, outDir2, tempx, tempy, outWidth2, outColor2);
					break;
				}
			}
		}
	}

	void nextSquare(int dir, int& x, int& y)
	{
		switch(dir)
		{
			case DIR_RIGHT:      x++;      break;
			case DIR_DOWN_RIGHT: x++; y++; break;
			case DIR_DOWN:       y++;      break;
			case DIR_DOWN_LEFT:  x--; y++; break;
			case DIR_LEFT:       x--;      break;
			case DIR_UP_LEFT:    x--; y--; break;
			case DIR_UP:         y--;      break;
			case DIR_UP_RIGHT:   x++; y--; break;

			default: sassert(false, "onoz");
		}
	}

	void selectGameObj(int idx)
	{
		selectedObject = idx;
		selectedX = gameObjects[idx].x();
		selectedY = gameObjects[idx].y();
	}

	void deselectGameObj()
	{
		selectedObject = 0;
	}

	void enterZoom()
	{
		inputMode = INPUT_ZOOM;
		tempCamera = camera;

		int w = collision->width(), h = collision->height();

		if(w > 16 || h > 12)
		{
			camera = Camera(0, 0, w, h);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			float width, height;

			if(((float)h / w) < (3.0/4))
			{
				width = w * 2;
				height = width * (3.0/4);
			}
			else
			{
				height = h * 2;
				width = height * (4.0/3);
			}

			glOrtho(0, width, 0, height, 0.5, 20);
			glScalef(1, -1, 1);
			glTranslatef(0, -height, 0);

			glMatrixMode(GL_MODELVIEW);
		}
	}

	void leaveZoom()
	{
		inputMode = INPUT_CAMERA;
		camera = tempCamera;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 32, 0, 24, 0.5, 20);
		glScalef(1, -1, 1);
		glTranslatef(0, -24, 0);
		glMatrixMode(GL_MODELVIEW);
	}

	bool invalidTouchPos(touchPosition* p)
	{
		return (p->px < 0 || p->px > SCREEN_WIDTH || p->py < 0 || p->py > SCREEN_HEIGHT);
	}

	void updateInput()
	{
		scanKeys();
		keyHit = keysDown();
		keyReleased = keysUp();
		keyDown = keysHeld();
		keyRepeat = keysDownRepeat();
	}

	void processInput()
	{
		if(inputMode == INPUT_CAMERA)
		{
			if((keyRepeat & KEY_RIGHT) || (keyRepeat & KEY_A))
				camera.x++;

			if((keyRepeat & KEY_LEFT) || (keyRepeat & KEY_Y))
				camera.x--;

			if((keyRepeat & KEY_UP) || (keyRepeat & KEY_X))
				camera.y--;

			if((keyRepeat & KEY_DOWN)  || (keyRepeat & KEY_B))
				camera.y++;

			clamp(camera.x, -1, maxCamX);
			clamp(camera.y, -1, maxCamY);

			if(keyHit & (KEY_L | KEY_R))
			{
				enterZoom();
				return;
			}
				
			if(keyHit & KEY_TOUCH)
			{
				touchPosition dummy;

				touchRead(&touch);
				touchRead(&dummy);

				if(invalidTouchPos(&touch) || invalidTouchPos(&dummy))
					touchRead(&touch);

				int touchx = touch.px / 16 + camera.x;
				int touchy = touch.py / 16 + camera.y;
				
				if(touchx < 0 || touchx >= collision->width() || touchy < 0 || touchy >= collision->height())
				{
					// deselect
					deselectGameObj();
				}
				else
				{
					int type = collision->get(touchx, touchy);
					
					if(type == COLLISION_NONE || type == COLLISION_STATIC || !isMovableObj[gameObjects[type].type()])
					{
						// deselect
						deselectGameObj();
					}
					else
					{
						// select
						selectGameObj(type);
						inputMode = INPUT_MOVE;
					}
				}
			}
		}
		else if(inputMode == INPUT_ZOOM)
		{
			if(keyReleased & (KEY_L | KEY_R))
				leaveZoom();
		}
		else if(inputMode == INPUT_MOVE)
		{
			if(keyReleased & KEY_TOUCH)
			{
				projectLasers();
				inputMode = INPUT_CAMERA;
				return;
			}

			touchRead(&touch);
			int touchx = touch.px / 16 + camera.x;
			int touchy = touch.py / 16 + camera.y;

			// omfg hueg condition!
			// move the object if the touched position is:
			//     (1) in the playing field
			//     (2) different from the current position by one unit in either the x or y direction
			//     (3) not colliding with anything
			if( touchx >= 0 && touchx < collision->width() && touchy >= 0 && touchy < collision->height() &&
				(abs(touchx - selectedX) == 1 || abs(touchy - selectedY) == 1) &&
				collision->get(touchx, touchy) == COLLISION_NONE)
			{
				collision->set(selectedX, selectedY, COLLISION_NONE);
				selectedX = touchx;
				selectedY = touchy;
				gameObjects[selectedObject].position(touchx, touchy);
				collision->set(touchx, touchy, selectedObject);
				projectLasers();
				return;
			}

			if(keyHit & (KEY_LEFT | KEY_Y))
			{
				gameObjects[selectedObject].direction(wrapDir(gameObjects[selectedObject].direction() - 1));
				projectLasers();
				return;
			}
			else if(keyHit & (KEY_RIGHT | KEY_A))
			{
				gameObjects[selectedObject].direction(wrapDir(gameObjects[selectedObject].direction() + 1));
				projectLasers();
				return;
			}
		}
	}

	void drawPlayingField()
	{
		int tileWidth = staticObjects->width();
		int tileHeight = staticObjects->height();

		glPushMatrix();
		glTranslatef(0, 0, PLAYING_FIELD_DEPTH);
		glScalef(tileWidth * 2, tileHeight * 2, 1);
		glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(62));
		glColor3f(1, 1, 1);
		glBindTexture(0, floorTex);
	
		glBegin(GL_QUADS);
			glTexCoord2f(0,               0);                glVertex3f(0, 0, 0);
			glTexCoord2f(tileWidth / 4.0, 0);                glVertex3f(1, 0, 0);
			glTexCoord2f(tileWidth / 4.0, tileHeight / 4.0); glVertex3f(1, 1, 0);
			glTexCoord2f(0,               tileHeight / 4.0); glVertex3f(0, 1, 0);
		glEnd();
		glPopMatrix(1);
	}

	void drawLasers()
	{
		for(int i = 0; laserActive[i]; i++)
			lasers[i].draw();
	}

	void drawStaticObjects()
	{
		staticObjects->draw(camera);
	}

	void drawObjects()
	{
		for(int i = 1; i < numGameObjects; i++)
			gameObjects[i].draw(camera);

		if(selectedObject > 0)
		{
			ringColorIdx = (ringColorIdx + 1) % (sizeof(ringColorTable) / sizeof(int));
			int color = ringColorTable[ringColorIdx] + 8;

			GameObj& obj = gameObjects[selectedObject];

			glPolyFmt(POLY_ALPHA(15) | POLY_CULL_NONE | POLY_ID(59));
			glColor(ARGB16(1, color + 8, color + 8, 0));
			glBindTexture(0, ringTex);

			glPushMatrix();
				glTranslatef(obj.x() * 2 + 1, obj.y() * 2 + 1, MOVABLE_OBJECT_DEPTH);

				glBegin(GL_QUADS);
					glTexCoord2t16(inttot16(0),  inttot16(0));  glVertex3f(-2, 2, 0);
					glTexCoord2t16(inttot16(32), inttot16(0));  glVertex3f(2, 2, 0);
					glTexCoord2t16(inttot16(32), inttot16(31)); glVertex3f(2, -2, 0);
					glTexCoord2t16(inttot16(0),  inttot16(31)); glVertex3f(-2, -2, 0);
				glEnd();
			glPopMatrix(1);
		}
	}

	void drawBorder()
	{
		int tileWidth = staticObjects->width() + 2;
		int tileHeight = staticObjects->height() + 2;

		glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_ID(61));
		glColor3f(0, 0, 0);
		glBindTexture(0, 0);

		glPushMatrix();
			glTranslatef(0, 0, IMMOVABLE_OBJECT_DEPTH);

			glPushMatrix();
				glTranslatef(-2, -2, 0);
				glScalef(tileWidth * 2, 2, 1);

				glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(1, 0, 0);
					glVertex3f(1, 1, 0);
					glVertex3f(0, 1, 0);
				glEnd();
			glPopMatrix(1);

			glPushMatrix();
				glTranslatef(-2, -2, 0);
				glScalef(2, tileHeight * 2, 1);

				glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(1, 0, 0);
					glVertex3f(1, 1, 0);
					glVertex3f(0, 1, 0);
				glEnd();
			glPopMatrix(1);

			glPushMatrix();
				glTranslatef(tileWidth * 2 - 4, -2, 0);
				glScalef(2, tileHeight * 2, 1);

				glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(1, 0, 0);
					glVertex3f(1, 1, 0);
					glVertex3f(0, 1, 0);
				glEnd();
			glPopMatrix(1);

			glPushMatrix();
				glTranslatef(-2, tileHeight * 2 - 4, 0);
				glScalef(tileWidth * 2, 2, 1);

				glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(1, 0, 0);
					glVertex3f(1, 1, 0);
					glVertex3f(0, 1, 0);
				glEnd();
			glPopMatrix(1);
		glPopMatrix(1);
	}
	
	bool finished()
	{
		return targetsSatisfied == numTargets && switchesSatisfied == numSwitches;
	}

	void gameLoop()
	{
		while(!finished())
		{
			if(fadeValue > 0)
			{
				fadeValue--;
				REG_BLDY = fadeValue;
			}

			if(*desc)
				printf("%c", *desc++);

			swiWaitForVBlank();

			updateInput();
			processInput();

			camera.apply();
				drawPlayingField();
				drawLasers();
				drawStaticObjects();
				drawObjects();
				drawBorder();
			glFlush(0);
		}
		
		for(int i = 0; i < 60; i++)
			swiWaitForVBlank();
			
		for(int fadeValue = 0; fadeValue <= 16; fadeValue++)
		{
			REG_BLDY = fadeValue;
			swiWaitForVBlank();
		}
	}

	void titleScreen()
	{
		BG_PALETTE_SUB[0] = 0;
		lcdMainOnBottom();
		consoleDemoInit(); // black out upper screen
		videoSetMode(MODE_5_2D | DISPLAY_BG3_ACTIVE);
		vramSetBankA(VRAM_A_MAIN_BG);

		REG_BLDCNT = BLEND_SRC_BG3 | BLEND_FADE_BLACK;
		REG_BLDY = 16;

		REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0);
		REG_BG3PA = 1 << 8;
		REG_BG3PB = 0;
		REG_BG3PC = 0;
		REG_BG3PD = 1 << 8;

		u16* src = (u16*)titleBitmap;
		u16* dst = BG_BMP_RAM(0);

		for(int i = 0; i < 256 * 192; i++)
			*dst++ = *src++ | BIT(15);

		for(int i = 16; i >= 0; i--)
		{
			REG_BLDY = i;

			for(int j = 0; j < 4; j++)
				swiWaitForVBlank();
		}

		while(true)
		{
			swiWaitForVBlank();
			scanKeys();

			if(keysDown() & KEY_TOUCH)
				break;
		}

		for(int i = 0; i <= 16; i++)
		{
			REG_BLDY = i;

			for(int j = 0; j < 4; j++)
				swiWaitForVBlank();
		}
	}

	void thanksScreen()
	{
		BG_PALETTE_SUB[0] = 0;
		lcdMainOnBottom();
		consoleDemoInit(); // black out upper screen
		videoSetMode(MODE_5_2D | DISPLAY_BG3_ACTIVE);
		vramSetBankA(VRAM_A_MAIN_BG);

		REG_BLDCNT = BLEND_SRC_BG3 | BLEND_FADE_BLACK;
		REG_BLDY = 16;

		REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0);
		REG_BG3PA = 1 << 8;
		REG_BG3PB = 0;
		REG_BG3PC = 0;
		REG_BG3PD = 1 << 8;

		u16* src = (u16*)thanksBitmap;
		u16* dst = BG_BMP_RAM(0);

		for(int i = 0; i < 256 * 192; i++)
			*dst++ = *src++ | BIT(15);

		for(int i = 16; i >= 0; i--)
		{
			REG_BLDY = i;

			for(int j = 0; j < 4; j++)
				swiWaitForVBlank();
		}

		while(true)
		{
			swiWaitForVBlank();
			scanKeys();

			if(keysDown() & KEY_TOUCH)
				break;
		}

		for(int i = 0; i <= 16; i++)
		{
			REG_BLDY = i;

			for(int j = 0; j < 4; j++)
				swiWaitForVBlank();
		}
	}

	void run()
	{
		while(true)
		{
			titleScreen();
			init();

			for(uint i = 0; i < (sizeof(levels) / sizeof(Level)); i++)
				startLevel(i);

			thanksScreen();
		}
	}
};

Game g;

int main()
{
	// showIntro();

	g.run();

	return 0;
}