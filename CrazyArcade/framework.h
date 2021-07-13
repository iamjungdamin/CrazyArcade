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