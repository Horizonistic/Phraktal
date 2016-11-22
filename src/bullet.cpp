#include "bullet.h"

Bullet::Bullet(Vector2 pos) : Mimic()
{
    this->pos = pos;
}

void Bullet::setDestination(Vector2 destination)
{
    this->destination = destination;
    this->velocity.x = this->destination.x - this->pos.x;
    this->velocity.y = this->destination.y - this->pos.y;
    this->velocity.normalize();
    this->angle = (std::atan2(this->destination.x - this->pos.y, this->destination.y - this->pos.x) * (180 / PI)) - 90;
    if (this->angle < 0)
    {
        this->angle = 360 - (-angle);
    }
}

bool Bullet::inFrame()
{
    return !(this->pos.x < 1080 + this->texture->getWidth() &&
            this->pos.x > 0 - this->texture->getWidth() &&
            this->pos.y < 720 + this->texture->getHeight() &&
            this->pos.y > 0 - this->texture->getHeight());
}

void Bullet::update(float dTime)
{
    this->oldPos.x = this->pos.x;
    this->oldPos.y = this->pos.y;
    this->pos.x += this->velocity.x * dTime * MAX_SPEED;
    this->pos.y += this->velocity.y * dTime * MAX_SPEED;
}

void Bullet::render()
{
    this->texture->renderTexture((int) this->pos.x, (int) this->pos.y, NULL, this->angle, NULL, SDL_FLIP_NONE);
}