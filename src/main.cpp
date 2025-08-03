#include <fmt/printf.h>
#include <GLFW/glfw3.h>

#include <memory>
#define GL_SILENCE_DEPRECATION

#include "imgui.h"
#include "third_party/imgui/imgui_impl_glfw.h"
#include "core/Config.h"
#include "core/EntityManager.h"
#include "core/Stats.h"
#include "core/TextRenderer.h"
#include "core/TimeManager.h"
#include "game/Triangle.h"

int screenWidth = 1920;
int screenHeight = 1080;

int main() {
    fmt::print("Hello, World!\n");

    auto config = Config();
    config.setScreenWidth(screenWidth);
    config.setScreenHeight(screenHeight);
    config.setFullscreen(false);
    config.setVsync(true);
    config.setDebugMode(true);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "Station Keeper", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    auto time_manager = TimeManager();


    EntityManager * entity_manager = EntityManager::getInstance();

    Stats entity("Debug stats", &time_manager, &config, window, 1.0);
    entity_manager->initialize(&entity);

    Triangle triangle("Triangle");
    entity_manager->initialize(&triangle);

    constexpr auto clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }
        time_manager.update();

        entity_manager->updateAll(time_manager.getDeltaTime());

        TextRenderer::RenderText(glm::vec2(300, 300), "Hello Game!");

        glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
        glViewport(0, 0, screenWidth, screenHeight);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Render here */
        entity_manager->renderAll();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
