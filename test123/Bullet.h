#ifndef BULLET_H_
#define BULLET_H_

#include "Entity.h"
#include <math.h>
#define g 100
const float BULLET_SPEED = 900;

class Bullet : public Entity
{
public:
	Bullet(SDL_Renderer* renderer);
	~Bullet();

	void Update(float delta);
	void Render(float delta);

	void SetDirection(float angle);

	float dirx, diry;

private:
	SDL_Texture* texture;
};
#endif // !BULLET_H_
