#pragma once

struct Vec2
{
	float x;
	float y;
public:
	Vec2() : x(0.f), y(0.f) {}
	Vec2(float x, float y) : x(x), y(y) {}
	Vec2(int x, int y) : x((float)x), y((float)y) {}

};

