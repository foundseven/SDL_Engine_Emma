// Core Libraries
#include <crtdbg.h>
#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>

//Global variables are accessible from any context 
constexpr float FPS = 60.0f; // target frames per second
constexpr float DELAY_TIME = 1000.0f / FPS; // target time between frames in ms
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;


bool isGameRunning = true;

// Anything with a star * to its right is a pointer type. SDL_Window* is a memory address of an SDL_Window
//Pointers can also be set to point to memory address 0, which means nothing. We call these NULL pointers.
//Computer memory is addressable by one number, like a homeaddress on one very , very long street.

SDL_Window* pWindow = nullptr; // assignin a pointer to mullptr means the address is 0
SDL_Renderer* pRenderer = nullptr; // NULL is the address 0. =NULL is essentiall the same as NULLptr
SDL_Texture* pMySprite = nullptr;
SDL_Rect mySpriteSrc;
SDL_Rect mySpriteDst;


//init is short for initialize, we are setting p the game window, start SDL feature, ect
bool Init()
{
	
	SDL_Init(SDL_INIT_EVERYTHING);

	// Display Main SDL Window
	// get pointer to SDL_WINDOW object

	pWindow = SDL_CreateWindow("Thornewell_101466157", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0
		  // (borderless) SDL_WINDOW_MAXIMIZED | SDL_WINDOW_BORDERLESS 
		 );


	if (pWindow == NULL) //if the window creations failed...
	{
		std::cout << "Window Creation Failed! " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "Window Creation Succesful! " << std::endl;
	}



	//get pointer to SDL_Renderer object for use of drawing sprites
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	if (pRenderer == NULL) 
	{
		std::cout << "Renderer Creation Failed! " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "Renderer Creation Succesful! " << std::endl;
	}
	return true;
}


void load()
{
	//load texture...
	//SDL_Texture * IMG_LoadTexture(SDL_Renderer *renderer, const char *file)

	pMySprite = IMG_LoadTexture(pRenderer, "../Assets/textures/enterprise.png");

	if (pMySprite == NULL)
	{
		std::cout << "Image Load Failed! " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "Image Load Succesful! " << std::endl;
	}


	mySpriteSrc.x = 0;
	mySpriteSrc.y = 0;
	mySpriteSrc.w = 643;
	mySpriteSrc.h = 296;

	int shipWidth = mySpriteSrc.w / 4;
	int shipHeight = mySpriteSrc.h / 4;

	mySpriteDst.w = shipWidth;
	mySpriteDst.h = shipHeight;
	mySpriteDst.x = (WINDOW_WIDTH / 8); //start with left eighth
	mySpriteDst.y = (WINDOW_HEIGHT / 2) - shipHeight/2; // in middle
}

void Input()
{

}


void Update()
{
	mySpriteDst.x = mySpriteDst.x + 1;
}

void Draw()
{
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 20, 255);
	SDL_RenderClear(pRenderer);

	int result = SDL_RenderCopy(pRenderer, pMySprite, &mySpriteSrc, &mySpriteDst);
	if (result != 0)
	{
		std::cout << "Render Failed!" << SDL_GetError() << std::endl;
	}

	//show the back buffer
	SDL_RenderPresent(pRenderer);
}
	
 
/**
 * \brief Program Entry Point
 */
int main(int argc, char* args[])
{

	// show and position the application console
	AllocConsole();
	auto console = freopen("CON", "w", stdout);
	const auto window_handle = GetConsoleWindow();
	MoveWindow(window_handle, 100, 700, 800, 200, TRUE);


	isGameRunning = Init();

	load();

	//show back buffer which we have been drawing to prior. this is part of a common rendering tech called double buffering.
	SDL_RenderPresent(pRenderer);


	// Main Game Loop, each iteration of the loop is one frame of the game
	while (isGameRunning)
	{
		//get time in ms at the start of the time
		const auto frame_start = static_cast<float>(SDL_GetTicks());

		//CALLING Three functions in sequence...
		Input();    //input from player
		Update();   //update game state
		Draw();     //draw to screen
		
		if (const float frame_time = static_cast<float>(SDL_GetTicks()) - frame_start; //statement excecuted before if statement
			frame_time < DELAY_TIME) //if statement condition (if we completed our input-update-draw in less than target time
		{
			//wait for the difference, do nothing
			SDL_Delay(static_cast<int>(DELAY_TIME - frame_time));
		}

		// delta time
		const auto delta_time = (static_cast<float>(SDL_GetTicks()) - frame_start) / 1000.0f;
		
	
	}
	getchar();
	return 0;
}

