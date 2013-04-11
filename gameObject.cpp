#include "gameObject.h"


bool GameObject::isCollidingWith(GameObject* other)
{
	//Vec2 difference;
	//float distance = (position - other->getPosition()).length();
	//float collisionDistance = radius + other->getRadius();
	//return distance < collisionDistance;

	return bbImagesCollide(	getImage(),			getPosition().x,		getPosition().y,		0,
							other->getImage(),	other->getPosition().x,	other->getPosition().y,	0);
}

Vec2 GameObject::getPosition()
{
	return position;
}

void GameObject::onCollision(GameObject* other)
{


}

void GameObject::fire(World* world)
{

}

void GameObject::spawn(World* world)
{

}

bool GameObject::wasKilled()
{
	return m_wasKilled;
}

void GameObject::setKilled()
{
	m_wasKilled = true;
}

float GameObject::getRadius()
{
	return radius;
}

void GameObject::queueForDestruction()
{
	needsDestruction = true;
}

bool GameObject::NeedsDestruction()
{
	return needsDestruction;
}