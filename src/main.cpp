// Core Libraries
#include <crtdbg.h>
#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

//Global variables are accessible from any context 
constexpr float FPS = 60.0f; // target frames per second
constexpr float DELAY_TIME = 1000.0f / FPS; // target time between frames in ms
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;
float deltaTime = 1.0f / FPS;x

bool isGameRunning = true;

// Anything with a star * to its right is a pointer type. SDL_Window* is a memory address of an SDL_Window
//Pointers can also be set to point to memory address 0, which means nothing. We call these NULL pointers.
//Computer memory is addressable by one number, like a homeaddress on one very , very long street.

SDL_Window* pWindow = nullptr; // assignin a pointer to mullptr means the address is 0
SDL_Renderer* pRenderer = nullptr; // NULL is the address 0. =NULL is essentiall the same as NULLptr


SDL_Texture* pMySprite = nullptr;
SDL_Rect mySpriteSrc;
SDL_Rect mySpriteDst;

struct background
{
public:

	SDL_Texture* pTexture;
	SDL_Rect src;
	SDL_Rect dst;


	// We can also create Member Functions that we call on.


	background()
	{
		pTexture = nullptr;
		src = { 0, 0, 0, 0 };
		dst = { 0, 0, 0 ,0 };

	}


	//a non-default constructor
	background(SDL_Renderer* renderer, const char* imageFilePath)
	{

		pTexture = IMG_LoadTexture(renderer, imageFilePath);

		if (pTexture == NULL)
		{
			std::cout << "Image Load Failed! " << SDL_GetError() << std::endl;
		}
		else
		{
			std::cout << "Image Load Succesful! " << std::endl;
		}

		if (SDL_QueryTexture(pTexture, NULL, NULL, &src.w, &src.h) != 0)
		{
			std::cout << "Query Texture Failed! " << SDL_GetError() << std::endl;
		}
		src.x = 0;
		src.y = 0;

		dst.x = 0;
		dst.y = 0;
		dst.w = src.w;
		dst.h = src.h;
	}


	void draw(SDL_Renderer* renderer)
	{
		int result = SDL_RenderCopy(renderer, pTexture, &src, &dst);
		if (result != 0)
		{
			std::cout << "Render Failed!" << SDL_GetError() << std::endl;
		}
	}

};

background renderBackground = background(); // call the default constructor



struct userPlayer 
{
public:

SDL_Texture* usership;
SDL_Rect src;
SDL_Rect dst;


// We can also create Member Functions that we call on.


	userPlayer()
	{
		std::cout << "Defualt Constructor" << std::endl;
		usership = nullptr;
		src = { 0, 0, 0, 0 };
		dst = { 0, 0, 0 ,0 };

	}


	//a non-default constructor
	userPlayer(SDL_Renderer* renderer, const char* imageFilePath)
	{
		std::cout << "user player Constructor" << std::endl;
		usership = IMG_LoadTexture(renderer, imageFilePath);

		if (usership == NULL)
		{
			std::cout << "Image Load Failed! " << SDL_GetError() << std::endl;
		}
		else
		{
			std::cout << "Image Load Succesful! " << std::endl;
		}

		if ( SDL_QueryTexture(usership, NULL, NULL, &src.w, &src.h) != 0)
		{
			std::cout << "Query Texture Failed! " << SDL_GetError() << std::endl;
		}
		src.x = 0;
		src.y = 0;

		dst.x = 0;
		dst.y = 0;
		dst.w = src.w;
		dst.h = src.h;
	}


void draw(SDL_Renderer* renderer)
{
	int result = SDL_RenderCopy(renderer, usership, &src, &dst);
	if (result != 0)
	{
		std::cout << "Render Failed!" << SDL_GetError() << std::endl;
	}
}

};

userPlayer renderUserPlayer = userPlayer(); // call the default constructor
userPlayer enemy1;

struct obsticle
{
public:

	SDL_Texture* object;
	SDL_Rect src;
	SDL_Rect dst;


	// We can also create Member Functions that we call on.


	obsticle()
	{
		std::cout << "Defualt Constructor" << std::endl;
		object = nullptr;
		src = { 0, 0, 0, 0 };
		dst = { 0, 0, 0 ,0 };

	}


	//a non-default constructor
	obsticle(SDL_Renderer* renderer, const char* imageFilePath)
	{
		std::cout << "user player Constructor" << std::endl;
		object = IMG_LoadTexture(renderer, imageFilePath);

		if (object == NULL)
		{
			std::cout << "Image Load Failed! " << SDL_GetError() << std::endl;
		}
		else
		{
			std::cout << "Image Load Succesful! " << std::endl;
		}

		if (SDL_QueryTexture(object, NULL, NULL, &src.w, &src.h) != 0)
		{
			std::cout << "Query Texture Failed! " << SDL_GetError() << std::endl;
		}
		src.x = 0;
		src.y = 0;

		dst.x = 0;
		dst.y = 0;
		dst.w = src.w;
		dst.h = src.h;
	}


