#pragma once

#pragma comment (lib, "d3d9.lib")
#include <d3d9.h>
#include <d3dx9.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h" 
#include "../imgui/imgui_impl_win32.h"

namespace Menu
{
	namespace settings {
		inline bool isOpened = true;
		inline int ui_width = 780;
		inline int ui_height = 590;
	};
	void runCustomGui(LPDIRECT3DDEVICE9, bool paramval = 0);
	void runCustomGui2(bool paramval = 0);
};