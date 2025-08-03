//
// Created by halma on 2025. 08. 03..
//

#include "Triangle.h"

#include <fmt/printf.h>

void Triangle::update(double deltaTime) {
    // You could add animation here by changing vertex positions
    // For example, rotate the triangle
}

void Triangle::render() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, m_vertices);
    glColorPointer(3, GL_FLOAT, 0, m_colors);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
