//
// Created by halma on 2025. 08. 03.
//


#include "EntityManager.h"

#include <fmt/format.h>

EntityManager* EntityManager::instance = nullptr;

void EntityManager::updateAll(const double delta_time) {
    for (const auto &entity: getInstance()->entities) {
        if (entity && entity->isAlive()) {
            entity->update(delta_time);
        }
    }
}

void EntityManager::renderAll() {
    for (const auto &entity: getInstance()->entities) {
        if (entity && entity->isAlive()) {
            entity->render();
        }
    }
}

void EntityManager::initialize(Entity *entity) {
    if (entity) {
        entity->init();
        getInstance()->entities.push_back(std::vector<std::shared_ptr<Entity> >::value_type(entity));
    }
}
