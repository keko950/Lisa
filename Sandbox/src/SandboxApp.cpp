#include <Lisa.h>

#include <imgui\imgui.h>

class ExampleLayer : public Lisa::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	
	~ExampleLayer() 
	{

	}

	void OnImGuiRender() override
	{
	}

	void OnUpdate() override
	{
		//LS_INFO("HELLO");
	}

	void OnEvent(Lisa::Event& e) override
	{
		//LS_INFO("{0}", e.GetName());
	}
};

class Sandbox : public Lisa::Application
{
public:
	Sandbox() 
	{
		ExampleLayer *el = new ExampleLayer;
		//Lisa::ImGuiLayer *il = new Lisa::ImGuiLayer;
		this->PushLayer(el);
		//this->PushLayer(il);
	}

	~Sandbox()
	{

	}

};

Lisa::Application* Lisa::CreateApplication()
{
	return new Sandbox;
}