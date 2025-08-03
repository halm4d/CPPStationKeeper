//
// Created by halma on 2025. 08. 03.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <memory>
#include <vector>
#include "Entity.h"

struct EntityManager final {
    static EntityManager *getInstance() {
        if (!instance) {
            instance = new EntityManager();
        }
        return instance;
    }

private:
    std::vector<std::shared_ptr<Entity> > entities;
    static EntityManager *instance;

public:
    virtual ~EntityManager() = default;

    virtual void updateAll(double delta_time);

    virtual void renderAll();

    virtual void initialize(Entity *entity);

    [[nodiscard]] std::vector<std::shared_ptr<Entity> > getEntities() const {
        return entities;
    }
};

#endif //ENTITYMANAGER_H
