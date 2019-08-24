#include "lspch.h"
#include "ImGuiLayer.h"

#include <GLFW\glfw3.h>
#include <Lisa\Log.h>
#include <imgui.h>
#include <examples\imgui_impl_glfw.h>
#include <Platform\OpenGL\ImGuiOpenGLRenderer.h>

namespace Lisa
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{ 
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.WantCaptureKeyboard = true;

		// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
		Application& app = Application::Get();
		m_Window = (GLFWwindow*)app.GetNativeWindow().GetNativeWindow();
	}
	void ImGuiLayer::OnDetach()
	{
	}
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		if (m_Resize)
		{
			int w, h;
			int display_w, display_h;
			glfwGetWindowSize(m_Window, &w, &h);
			glfwGetFramebufferSize(m_Window, &display_w, &display_h);
			io.DisplaySize = ImVec2((float)w, (float)h);
			if (w > 0 && h > 0)
				io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);
		}
		
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		for (int i = 0; i < ARRAYSIZE(m_MouseButtons); i++) {
			m_MouseButtons[i] = false;
			//io.MouseDown[i] = m_MouseButtons[i];
		}
		m_Resize = false;
	}

	void ImGuiLayer::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent& e) {
			return OnKeyPressedEvent(e);
		});
		eventDispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {
			return OnKeyReleasedEvent(e);
		});
		eventDispatcher.Dispatch<MouseButtonPressedEvent>([this](MouseButtonPressedEvent& e) {
			return OnMouseButtonPressedEvent(e);
		});
		eventDispatcher.Dispatch<MouseButtonReleasedEvent>([this](MouseButtonReleasedEvent& e) {
			return OnMouseButtonReleasedEvent(e);
		});
		eventDispatcher.Dispatch<MouseScrolledEvent>([this](MouseScrolledEvent& e) {
			return OnMouseScrolledEvent(e);
		});
		eventDispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {
			return OnWindowResizedEvent(e);
		});
		eventDispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent& e) {
			return OnMouseMovedEvent(e);
		});
		eventDispatcher.Dispatch<KeyTypedEvent>([this](KeyTypedEvent& e) {
			return OnKeyTypedEvent(e);
		});


	}

	bool ImGuiLayer::OnKeyPressedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		KeyPressedEvent ke = (KeyPressedEvent&)e;
		io.KeysDown[ke.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return true;
	}
	bool ImGuiLayer::OnKeyReleasedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		KeyReleasedEvent ke = (KeyReleasedEvent&)e;
		io.KeysDown[ke.GetKeyCode()] = false;
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return true;
	}
	bool ImGuiLayer::OnKeyTypedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		KeyTypedEvent ke = (KeyTypedEvent&)e;
		io.AddInputCharacter(ke.GetKeyCode());
		return true;
	}
	bool ImGuiLayer::OnMouseButtonPressedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		MouseButtonPressedEvent me = (MouseButtonPressedEvent&)e;
		int code = me.GetMouseButton();
		if (code >= 0 && code < 5) {
			m_MouseButtons[code] = true;
			io.MouseDown[code] = m_MouseButtons[code];
			return true;
		}
	}
	bool ImGuiLayer::OnMouseButtonReleasedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		MouseButtonPressedEvent me = (MouseButtonPressedEvent&)e;
		int code = me.GetMouseButton();
		if (code >= 0 && code < 5) {
			m_MouseButtons[code] = false;
			io.MouseDown[code] = m_MouseButtons[code];
			return true;
		}
	}
	bool ImGuiLayer::OnMouseScrolledEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		MouseMovedEvent me = (MouseMovedEvent&)e;
		io.MouseWheelH += (float)me.GetX();
		io.MouseWheel += (float)me.GetY();
		return true;
	}
	bool ImGuiLayer::OnMouseMovedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		MouseMovedEvent me = (MouseMovedEvent&)e;
		io.MousePos = ImVec2((float)me.GetX(), (float)me.GetY());
		return true;
	}
	bool ImGuiLayer::OnWindowResizedEvent(Event & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (e.GetEventType() == WindowResizeEvent::GetStaticType())
		{
			m_Resize = true;
		}
		return true;
	};
}