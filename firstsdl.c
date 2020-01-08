#include <SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
	//初始化窗口
	SDL_Window *window = NULL;
	SDL_Renderer *render = NULL;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_Log("Hello world");
	
	window = SDL_CreateWindow("SDL2 Window", 
			  200, 
			  400,
		       	  640,
			  480,
			  SDL_WINDOW_SHOWN);
	if(!window){
		SDL_Log("Failed to Create window!");
		goto __EXIT;
	}
	render = SDL_CreateRenderer(window, -1, 0);
	if(!render) {
                  SDL_Log("Failed to Create Render");
                  goto __DWINDOW;
         }

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);

	SDL_RenderClear(render);
	
	SDL_RenderPresent(render);

	// SDL_Delay(30000);

	bool isquit = false;
	SDL_Event event;
	while (!isquit) {
    	if (SDL_PollEvent( & event)) {
        	if (event.type == SDL_QUIT) {
            	isquit = true;
        	}
    	}
	}

__DWINDOW:
	SDL_DestroyWindow(window);

__EXIT:
	SDL_Quit();
	return 0;
}
