#include "Entity.hpp"

Entity::Entity(float x, float y, SDL_Texture* tex)
	: _vec(Vector2(x, y)), _texture(tex)
{
	_currentFrame.x = 0;
	_currentFrame.y = 0;
	_currentFrame.w = 32;
	_currentFrame.h = 32;
}

Entity::~Entity()
{
}

SDL_Texture* Entity::GetTexture() const
{
	return _texture;
}

SDL_Rect Entity::GetCurrentFrame() const
{
	return _currentFrame;
}

Vector2 Entity::GetCurrentPosition() const
{
	return _vec.Get();
}

void Entity::SetPosition(Vector2 newPosition)
{
	Vector2 pos = GetCurrentPosition() + newPosition;
	pos.x = std::clamp(pos.x, 0.1f, Constants::Width - (float)_currentFrame.w);
	pos.y = std::clamp(pos.y, 0.1f, Constants::Height - (float)_currentFrame.h);

	_vec.Set(pos);

	Vector2 currentPos = GetCurrentPosition();
	std::cout << "current pos: x" << currentPos.x << " y " << currentPos.y << std::endl;
}

void Entity::Update()
{
}

