#include "Game.h"


Game::Game()
{
	window = 0;
	renderer = 0;
}

Game::~Game()
{

}

bool Game::Init()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Example",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!window)
	{
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		return false;
	}

	lasttick = SDL_GetTicks();
	fpstick = lasttick;
	fps = 0;
	framecount = 0;

	return true;
}

void Game::Clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Game::Run()
{
	board = new Board(renderer);
	player = new Player(renderer);
	enemy = new Enemy(renderer);

	NewGame();

	while (1)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}

		unsigned int curtick = SDL_GetTicks();
		float delta = (curtick - lasttick) / 1000.0f;
		if (curtick - fpstick >= FPS_DELEY)
		{
			fps = framecount * (1000.0f / (curtick - fpstick));
			fpstick = curtick;
			framecount = 0;
			char buf[100];
			snprintf(buf, 100, "test123(fps: %u)", fps);
			SDL_SetWindowTitle(window, buf);
		}
		else
		{
			framecount++;
		}
		lasttick = curtick;

		if (SDL_MOUSEBUTTONDOWN == true && e.button.button == SDL_BUTTON_LEFT)
		{
			bullet = new Bullet(renderer);

		}

		Update(delta, e);
		Render(delta);
	}//while(1)

	delete board;
	delete player;
	delete enemy;

}

void Game::NewGame()
{
	SetPlayerX(board->width / 2 - player->width / 2);
	SetPlayerY(0);
	SetPlayerAngle(45);

	SetEnemyX(board->width / 2 - player->width / 2);
	SetEnemyY(0);
	SetEnemyAngle(45);
}

void Game::Update(float delta, SDL_Event e)
{
	if (SDL_KEYDOWN == true && (e.key.keysym.sym == 87 or e.key.keysym.sym == 119))
	{
		player->angle += 0.5;
	}
	else if (SDL_KEYDOWN == true && (e.key.keysym.sym == 83 or e.key.keysym.sym == 115))
	{

	}
	

	CheckCollisions();
	AI(delta);

	board->Update(delta);
	player->Update(delta);
}

void Game::SetPlayerX(float x)
{
	float newx;
	if (x < board->boundleft)
	{
		newx = board->boundleft;
	}
	else if (x + player->width > board->boundright)
	{
		newx = board->boundright - player->width;
	}
	else
	{
		newx = x;
	}

	player->x = newx;
}

void Game::SetPlayerY(float y)
{
	float newy;
	if (y < board->boundtop)
	{
		newy = board->boundtop;
	}
	else if (y + player->height > board->boundbottom)
	{
		newy = board->boundbottom - player->height;
	}
	else
	{
		newy = y;
	}

	player->y = newy;
}

void Game::SetPlayerAngle(float a)
{
	float newa;
	if (a < 0)
	{
		newa = 0;
	}
	else if (a > 90)
	{
		newa = 90;
	}
	else
	{
		newa = a;
	}

	player->angle = newa;
}

void Game::CheckCollisions()
{
	if
}