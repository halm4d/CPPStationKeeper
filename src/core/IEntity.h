//
// Created by halma on 2025. 08. 03..
//
#ifndef IENTITY_H
#define IENTITY_H

class IEntity {
public:
    bool initialized = false;
    bool destroyed = false;

    virtual ~IEntity() = default;

    virtual void init() {
        if (!initialized) {
            initialized = true;
        }
    };

    virtual void update(double delta_time) {}; // Empty implementation

    virtual void render() {}; // Empty implementation

    virtual void destroy() { if (!destroyed) destroyed = true; };

};

#endif // IENTITY_H
