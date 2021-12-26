// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasIMGUI.h"
#include "need_dasIMGUI.h"
namespace das {
void Module_dasIMGUI::initFunctions_11() {
	addExtern< bool (*)(const char *,bool,ImGuiSelectableFlags,const ImVec2 &) , ImGui::Selectable >(*this,lib,"Selectable",SideEffects::worstDefault,"ImGui::Selectable")
		->args({"label","selected","flags","size"})
		->arg_init(1,make_smart<ExprConstBool>(false))
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)));
	addExtern< bool (*)(const char *,bool *,ImGuiSelectableFlags,const ImVec2 &) , ImGui::Selectable >(*this,lib,"Selectable",SideEffects::worstDefault,"ImGui::Selectable")
		->args({"label","p_selected","flags","size"})
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)));
	addExtern< bool (*)(const char *,const ImVec2 &) , ImGui::BeginListBox >(*this,lib,"BeginListBox",SideEffects::worstDefault,"ImGui::BeginListBox")
		->args({"label","size"});
	addExtern< void (*)() , ImGui::EndListBox >(*this,lib,"EndListBox",SideEffects::worstDefault,"ImGui::EndListBox");
	addExtern< bool (*)(const char *,int *,const char *const [],int,int) , ImGui::ListBox >(*this,lib,"ListBox",SideEffects::worstDefault,"ImGui::ListBox")
		->args({"label","current_item","items","items_count","height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1));
	addExtern< void (*)(const char *,const float *,int,int,const char *,float,float,ImVec2,int) , ImGui::PlotLines >(*this,lib,"PlotLines",SideEffects::worstDefault,"ImGui::PlotLines")
		->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(340282346638528859811704183484516925440.00000000000000000))
		->arg_init(6,make_smart<ExprConstFloat>(340282346638528859811704183484516925440.00000000000000000))
		->arg_init(8,make_smart<ExprConstInt>(4));
	addExtern< void (*)(const char *,const float *,int,int,const char *,float,float,ImVec2,int) , ImGui::PlotHistogram >(*this,lib,"PlotHistogram",SideEffects::worstDefault,"ImGui::PlotHistogram")
		->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(340282346638528859811704183484516925440.00000000000000000))
		->arg_init(6,make_smart<ExprConstFloat>(340282346638528859811704183484516925440.00000000000000000))
		->arg_init(8,make_smart<ExprConstInt>(4));
	addExtern< void (*)(const char *,bool) , ImGui::Value >(*this,lib,"Value",SideEffects::worstDefault,"ImGui::Value")
		->args({"prefix","b"});
	addExtern< void (*)(const char *,int) , ImGui::Value >(*this,lib,"Value",SideEffects::worstDefault,"ImGui::Value")
		->args({"prefix","v"});
	addExtern< void (*)(const char *,unsigned int) , ImGui::Value >(*this,lib,"Value",SideEffects::worstDefault,"ImGui::Value")
		->args({"prefix","v"});
	addExtern< void (*)(const char *,float,const char *) , ImGui::Value >(*this,lib,"Value",SideEffects::worstDefault,"ImGui::Value")
		->args({"prefix","v","float_format"})
		->arg_init(2,make_smart<ExprConstString>(""));
	addExtern< bool (*)() , ImGui::BeginMenuBar >(*this,lib,"BeginMenuBar",SideEffects::worstDefault,"ImGui::BeginMenuBar");
	addExtern< void (*)() , ImGui::EndMenuBar >(*this,lib,"EndMenuBar",SideEffects::worstDefault,"ImGui::EndMenuBar");
	addExtern< bool (*)() , ImGui::BeginMainMenuBar >(*this,lib,"BeginMainMenuBar",SideEffects::worstDefault,"ImGui::BeginMainMenuBar");
	addExtern< void (*)() , ImGui::EndMainMenuBar >(*this,lib,"EndMainMenuBar",SideEffects::worstDefault,"ImGui::EndMainMenuBar");
	addExtern< bool (*)(const char *,bool) , ImGui::BeginMenu >(*this,lib,"BeginMenu",SideEffects::worstDefault,"ImGui::BeginMenu")
		->args({"label","enabled"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	addExtern< void (*)() , ImGui::EndMenu >(*this,lib,"EndMenu",SideEffects::worstDefault,"ImGui::EndMenu");
	addExtern< bool (*)(const char *,const char *,bool,bool) , ImGui::MenuItem >(*this,lib,"MenuItem",SideEffects::worstDefault,"ImGui::MenuItem")
		->args({"label","shortcut","selected","enabled"})
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_init(3,make_smart<ExprConstBool>(true));
	addExtern< bool (*)(const char *,const char *,bool *,bool) , ImGui::MenuItem >(*this,lib,"MenuItem",SideEffects::worstDefault,"ImGui::MenuItem")
		->args({"label","shortcut","p_selected","enabled"})
		->arg_init(3,make_smart<ExprConstBool>(true));
	addExtern< void (*)() , ImGui::BeginTooltip >(*this,lib,"BeginTooltip",SideEffects::worstDefault,"ImGui::BeginTooltip");
}
}

