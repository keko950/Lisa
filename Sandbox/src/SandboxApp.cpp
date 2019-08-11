#include <Lisa.h>

namespace Lisa {

	LISA_API void Print();

}

class Sandbox : public Lisa::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}

};

Lisa::Application* Lisa::CreateApplication()
{
	return new Sandbox;
}