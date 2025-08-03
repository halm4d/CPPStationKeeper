//
// Created by halma on 2025. 08. 03.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <memory>
#include <vector>
#include "Entity.h"

struct EntityManager {
private:
    std::vector<std::shared_ptr<Entity> > entities;
    static EntityManager *instance;
public:
    static EntityManager *getInstance() {
        if (!instance) {
            instance = new EntityManager();
        }
        return instance;
    }

    static void updateAll(double delta_time);
    static void renderAll();

    static void initialize(Entity *entity);

    [[nodiscard]] std::vector<std::shared_ptr<Entity> > getEntities() const {
        return entities;
    }
};

#endif //ENTITYMANAGER_H
