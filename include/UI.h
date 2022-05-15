#pragma once

#include "Battery/Battery.h"
#include "Fonts.h"

class UI : public Battery::ImGuiPanel<> {
public:



    UI() : Battery::ImGuiPanel<>("UI", {0, 0}, {0, 0}) {}

    void OnUpdate() override {
        size = Battery::GetMainWindow().GetSize();
    }

    void OnRender() override {
		ImGui::PushFont(Fonts::robotoMedium);

        ImGui::Text("Hello");
        ImGui::Text("It works!");

		ImGui::PushFont(Fonts::fontAwesomeIcons);
        ImGui::Text("\uf1E2  \u2699  \uE2CE  \uF0EB");
        ImGui::PopFont();

        ImGui::ShowDemoWindow();

        ImGui::PopFont();
    }
};

class UILayer : public Battery::ImGuiLayer<Fonts> {
public:

    std::shared_ptr<UI> ui;

    UILayer() {}

    void OnImGuiAttach() override {
        ui = std::make_shared<UI>();
        PushPanel(ui);
	}

	void OnImGuiDetach() override {

	}

	void OnImGuiUpdate() override {

	}

	void OnImGuiRender() override {
        
	}

	void OnImGuiEvent(Battery::Event* event) override {

	}
};
