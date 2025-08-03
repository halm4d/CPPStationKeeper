//
// Created by halma on 2025. 08. 03..
//

#ifndef DELTATIME_H
#define DELTATIME_H
#include <GLFW/glfw3.h>

class TimeManager {
    double currentTime = glfwGetTime();
    double lastTime = currentTime;
    double deltaTime = 0.0;

public:
    TimeManager() = default;

    void update();

    [[nodiscard]] double getDeltaTime() const;
    [[nodiscard]] double getCurrentTime() const;
};

#endif //DELTATIME_H
