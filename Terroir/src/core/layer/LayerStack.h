//
// Created by cjp on 1/8/23.
//

#ifndef TERROIR_LAYERSTACK_H
#define TERROIR_LAYERSTACK_H

#include "Terroir/pch/Tpch.h"
#include <Terroir/terroir_export.h>
#include "Layer.h"

namespace Terroir
{
	// This stack controls engine's layer functionality
	class TERROIR_EXPORT LayerStack
	{
	public:
		// Takes pointer to layer for polymorphism
		using LayerPtr = std::unique_ptr<Layer*>;
		using LayerStackVec = std::vector<LayerPtr>;
		using LayerStackVecIterator = LayerStackVec::iterator;

		LayerStack();

		~LayerStack();

		void PushLayer(LayerPtr);

		void PushOverlay(LayerPtr);

		// to be possibly changed
		void PopLayer(LayerPtr&);

		// to be possibly changed
		void PopOverlay(LayerPtr&);

		inline LayerStackVecIterator begin()
		{
			return m_Layers.begin();
		}

		inline LayerStackVecIterator end()
		{
			return m_Layers.end();
		}

	private:
		LayerStackVec m_Layers;
		LayerStackVecIterator m_LayerInsert;

	};

} // Terroir

#endif //TERROIR_LAYERSTACK_H
