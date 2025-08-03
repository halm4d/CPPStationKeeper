//
// Created by halma on 2025. 08. 03..
//

#include "TextRenderer.h"

#include "Vector2D.h"

void TextRenderer::RenderText(const Vector2D pos, const char* text) {
    ImDrawList *drawList = ImGui::GetBackgroundDrawList();
    drawList->AddText(ImVec2(pos.x, pos.y), IM_COL32(255, 255, 255, 255), text);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
