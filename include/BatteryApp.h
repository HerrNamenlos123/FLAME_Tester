#pragma once

#include "Battery/Battery.h"
#include "UI.h"

class BatteryApp : public Battery::Application {
public:

    std::shared_ptr<UILayer> ui_layer;

    BatteryApp() {}

    bool OnStartup() override;
    void OnUpdate() override;
    void OnRender() override;
    void OnEvent(Battery::Event* e) override;
    void OnShutdown() override;
};
