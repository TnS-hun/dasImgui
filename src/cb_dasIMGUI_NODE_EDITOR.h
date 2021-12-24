#pragma once

#include "imgui_node_editor_stub.h"

namespace das {

// node

template <> struct typeFactory<ax::NodeEditor::NodeId> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tInt);
		t->alias = "ax::NodeEditor::NodeId";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ax::NodeEditor::NodeId> { constexpr static const char * name() { return "NodeId"; } };
template <> struct cast_arg<ax::NodeEditor::NodeId> {
    static __forceinline ax::NodeEditor::NodeId to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        return ax::NodeEditor::NodeId(cast<int32_t>::to(res));
    }
};
template <> struct cast_res<ax::NodeEditor::NodeId> {
    static __forceinline vec4f from ( ax::NodeEditor::NodeId node ) {
        return cast<int32_t>::from(int32_t(node.Get()));
    }
};

// pin

template <> struct typeFactory<ax::NodeEditor::PinId> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tInt);
		t->alias = "ax::NodeEditor::PinId";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ax::NodeEditor::PinId> { constexpr static const char * name() { return "PinId"; } };
template <> struct cast_arg<ax::NodeEditor::PinId> {
    static __forceinline ax::NodeEditor::PinId to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        return ax::NodeEditor::PinId(cast<int32_t>::to(res));
    }
};
template <> struct cast_res<ax::NodeEditor::PinId> {
    static __forceinline vec4f from ( ax::NodeEditor::PinId node ) {
        return cast<int32_t>::from(int32_t(node.Get()));
    }
};

// link

template <> struct typeFactory<ax::NodeEditor::LinkId> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tInt);
		t->alias = "ax::NodeEditor::LinkId";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ax::NodeEditor::LinkId> { constexpr static const char * name() { return "LinkId"; } };
template <> struct cast_arg<ax::NodeEditor::LinkId> {
    static __forceinline ax::NodeEditor::LinkId to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        return ax::NodeEditor::LinkId(cast<int32_t>::to(res));
    }
};
template <> struct cast_res<ax::NodeEditor::LinkId> {
    static __forceinline vec4f from ( ax::NodeEditor::LinkId node ) {
        return cast<int32_t>::from(int32_t(node.Get()));
    }
};

}
