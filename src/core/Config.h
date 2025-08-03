//
// Created by halma on 2025. 08. 03..
//

#ifndef CONFIG_H
#define CONFIG_H


class Config {
    int screenWidth = 1920;
    int screenHeight = 1080;
    bool fullscreen = false;
    bool vsync = true;
    bool debugMode = false;

public:
    Config() = default;

    int getScreenWidth() const;

    int getScreenHeight() const;

    bool isFullscreen() const;

    bool isVsync() const;

    bool isDebugMode() const;

    void setScreenWidth(int width);

    void setScreenHeight(int height);

    void setFullscreen(bool isFullscreen);

    void setVsync(bool isVsync);

    void setDebugMode(bool isDebugMode);
};


#endif //CONFIG_H
