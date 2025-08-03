//
// Created by halma on 2025. 08. 03..
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <GLFW/glfw3.h>

#include "../core/Entity.h"


class Triangle final : public Entity {
private:
    // Vertex data
    float m_vertices[9] = {
        -0.25f, -0.25f, 0.0f,  // bottom left
         0.25f, -0.25f, 0.0f,  // bottom right
         0.0f,  0.25f, 0.0f   // top
    };

    // Color data
    float m_colors[9] = {
        1.0f, 0.0f, 0.0f,  // red
        0.0f, 1.0f, 0.0f,  // green
        0.0f, 0.0f, 1.0f   // blue
    };

public:
    explicit Triangle(const char *name) : Entity(name) {}

    void update(double deltaTime) override;
    void render() override;
};

#endif //TRIANGLE_H
