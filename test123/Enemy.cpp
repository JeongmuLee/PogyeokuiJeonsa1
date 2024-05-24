#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer) :Entity(renderer)
{
	SDL_Surface* surface = IMG_Load("Enemy.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	width = 50;
	height = 50;

	x = 0;
	y = 0;
	angle = 45;
}

Enemy::~Enemy()
{
	SDL_DestroyTexture(texture);
}

void Enemy::Update(float delta)
{

}

void Enemy::Render(float delta)
{
	SDL_Rect rect;
	rect.x = (int)(x + 0.5f);
	rect.y = (int)(y + 0.5f);
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer, texture, 0, &rect);
}