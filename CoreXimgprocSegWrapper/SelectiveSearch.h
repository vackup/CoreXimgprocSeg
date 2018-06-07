//Entity.h
#pragma once
#include "ManagedObject.h"
#include "../CoreXimgprocSeg/Core.h"
using namespace System;
using namespace CoreXimgprocSegWrapper;
using namespace System::Collections::Generic;

namespace CoreXimgprocSegWrapper
{
	public ref class RectCLR
	{
		int x;
		int y;
		int width;
		int height;

		public:
			RectCLR(int x, int y, int width, int height)
				: x(x), y(y), width(width), height(height)
			{}
			property int X {
				int get() { return x; }
			}
			property int Y {
				int get() { return y; }
			}
			property int Height {
				int get() { return height; }
			}
			property int Width {
				int get() { return width; }
			}
	};

	public ref class SelectiveSearch : public ManagedObject<CoreXimgprocSeg::Entity>
	{
		public:
			SelectiveSearch();
			cli::array<CoreXimgprocSegWrapper::RectCLR^>^ GetRectangles(String^ fileName, String^ strategyType);
	};	
}