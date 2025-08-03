//
// Created by halma on 2025. 08. 03.
//
#ifndef ENTITY_H
#define ENTITY_H

struct Entity {
    const char * uid = nullptr;
    const char * name = nullptr;
    bool initialized = false;
    bool destroyed = false;

    virtual void init() {
        if (!initialized) {
            initialized = true;
        }
    }

    virtual void update(double delta_time);

    virtual void render();

    virtual void destroy() { if (!destroyed) destroyed = true; };

    [[nodiscard]] virtual bool isAlive() const {
        return initialized && !destroyed;
    }

    explicit Entity(const char * name);
    virtual ~Entity() = default;


private:
    static const char * generateUID();
};

#endif // ENTITY_H
