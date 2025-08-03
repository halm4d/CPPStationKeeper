//
// Created by halma on 2025. 08. 03..
//

#include "Config.h"

int Config::getScreenWidth() const {
    return screenWidth;
}

int Config::getScreenHeight() const {
    return screenHeight;
}

bool Config::isFullscreen() const { return fullscreen; }

bool Config::isVsync() const { return vsync; }

bool Config::isDebugMode() const { return debugMode; }

void Config::setScreenWidth(const int width) { screenWidth = width; }

void Config::setScreenHeight(const int height) { screenHeight = height; }

void Config::setFullscreen(const bool isFullscreen) { fullscreen = isFullscreen; }

void Config::setVsync(const bool isVsync) { vsync = isVsync; }

void Config::setDebugMode(const bool isDebugMode) { debugMode = isDebugMode; }
