#include "Bullet.h"
#define Pi 3.141592
Bullet::Bullet(SDL_Renderer* renderer) : Entity(renderer)
{
	SDL_Surface* surface = IMG_Load("bullet.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	x = 0;
	y = 0;
	width = 24;
	height = 24;

	SetDirection(45);
};

Bullet::~Bullet()
{
	SDL_DestroyTexture(texture);
}

void Bullet::Update(float delta)
{
	x += dirx * delta;
	y = diry * delta - g * pow(delta, 2);
}

void Bullet::Render(float delta)
{
	SDL_Rect rect;
	rect.x = (int)(x + 0.5f);
	rect.y = (int)(y + 0.5f);
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer, texture, 0, &rect);
}

void Bullet::SetDirection(float a)
{
	this->dirx = BULLET_SPEED * cos(a * Pi / 180);
	this->diry = BULLET_SPEED * sin(a * Pi / 180);
}
