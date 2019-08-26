#pragma once

#include "Lisa\Core.h"
#include "Lisa\Events\Event.h"
#include "Lisa/Layer.h"

namespace Lisa
{
	class LISA_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* l);
		void PushOverlay(Layer *l);
		void PopLayer(Layer *l);
		void PopOverlay(Layer *l);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;

	};
}