//
// Created by halma on 2025. 08. 03..
//

#ifndef STATS_H
#define STATS_H
#include <GLFW/glfw3.h>

#include "Config.h"
#include "Entity.h"

#include <imgui.h>

#include "TimeManager.h"
#include "../third_party/imgui/imgui_impl_glfw.h"
#include "../third_party/imgui/imgui_impl_opengl3.h"

class Stats : public Entity {
private:
    TimeManager *time_manager;
    Config *config;
    GLFWwindow *window = nullptr; // Pointer to the GLFW window, if needed for rendering

    // FPS statistics
    double fps_refresh_rate = 1.0; // Refresh rate in seconds
    double fps_last_update_time = 0.0; // Last time the stats were updated
    double fps = 0.0; // Frames per second

    bool show_debug_window = true; // Flag to control the visibility of the debug window
public:
    explicit Stats(const char *name, TimeManager *time_manager, Config *config, GLFWwindow *window, const double fps_refresh_rate): Entity(name) {
        this->time_manager = time_manager;
        this->config = config;
        this->window = window;
        this->fps_refresh_rate = fps_refresh_rate;
    }

    [[nodiscard]] double getFPS();

    void init() override;

    void update(double delta_time) override;

    void render() override;

    void destroy() override;

    void showDebugWindow(const bool show) {
        show_debug_window = show;
    };

    [[nodiscard]] bool isDebugWindowVisible() const {
        return show_debug_window;
    };
};

#endif // STATS_H
