#include "lspch.h"
#include "LayerStack.h"

namespace Lisa
{
		LayerStack::LayerStack()
		{
			m_LayerInsert = m_Layers.begin();
		}

		LayerStack::~LayerStack()
		{
			for (Layer* l : m_Layers)
			{
				delete l;
			}
		}

		void LayerStack::PushLayer(Layer* l)
		{
			m_LayerInsert = m_Layers.emplace(m_LayerInsert, l);
		}

		void LayerStack::PushOverlay(Layer* l)
		{
			m_Layers.emplace_back(l);
		}

		void LayerStack::PopLayer(Layer* l)
		{
			auto it = std::find(m_Layers.begin(), m_Layers.end(), l);
			if (it != m_Layers.end())
			{
				m_Layers.erase(it);
				m_LayerInsert--;
			}
		}

		void LayerStack::PopOverlay(Layer *l)
		{
			auto it = std::find(m_Layers.begin(), m_Layers.end(), l);
			if (it != m_Layers.end())
			{
				m_Layers.erase(it);
			}
		}

}

