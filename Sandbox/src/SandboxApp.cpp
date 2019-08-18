#include <Lisa.h>

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