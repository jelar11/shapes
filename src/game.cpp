#include "game.h"

#include <iostream>

game::game()
{
    mRunning = true;
}

void game::OnExecute()
{
    OnInit();

    SDL_Event event;
    while( mRunning ){

        while(SDL_PollEvent( &event )) {
            OnEvent( &event );
        }

        OnLoop();
        OnRender();
    }

    OnCleanUp();

}
bool game::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Init error";
        return false;
    }
    
    //Create window
    if( (mWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL )) == NULL ){
        std::cout << "Create Window error";
        return false;
    }
//     mScreenSurface = SDL_GetWindowSurface( mWindow );

    if( (mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL ){
        std::cout << "Create Render Error";
        return false;
    }


    return true;
}

void game::OnCleanUp()
{
    SDL_Quit();
}


void game::OnLoop()
{
    std::cout << "Loop" << std::endl;
}

void game::OnRender()
{
    std::cout << "render" << std::endl;

    // Clear screen
    SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear( mRenderer );

    SDL_Rect fillRect = { 640/ 4, 480/ 4, 640/ 2, 480/ 2 };
    SDL_SetRenderDrawColor( mRenderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( mRenderer, &fillRect ); 

    // Update screen
    SDL_RenderPresent( mRenderer );

    SDL_Delay(100);
}

void game::OnEvent(SDL_Event* event)
{
    if(event->type == SDL_QUIT) {
        mRunning = false;
    }

    if( event->type == SDL_KEYDOWN){
        switch( event->key.keysym.sym ){
            // Exit/quit
            case SDLK_ESCAPE:
            case SDLK_e:
            case SDLK_q:
                mRunning = false;
            break;

        }
    }
    std::cout << "event" << std::endl;
}
