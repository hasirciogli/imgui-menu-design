#include "Menu.h"
#include <iostream>
#include <string>

void imspaceMacro(float x, float y) {
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + x, ImGui::GetCursorPos().y + y));
}

struct windowSize {
	float width;
	float height;
};

void GetWindowSize(windowSize& size, LPDIRECT3DDEVICE9 pDevice) {
	D3DDEVICE_CREATION_PARAMETERS cparams;
	RECT rect;

	pDevice->GetCreationParameters(&cparams);
	GetWindowRect(cparams.hFocusWindow, &rect);
	

	size.width = (float)rect.right - rect.left;
	size.height = (float)rect.bottom - rect.top;
}

int calculateUiScalar(int scalaDef) {
	if (false)
	{
		if (Menu::settings::ui_scalar == 200)
			return scalaDef + ((scalaDef * 200) / 100);
		else if (Menu::settings::ui_scalar == 175)
			return 0000;
		else if (Menu::settings::ui_scalar == 150)
			return 0000;
		else if (Menu::settings::ui_scalar == 125)
			return 0000;
		else if (Menu::settings::ui_scalar == 100)
			return 0000;
		else if (Menu::settings::ui_scalar == 75)
			return 0000;
		else if (Menu::settings::ui_scalar == 50)
			return 0000;
		else if (Menu::settings::ui_scalar == 25)
			return 0000;
		else if (Menu::settings::ui_scalar == 0)
			return 0000;
		else
			return scalaDef;
	}

	return (scalaDef * Menu::settings::ui_scalar) / 100;
}

void customComboBox(int& selectedItemID, const char* items[10]) {
	if (ImGui::BeginCombo("##combo", *items)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			bool is_selected = (selectedItemID == *items[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable((const char*)*items[n], is_selected))
			{
				selectedItemID = n;
				ImGui::SetItemDefaultFocus();
					
			}// You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)

		}
		ImGui::EndCombo();
	}
}

