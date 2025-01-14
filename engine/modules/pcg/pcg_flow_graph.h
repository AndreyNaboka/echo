#pragma once

#include "engine/core/scene/render_node.h"
#include "engine/core/render/base/mesh/mesh.h"
#include "engine/core/render/base/shader/material.h"
#include "engine/core/render/base/proxy/render_proxy.h"
#include "engine/modules/pcg/node/pcg_node.h"
#include "engine/modules/pcg/data/pcg_data.h"

namespace Echo
{
	class PCGFlowGraph : public Node
	{
		ECHO_CLASS(PCGFlowGraph, Node)

	public:
		PCGFlowGraph();
		virtual ~PCGFlowGraph();

		// reset
		void reset();

		// node
		void addNode(PCGNode* node);
		void removeNode(PCGNode* node);

		// node query
		const vector<PCGNode*>::type& getNodes() const { return m_nodes; }
		PCGNode* getNodeByName(const String& name);

		// connect
		void addConnect(PCGConnect* connect);
		void removeConnect(PCGConnect* connect);

		// add connect by node name and connect point idx
		PCGConnect* addConnect(const String& fromNode, i32 fromIdx, const String& toNode, i32 toIdx);

		// connect query
		const vector<PCGConnect*>::type& getConnects() const { return m_connects; }

		// current
		void setAsOutput(PCGNode* node);
		PCGNode* getOutputNode();

		// data flow programming pcg flow graph
		const String& getGraph();
		void setGraph(const String& graph);

		// run
		void run();

	public:
		// Is Node Exist
		bool isNodeExist(PCGNode* node);

		// unique name
		void makeNameUnique(PCGNode* node);

	private:
		// Run
		void runNode(PCGNode* node);

	protected:
		String						m_graph;
		vector<PCGNode*>::type		m_nodes;
		PCGNode*					m_nodeOutput = nullptr;
		std::vector<PCGConnect*>	m_connects;
	};
}
