#ifndef GAME_H_
#define	GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#define FPS_DELEY 500
#define AI_SPEED 400

class Game
{
public:
	Game();
	~Game();

	bool Init();
	void Run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	unsigned int lasttick, fpstick, fps, framecount;

	Board* board;
	Player* player;
	Enemy* enemy;
	Bullet* bullet;

	void Clean();
	void Update(float delta, SDL_Event e);
	void Render(float delta);

	void NewGame();

	void SetPlayerX(float x);
	void SetPlayerY(float y);
	void SetPlayerAngle(float a);
	void SetEnemyX(float x);
	void SetEnemyY(float y);
	void SetEnemyAngle(float a);
	void CheckCollisions();
	float GetDamage(int index, float hity);

	void AI(float delta);
};

#endif