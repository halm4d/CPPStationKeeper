//
// Created by halma on 2025. 08. 03..
//

#include "TimeManager.h"

#include <GLFW/glfw3.h>

void TimeManager::update() {
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
}

double TimeManager::getDeltaTime() const {
    return deltaTime;
}

double TimeManager::getCurrentTime() const {
    return currentTime;
}
