#pragma once
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h" 
#include "../imgui/imgui_impl_win32.h"

namespace Menu
{
	namespace settings {
		inline bool isOpened = false;
	};
	void runCustomGui(bool paramval = 0);
	void runCustomGui2(bool paramval = 0);
};