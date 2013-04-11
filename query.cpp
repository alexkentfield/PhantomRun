#include "query.h"

Query& Query::select(GameObjectType types[])
{
	for (int i = 0; i < sizeof(types); i++)
	{
		GameObjectVector obj = m_world->GetGameObjects(types[i]);

		for (GameObjectVector::iterator it = obj.begin(); it != obj.end(); it++)
		{
			m_results.push_back(*it);
		}

	}
	return *this;
}

GameObjectVector Query::getResults()
{
	return m_results;
}

Query& Query::inRect(float left, float right, float top, float bottom)
{
	GameObjectVector temp;
	for(GameObjectVector::iterator it = m_results.begin(); it != m_results.end(); it++)
	{
		GameObject* obj = *it;
		int x = obj->getPosition().x;
		int y = obj->getPosition().y;

		if (x >= left && x <= right && y >= top && y <= bottom)
		{
			temp.push_back(obj);
		}
	}

	m_results = temp;
	return *this;
}

GameObject* Query::nearest(Vec2 position)
{
	GameObject* result = 0;
	float resultDistance = 9999.9f;

	for(GameObjectVector::iterator it = m_results.begin(); it != m_results.end(); it++)
	{
		GameObject* obj = *it;
		Vec2 difference = obj->getPosition() - position;
		float distance = difference.length();
		if( distance < resultDistance )
		{
			result = obj;
			resultDistance = distance;
		}
	}

	return result;
}