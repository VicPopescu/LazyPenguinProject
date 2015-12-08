#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <map>
#include "SDL.h"
#include <SDL_image.h>



class TextureManager
{
    public:
        TextureManager();
        ~TextureManager();

        bool load(std::string fileName,std::string id, SDL_Renderer* pRenderer);

        // draw
        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
        //draw frame
        void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


        std::map<std::string, SDL_Texture*> m_textureMap;




    protected:
    private:
};

#endif // TEXTUREMANAGER_H
