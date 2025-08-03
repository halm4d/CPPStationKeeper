//
// Created by halma on 2025. 08. 03..
//

#include "TextRenderer.h"

void TextRenderer::RenderText(const char* text) {
    ImDrawList *drawList = ImGui::GetBackgroundDrawList();
    drawList->AddText(ImVec2(100, 100), IM_COL32(255, 255, 255, 255), text);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
