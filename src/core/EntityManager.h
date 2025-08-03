//
// Created by halma on 2025. 08. 03..
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <memory>
#include <vector>

#include "IEntity.h"

class EntityManager {
private:
    std::vector<std::shared_ptr<IEntity>> entities;

    EntityManager() = default;

    EntityManager(const EntityManager &other) = delete;
    EntityManager &operator=(const EntityManager &other) = delete;

    static EntityManager *instance;
public:
    static EntityManager *getInstance() {
        if (!instance) {
            instance = new EntityManager();
        }
        return instance;
    }

    static void updateAll(const double delta_time) {
        for (auto &entity : getInstance()->entities) {
            if (entity && entity->initialized && !entity->destroyed) {
                entity->update(delta_time);
            }
        }
    }

    static void initialize(IEntity * entity) {
        if (entity) {
            entity->init();
            getInstance()->entities.push_back(std::vector<std::shared_ptr<IEntity> >::value_type(entity));
        }
    }

    static void renderAll() {
        for (auto &entity : getInstance()->entities) {
            if (entity && entity->initialized && !entity->destroyed) {
                entity->render();
            }
        }
    }

    static void destroyAll() {
        for (auto &entity : getInstance()->entities) {
            if (entity && entity->initialized && entity->destroyed) {
                entity->destroy();
                std::erase(getInstance()->entities, entity);
            }
        }
    };
};

// Initialize the static instance pointer
inline EntityManager* EntityManager::instance = nullptr;


#endif //ENTITYMANAGER_H
