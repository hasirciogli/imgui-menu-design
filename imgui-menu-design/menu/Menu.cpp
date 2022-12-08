#include "Menu.h"


void Menu::runCustomGui(bool param) {
	if (!Menu::settings::isOpened)
		return;
	ImGui::Begin("NAME", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration);
	{

	}
	ImGui::End();
}

void Menu::runCustomGui2(bool param) {
}