	void draw(SDL_Renderer* renderer)
	{
		int result = SDL_RenderCopy(renderer, object, &src, &dst);
		if (result != 0)
		{
			std::cout << "Render Failed!" << SDL_GetError() << std::endl;
		}
	}

};

obsticle renderObject = obsticle();
obsticle rock1;
obsticle lighthouse;

struct bullet
{
public:

	SDL_Texture* ammo;
	SDL_Rect src;
	SDL_Rect dst;


	// We can also create Member Functions that we call on.


	bullet()
	{
		ammo = nullptr;
		src = { 0, 0, 0, 0 };
		dst = { 0, 0, 0 ,0 };

	}


	//a non-default constructor
	bullet(SDL_Renderer* renderer, const char* imageFilePath)
	{

		ammo = IMG_LoadTexture(renderer, imageFilePath);

		if (ammo == NULL)
		{
			std::cout << "Image Load Failed! " << SDL_GetError() << std::endl;
		}
		else
		{
			std::cout << "Image Load Succesful! " << std::endl;
		}

		if (SDL_QueryTexture(ammo, NULL, NULL, &src.w, &src.h) != 0)
		{
			std::cout << "Query Texture Failed! " << SDL_GetError() << std::endl;
		}
		src.x = 0;
		src.y = 0;

		dst.x = 0;
		dst.y = 0;
		dst.w = src.w;
		dst.h = src.h;
	}


	void draw(SDL_Renderer* renderer)
	{
		int result = SDL_RenderCopy(renderer, ammo, &src, &dst);
		if (result != 0)
		{
			std::cout << "Render Failed!" << SDL_GetError() << std::endl;
		}
	}

};

bullet renderAmmo = bullet(); // call the default constructor


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
	//loading all textures...
	//SDL_Texture * IMG_LoadTexture(SDL_Renderer *renderer, const char *file)
	renderBackground = background(pRenderer, "../Assets/textures/Still_water_image.png");


	int backgroundWidth = renderBackground.src.w ;
	int backgroundHeight = renderBackground.src.h ;

	renderBackground.dst.w = backgroundWidth;
	renderBackground.dst.h = backgroundHeight;

	/////////////////////////////////////////////////

	renderUserPlayer = userPlayer(pRenderer, "../Assets/textures/usership.png");


	int userWidth = renderUserPlayer.src.w / 10;
	int userHeight = renderUserPlayer.src.h / 10;

	renderUserPlayer.dst.w =  userWidth;
	renderUserPlayer.dst.h = userHeight;
	renderUserPlayer.dst.x = (WINDOW_WIDTH / 8); //start with left eighth
	renderUserPlayer.dst.y = (WINDOW_HEIGHT / 2) - userHeight/2; // in middle

	enemy1 = userPlayer(pRenderer, "../Assets/textures/enemy1.png");
	enemy1.dst.x = 1200;
	enemy1.dst.y = 320;

	/////////////////////////////////////////////////

	renderObject = obsticle(pRenderer, "../Assets/textures/kelp.png");


	int objectWidth = renderObject.src.w /2;
	int objectHeight = renderObject.src.h /2;

	renderObject.dst.w = objectWidth;
	renderObject.dst.h = objectHeight;
	renderObject.dst.x = (WINDOW_WIDTH /  2); //start with left eighth
	renderObject.dst.y = (WINDOW_HEIGHT / 7) ; // and up


	rock1 = obsticle(pRenderer, "../Assets/textures/rock1.png");
	rock1.dst.x = 700;
	rock1.dst.y = 200;

	lighthouse = obsticle(pRenderer, "../Assets/textures/lighthouse.png");
	
	int lighthouseWidth = lighthouse.src.w / 4;
	int lighthouseHeight = lighthouse.src.h / 4;

	lighthouse.dst.w = lighthouseWidth;
	lighthouse.dst.h = lighthouseHeight;
	lighthouse.dst.x = 1000;
	lighthouse.dst.y = 450;
	

	///////////////////////////////////////////////////

	renderAmmo = bullet(pRenderer, "../Assets/textures/cannonball.png");


	int ammoWidth = renderAmmo.src.w / 2;
	int ammoHeight = renderAmmo.src.h / 2;

	renderAmmo.dst.w = ammoWidth;
	renderAmmo.dst.h = ammoHeight;
	renderAmmo.dst.x = (WINDOW_WIDTH / 4); //start with left eighth
	renderAmmo.dst.y = (WINDOW_HEIGHT / 2); // and up

}