void Menu::runCustomGui(LPDIRECT3DDEVICE9 pDevice, bool param) {
	if (!Menu::settings::isOpened)
		return;

	Menu::settings::ui_width_s = calculateUiScalar(Menu::settings::ui_width);
	Menu::settings::ui_height_s = calculateUiScalar(Menu::settings::ui_height);

	static bool firstLoadInit = false;

	ImGuiStyle& imguiStyles = ImGui::GetStyle();



	//inline functions

	auto getMenuPos = [](ImVec2& pos) {
		pos = ImGui::GetWindowPos();
	};

	auto getCursorPos = [](ImVec2& pos) {
		pos = ImGui::GetCursorPos();
	};



	if (!firstLoadInit)
	{
		firstLoadInit = true;
		imguiStyles.WindowPadding = ImVec2(0, 0);
		imguiStyles.FramePadding = ImVec2(0, 0);
		imguiStyles.CellPadding = ImVec2(0, 0);
		imguiStyles.ItemSpacing = ImVec2(0, 0);
		imguiStyles.ItemInnerSpacing = ImVec2(0, 0);

		imguiStyles.Colors[ImGuiCol_WindowBg] = ImColor(20, 20, 20);

		windowSize wsz;

		GetWindowSize(wsz, pDevice);


		ImGui::SetNextWindowPos(ImVec2((wsz.width / 2) - (Menu::settings::ui_width_s / 2), (wsz.height / 2) - (Menu::settings::ui_height_s / 2)));
	}

	ImGui::SetNextWindowSize(ImVec2(Menu::settings::ui_width_s, Menu::settings::ui_height_s));

	
	ImGui::GetIO().FontGlobalScale = Menu::settings::uiSelectedDPI;


	imguiStyles.WindowRounding = 8;
	ImGui::Begin("NAME", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration);
	{
		imspaceMacro(5, 5);

		ImVec2 nPos = {};
		ImVec2 nPos2 = {};

		getMenuPos(nPos);
		getCursorPos(nPos2);


		ImGui::GetWindowDrawList()->AddLine(ImVec2(nPos.x + calculateUiScalar(230), nPos.y + nPos2.y), ImVec2(nPos.x + calculateUiScalar(230), nPos.y + calculateUiScalar(Menu::settings::ui_height_s - 5)), ImColor(150, 150, 150), 2);

		
		ImGui::BeginChild("#left-side", ImVec2(calculateUiScalar(220), calculateUiScalar(Menu::settings::ui_height_s - 10)), true);
		{

			ImGui::BeginChild("#left-upper", ImVec2(calculateUiScalar(220), calculateUiScalar(Menu::settings::ui_height_s - 75)), false);
			{
				ImGui::PushFont(Menu::settings::fonts_GUIBIGFONT);
				imspaceMacro(calculateUiScalar(220) / 2 - (ImGui::CalcTextSize("PC", nullptr).x / 2), 5);
				ImGui::Text("PC");
				ImGui::PopFont();


				//ImGui::Text(std::to_string(ImGui::GetIO().FontGlobalScale).c_str());



				ImGui::GetStyle().FrameRounding = 0;

				imguiStyles.Colors[ImGuiCol_Button] = ImColor(20, 20, 20);
				imguiStyles.Colors[ImGuiCol_ButtonHovered] = ImColor(35, 120, 30);
				imguiStyles.Colors[ImGuiCol_ButtonActive] = ImColor(35, 90, 30);


				auto selButItem = [](std::string item_name, int page_id, bool isFirst = false) {
					imspaceMacro(5, 0);
					if (ImGui::Button(item_name.c_str(), ImVec2(calculateUiScalar(210), calculateUiScalar(35))))
						Menu::settings::selected_page = page_id;
				};

				selButItem("Ragebot", 0, false);
				selButItem("Legitbot", 1);
				selButItem("Anti Aim", 2);
				 

				ImVec2 nPos = {};
				ImVec2 nPos2 = {};
				
				getMenuPos(nPos);
				getCursorPos(nPos2);

				ImGui::GetWindowDrawList()->AddLine(ImVec2(nPos.x + calculateUiScalar(40), nPos.y + nPos2.y + 9), ImVec2(nPos.x + calculateUiScalar(220 - 40), nPos.y + nPos2.y + 9), ImColor(150, 150, 150), 2);
				imspaceMacro(0, 20);

				selButItem("Esp", 3);
				selButItem("Chams", 4);
				selButItem("World", 5);

				getMenuPos(nPos);
				getCursorPos(nPos2);
				ImGui::GetWindowDrawList()->AddLine(ImVec2(nPos.x + calculateUiScalar(40), nPos.y + nPos2.y + 9), ImVec2(nPos.x + calculateUiScalar(220 - 40), nPos.y + nPos2.y + 9), ImColor(150, 150, 150), 2);
				imspaceMacro(0, 20);

				selButItem("Misc", 6);
				selButItem("Skins", 7);
				selButItem("Script", 8);

				ImGui::GetStyle().FrameRounding = 2;
			}
			ImGui::EndChild();

			ImGui::BeginChild("#left-bottomer", ImVec2(calculateUiScalar(220), calculateUiScalar(65)), false);
			{
				ImVec2 mPos = {};

				getMenuPos(mPos);

				ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(mPos.x + calculateUiScalar((220 / 3) / 2), mPos.y + calculateUiScalar(65 / 2)), 26, ImColor(140, 140, 140));
				imspaceMacro(calculateUiScalar((220 / 3 + 10)), calculateUiScalar(65 / 2) - (ImGui::CalcTextSize("Hasirciogli", nullptr).y / 2));
				ImGui::Text("Hasirciogli");
			}
			ImGui::EndChild();
		}
		ImGui::EndChild();

		ImGui::BeginChild("#right-side");
		{
			
		}
		ImGui::EndChild();
	}
	ImGui::End();

	ImGui::GetIO().FontGlobalScale = 1;

	ImGui::Begin("Debug Window");
	{
		ImGui::SliderFloat("test", &Menu::settings::uiSelectedDPI, -10.f, 10.f);
		ImGui::Text(std::to_string(ImGui::GetIO().FontGlobalScale).c_str());
		//customComboBox(Menu::settings::uiSelectedScalarID, Menu::settings::uiSelectedScalarName);
		if (ImGui::Button("reset", ImVec2(150, 50)))
			Menu::settings::uiSelectedDPI = 1;

	}
	ImGui::End();

	Menu::settings::updateMenuScalar(Menu::settings::uiSelectedScalarID);

}

void Menu::runCustomGui2(bool param) {
}