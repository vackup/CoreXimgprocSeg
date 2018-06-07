//Entity.h
#pragma once
#include <vector>

namespace CoreXimgprocSeg
{
	struct RectCLR
	{
		int x;
		int y;
		int width;
		int height;

		RectCLR(int x, int y, int width, int height)
			: x(x), y(y), width(width), height(height)
		{}
	};

	class Entity
	{
	public:
		Entity();

		std::vector<CoreXimgprocSeg::RectCLR> Move(const char* fileName, const char* strategyType);
	};	
}