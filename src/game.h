
#include <SDL2/SDL.h>

class game
{
private:
    bool mRunning;
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    SDL_Surface *mScreenSurface;


public:
    game();

    void OnExecute();
    bool OnInit();
    void OnLoop();
    void OnRender();
    void OnEvent(SDL_Event* Event);
    void OnCleanUp();

};