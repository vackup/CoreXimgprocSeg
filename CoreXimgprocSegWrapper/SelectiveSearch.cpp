//Entity.cpp
#include "SelectiveSearch.h"
#include "stdafx.h"

namespace CoreXimgprocSegWrapper
{
	SelectiveSearch::SelectiveSearch()
		: ManagedObject(new CoreXimgprocSeg::Entity())
	{
		//Console::WriteLine("Creating a new Entity-wrapper object!");
	}

	cli::array<CoreXimgprocSegWrapper::RectCLR^>^ SelectiveSearch::GetRectangles(String^ fileName, String^ strategyType)
	{
		//Console::WriteLine("The Move method from the Wrapper was called!");
		auto rects = m_Instance->Move(string_to_char_array(fileName), string_to_char_array(strategyType));

		array<CoreXimgprocSegWrapper::RectCLR^>^ rectCLRarray = gcnew array<CoreXimgprocSegWrapper::RectCLR^>(rects.size());

		int i = 0;

		for (auto ri = rects.begin(); ri != rects.end(); ri++)
		{
			auto x = (*ri).x;
			auto y = (*ri).y;
			auto width = (*ri).width;
			auto height = (*ri).height;

			rectCLRarray[i] = gcnew CoreXimgprocSegWrapper::RectCLR(
				x, 
				y, 
				width, 
				height);			

			i++;
		}

		return rectCLRarray;
	}
}