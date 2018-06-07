// ManagedObject.h
#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;

// Based on https://www.red-gate.com/simple-talk/dotnet/net-development/creating-ccli-wrapper/
namespace CoreXimgprocSegWrapper {

	/*
	This function allows you to convert a .NET String to a const char* which you can further use in C++. 
	If you want to do the conversion the other way around, things are not so complicated: 
	the String class contains a constructor that accepts a const char* as a parameter.
	*/
	static const char* string_to_char_array(String^ string)
	{
		const char* str = (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
		return str;
	}

	/*
	I chose to create the example with an integer array, but you can replace int with any type that you need.
	However, I recommend writing the code for this conversion wherever you need it rather than using a
	function like this, since, as you can see, there are two components that you need to know for the 
	unmanaged array: the pointer to the first element and the number of elements.
	You can, of course, create a struct to hold both of these elements, but it is a simpler and 
	more elegant solution to just write these two lines of code for each separate case where you need to.

	static void int_array_conversion(array<int>^ data)
	{
		pin_ptr<unsigned int> arrayPin = &data[0];
		unsigned int size = data->Length;
	}
	*/

	template<class T>
	public ref class ManagedObject
	{
	protected:
		T * m_Instance;
	public:
		ManagedObject(T* instance)
			: m_Instance(instance)
		{
		}
		virtual ~ManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}
		!ManagedObject()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}
		T* GetInstance()
		{
			return m_Instance;
		}
	};
}
