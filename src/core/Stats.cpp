//
// Created by halma on 2025. 08. 03..
//

#include "Stats.h"

double Stats::getFPS() {
    double current_time = time_manager->getCurrentTime();

    // Only update FPS if enough time has passed according to refresh_rate
    if (current_time - fps_last_update_time >= fps_refresh_rate || fps == 0.0) {
        fps_last_update_time = current_time;
        fps = 1.0 / time_manager->getDeltaTime();
    }

    return fps;
}

void Stats::init() {
    if (config->isDebugMode()) {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    IEntity::init();
}

void Stats::update(double delta_time) {
    if (config->isDebugMode()) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Debug Info");

        ImGui::Text("Performance:");
        ImGui::Text("FPS: %.2f", getFPS());
        ImGui::Text("Delta Time: %.5f ms", time_manager->getDeltaTime() * 1000.0);
        ImGui::Text("Current Time: %.2f s", time_manager->getCurrentTime());

        ImGui::SeparatorText("Configuration");

        ImGui::Text("Configuration");
        ImGui::Text("Screen Width: %d", config->getScreenWidth());
        ImGui::Text("Screen Height: %d", config->getScreenHeight());
        ImGui::Text("Fullscreen: %s", config->isFullscreen() ? "Yes" : "No");
        ImGui::Text("Vsync: %s", config->isVsync() ? "Enabled" : "Disabled");
        ImGui::Text("Debug Mode: %s", config->isDebugMode() ? "Enabled" : "Disabled");

        ImGui::End();
    }
}

void Stats::render() {
    if (config->isDebugMode()) {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}

void Stats::destroy() {
    IEntity::destroy();
}




