#include "Menu.h"
#include <iostream>
#include <string>

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

void Menu::runCustomGui(LPDIRECT3DDEVICE9 pDevice, bool param) {
	if (!Menu::settings::isOpened)
		return;

	static bool firstLoadInit = false;

	if (!firstLoadInit)
	{
		firstLoadInit = true;
		ImGuiStyle& styles = ImGui::GetStyle();
		styles.WindowPadding = ImVec2(0, 0);
		styles.FramePadding = ImVec2(0, 0);

		windowSize wsz;

		GetWindowSize(wsz, pDevice);


		ImGui::SetNextWindowPos(ImVec2((wsz.width / 2) - (Menu::settings::ui_width / 2), (wsz.height / 2) - (Menu::settings::ui_height / 2)));
	}

	ImGui::SetNextWindowSize(ImVec2(Menu::settings::ui_width, Menu::settings::ui_height));

	


	ImGui::Begin("NAME", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration);
	{
		ImGui::Text("selam");
	}
	ImGui::End();
}

void Menu::runCustomGui2(bool param) {
}