#define NANOVG_GLES2_IMPLEMENTATION
#include <stdio.h>
#include <iostream>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <SDL/SDL.h>
#include "nanovg.h"
#include "nanovg.c"
#include "nanovg_gl.h"
#include "nanovg_gl_utils.h"

using namespace std;

struct NVGcontext* vg;
SDL_Surface *screen;
/*
int main() {
    vg = nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
    nvgBeginPath(vg);
    nvgMoveTo(vg, 0.0f, 0.0f);
    nvgLineTo(vg, 100.0f, 100.0f);
    nvgStrokeColor(vg, nvgRGBA(255, 0, 0, 255));
    nvgStrokeWidth(vg, 1.0f);
    nvgStroke(vg);
    return 1;
}
 */


int main(){

    //SDL_Init(SDL_INIT_VIDEO);
   // screen = SDL_SetVideoMode(100, 100, 32, SDL_OPENGL);
    //initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0)
    {
        screen = SDL_SetVideoMode(100, 100, 0, SDL_OPENGL);
        if (screen == NULL)
        {
            cerr << "Could not set video mode: " << SDL_GetError() << endl;
            return 0;
        }
    }
    else
    {
        cerr << "Could not initialize SDL: " << SDL_GetError() << endl;
        return 0;
    }

    vg = nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

    nvgBeginFrame(vg, 100.0f, 100.0f, 1.0f);

    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

    nvgBeginPath(vg);
    nvgMoveTo(vg, 0.0f, 0.0f);
    nvgLineTo(vg, 100.0f, 100.0f);
    nvgStrokeColor(vg, nvgRGBA(0, 0, 0, 255));
    nvgStrokeWidth(vg, 1.0f);
    nvgStroke(vg);

    nvgEndFrame(vg);

    return 1;
}
