#include<SDL.h>
#include<iostream>
#include<SDL_image.h>

// Size of the SDL window
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char * argv[]) {

	// initialization pointers for Canvas(imageSurface) and window (windowSurface)
	SDL_Surface *imageSurface = NULL;
	SDL_Surface *windowSurafe = NULL;

	// inicialization SDL
	if (SDL_Init(SDL_INIT_EVERYTHING)<0)
		std::cout << "BAD"; 
	
	// create SDL Window
	SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

	windowSurafe = SDL_GetWindowSurface(window);


	if (NULL == window)
	{
		std::cout << "Window not created" << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}
	//return EXIT_SUCCESS;

	if (!(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG))
	{
		std::cout << "Fail to initialise SDL_image for PNG files: " << IMG_GetError() << std::endl;
	}


	// WindowEvent is a canvas to put some image on
	SDL_Event windowEvent;

	//imageSurface = SDL_LoadBMP("hello_world.bmp");		// Loading BMP
	imageSurface = IMG_Load("tex.png");					// Loading IMG

	//Check if imageSurface(canvas) is ok
	if (NULL == imageSurface)
	{
		std::cout << "SDL could not load image! SDL Errror: " << SDL_GetError() << std::endl;
	}

	// -------- Do not know what is it ! -----------
	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
				break;
		}
		SDL_BlitSurface(imageSurface, NULL, windowSurafe, NULL);

		SDL_UpdateWindowSurface(window);
	}
	// ------------------------------------

	// Delete/free surface we used
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurafe);

	// put the pointers to NULL
	imageSurface = NULL;
	windowSurafe = NULL;

	SDL_DestroyWindow(window);
	SDL_Quit();

	
	return 0;
}

