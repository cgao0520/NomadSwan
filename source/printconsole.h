#pragma once
#include <3ds/gfx.h>

struct PrintConsole {
    int cursorX, cursorY;
    int prevCursorX, prevCursorY;
    int consoleWidth, consoleHeight;
    gfxScreen_t screen;
    u8* framebuffer;
    bool redraw;
    
	int windowX;		/*!< Window X location in tiles (not implemented) */
	int windowY;		/*!< Window Y location in tiles (not implemented) */
	int windowWidth;	/*!< Window width in tiles (not implemented) */
	int windowHeight;	/*!< Window height in tiles (not implemented) */    
};

void consoleInitBottom();
void consoleSetScreen(gfxScreen_t screen);
void consoleCheckFramebuffers();

void gfxMySwapBuffers();
void consoleSwitchBuffers();
void consoleFlush();

int consoleGetWidth();
int consoleGetHeight();
void clearConsole();

const int CHAR_WIDTH = 8;
const int CHAR_HEIGHT = 8;

extern const int TOP_SCREEN_WIDTH;
extern const int TOP_SCREEN_HEIGHT;

extern const int BOTTOM_SCREEN_WIDTH;
extern const int BOTTOM_SCREEN_HEIGHT;

