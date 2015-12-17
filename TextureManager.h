#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <map>
#include <string>
#include "SDL.h"



class TextureManager
{
public:

        static TextureManager* Instance(){

        if(s_pInstance == 0){

            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;

        }


        bool load(std::string fileName,std::string id, SDL_Renderer* pRenderer);

        // draw
        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
        //draw a specific frame
        void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


        std::map<std::string, SDL_Texture*> m_textureMap;


protected:
private:
        //private constructor, because we want this class to be used as a singleton
        TextureManager();
        ~TextureManager();

        //singleton
        static TextureManager* s_pInstance;



};

typedef TextureManager TheTextureManager;

#endif // TEXTUREMANAGER_H
