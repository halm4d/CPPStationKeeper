//
// Created by halma on 2025. 08. 03..
//

#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <imgui.h>
#include <glm/ext/vector_float2.hpp>

#include "../third_party/imgui/imgui_impl_opengl3.h"

class TextRenderer {
public:
    static void RenderText(glm::vec2 pos, const char *text);
};


#endif //TEXTRENDERER_H
