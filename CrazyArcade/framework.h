#pragma once
//라이브러리 인클루드

#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr

namespace Math
{
	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		Vector2f direction;
		direction.x = vec1.x - vec2.x;
		direction.y = vec1.y - vec2.y;

		float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));
		
		return { direction.x / length, direction.y / length };
	}
}