
#include "BatteryApp.h"

bool BatteryApp::OnStartup() {

    window.SetScreenPosition({ 0, 0 });

    ui_layer = std::make_shared<UILayer>();
    PushLayer(ui_layer);
    
    //try {
    //    FlameTest();
    //}
    //catch (const std::exception& e) {
    //    std::cout << e.what() << std::endl;
    //}

    return true;
}

void BatteryApp::OnUpdate() {

}

void BatteryApp::OnRender() {
    
}

void BatteryApp::OnEvent(Battery::Event* e) {
    
}

void BatteryApp::OnShutdown() {
    
}
