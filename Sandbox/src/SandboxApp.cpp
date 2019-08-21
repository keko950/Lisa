#include <Lisa.h>


class ExampleLayer : public Lisa::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}
	
	~ExampleLayer() 
	{

	}

	void OnUpdate() override
	{
		LS_INFO("HELLO");
	}

	void OnEvent(Lisa::Event& e) override
	{
		LS_INFO("{0}", e.GetName());
		e.Handled = true;
	}
};

class Sandbox : public Lisa::Application
{
public:
	Sandbox() 
	{
		ExampleLayer *el = new ExampleLayer;
		this->PushLayer(el);
	}

	~Sandbox()
	{

	}

};

Lisa::Application* Lisa::CreateApplication()
{
	return new Sandbox;
}