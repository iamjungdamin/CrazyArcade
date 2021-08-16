#pragma once
//라이브러리 인클루드

#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <iostream>
#include <sstream>
#include <fstream>

#include <map>
#include <vector>
#include <stack>
#include <random>

using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr
constexpr float PI = 3.14159265f;

namespace Math
{
	inline const float Length(const float& positionX, const float& positionY)
	{
		return sqrt((positionX * positionX) + (positionY * positionY));
	}

	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		Vector2f direction;
		direction.x = vec1.x - vec2.x;
		direction.y = vec1.y - vec2.y;

		float length = Length(direction.x, direction.y);

		return { direction.x / length, direction.y / length };
	}

	inline int RandomIntager(const int& minimum, const int& maximum)
	{
		static uniform_int_distribution<int> urd(minimum, maximum);
		static default_random_engine dre;

		return urd(dre);
	}

	inline const float RotateAxis(const Vector2f& vec1, const Vector2f& vec2, const float& angle)
	{
		Vector2f normal = Math::Normalize(vec1, vec2);
		return (atan2(normal.y, normal.x) * 180 / PI) + angle;
	}

	inline const float RotateAxis(const Vector2f& vec, const float& angle)
	{
		return (atan2(vec.y, vec.x) * 180 / PI) + angle;
	}
}