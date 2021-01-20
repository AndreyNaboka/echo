#pragma once

#include "engine/core/render/base/editor/shader/node/shader_node.h"

#ifdef ECHO_EDITOR_MODE

namespace Echo
{
    class ShaderNodeMod : public ShaderNode
    {
        Q_OBJECT

    public:
        ShaderNodeMod();
        virtual ~ShaderNodeMod() {}

        // caption
        virtual QString caption() const override { return QStringLiteral("Mod"); }

        // is caption visible
        virtual bool captionVisible() const override { return true; }

        // name
        virtual QString name() const override { return QStringLiteral("Mod"); }

		// when input changed
		virtual void setInData(std::shared_ptr<NodeData> nodeData, QtNodes::PortIndex port) override;

		// generate code
		virtual bool generateCode(Echo::ShaderCompiler& compiler) override;
    };
}

#endif