// player input variables
bool isUpPressed = false;
bool isDownPressed = false;
bool isShootPressed = false;
bool isForwardPressed = false;
bool isBackPressed = false;
const float playerSpeedPx = 600.0f; //pixels per second
const float playerShootCoolDownDuration = 0.5f; // time between shots
float playerShootCoolDownTimer = 0.0f; //determines when we can shoot again


void Input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case (SDL_KEYDOWN):
			
			switch (event.key.keysym.scancode)
			{
			case (SDL_SCANCODE_W):
				isUpPressed = true;

				break;

			case(SDL_SCANCODE_S):
				isDownPressed = true;

				break;

			case(SDL_SCANCODE_A):
				isBackPressed = true;

				break;

			case (SDL_SCANCODE_D):
				isForwardPressed = true;

				break;

			case(SDL_SCANCODE_SPACE):
				isShootPressed = true;

				break;
			}
			break;
		}
		
		switch (event.type)
		{
		case(SDL_KEYUP):
			switch (event.key.keysym.scancode)
			{
			case(SDL_SCANCODE_W):
				isUpPressed = false;

				break;

			case (SDL_SCANCODE_S):
				isDownPressed = false;

				break;

			case (SDL_SCANCODE_A):
				isBackPressed = false;

				break;

			case(SDL_SCANCODE_D):
				isForwardPressed = false;

				break;

			case (SDL_SCANCODE_SPACE):
				isShootPressed = false;

				break;
			}
		}
	}



}


void Update()
{

	if (isUpPressed)
	{
		renderUserPlayer.dst.y -= playerSpeedPx / FPS;
	}
	if (isDownPressed)
	{
		renderUserPlayer.dst.y += playerSpeedPx * deltaTime;

	}
	if (isForwardPressed)
	{
		renderUserPlayer.dst.x += playerSpeedPx / FPS;

	}
	if (isBackPressed)
	{
		renderUserPlayer.dst.x -= playerSpeedPx * deltaTime;

	}
	if (isShootPressed)
	{
		//if player is off cooldown
		if (playerShootCoolDownTimer <= 0.0f)
		{
			std::cout << "Shoot!" << std::endl;

			renderAmmo.dst.x = renderUserPlayer.dst.x + renderUserPlayer.dst.h - renderAmmo.dst.w;
			renderAmmo.dst.y = renderUserPlayer.dst.y + renderUserPlayer.dst.w/2;

			//reset cool down timer
			playerShootCoolDownTimer = playerShootCoolDownDuration;

		}


	}
	
	//tick down shoot cooldown
	playerShootCoolDownTimer -= deltaTime;

	//move bullet
	renderAmmo.dst.x += 5;


	//width
	if (renderUserPlayer.dst.x >= WINDOW_WIDTH - renderUserPlayer.dst.w)
	{
		renderUserPlayer.dst.x = WINDOW_WIDTH - renderUserPlayer.dst.w;
	}

	if (renderUserPlayer.dst.x <= WINDOW_WIDTH * 0)
	{
		renderUserPlayer.dst.x = (WINDOW_HEIGHT * 0);
	}

	if (renderUserPlayer.dst.x <= 0 + 10)
	{
		renderUserPlayer.dst.x = 10;
	}

	//height
	if (renderUserPlayer.dst.y >= WINDOW_HEIGHT - renderUserPlayer.dst.h)
	{
		renderUserPlayer.dst.y = WINDOW_HEIGHT - renderUserPlayer.dst.h;
	}

	if (renderUserPlayer.dst.y <= WINDOW_HEIGHT * 0)
	{
		renderUserPlayer.dst.y = (WINDOW_HEIGHT * 0);
	}

	if (renderUserPlayer.dst.y <= 0 + 10)
	{
		renderUserPlayer.dst.y = 10;
	}

	//making the enemy move 
	enemy1.dst.x = enemy1.dst.x - 1;


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

	// calling on the draw function for background
	renderBackground.draw(pRenderer);

	// calling on user ship
	renderUserPlayer.draw(pRenderer);

	//drawing enemy
	enemy1.draw(pRenderer);

	//calling on first object
	renderObject.draw(pRenderer);

	//calling on rock1
	rock1.draw(pRenderer);

	//calling on cannonball
	renderAmmo.draw(pRenderer);

	// calling on lighthouse
	lighthouse.draw(pRenderer);

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

