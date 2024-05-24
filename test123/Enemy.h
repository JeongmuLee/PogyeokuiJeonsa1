#ifndef ENEMEY_H_
#define ENEMY_H_

#include "Entity.h"

class Enemy :public Entity
{
public:
	Enemy(SDL_Renderer* renderer);
	~Enemy();

	void Update(float delta);
	void Render(float delta);

private:
	SDL_Texture* texture;
};
#endif // !ENEMEY_H_
