//
// Created by halma on 2025. 08. 03.
//
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {

protected:
    const char * m_uid = nullptr;
    std::string m_uid_storage; // Store the UID string to maintain its lifetime
    const char * m_name = nullptr;
    bool m_initialized = false;
    bool m_destroyed = false;

public:
    // Core entity methods that can be overridden by derived classes
    virtual void init() {
        if (!m_initialized) {
            m_initialized = true;
        }
    }

    virtual void update(double delta_time);

    virtual void render();

    virtual void destroy() { 
        if (!m_destroyed) m_destroyed = true; 
    };

    [[nodiscard]] virtual bool isAlive() const {
        return m_initialized && !m_destroyed;
    }

    explicit Entity(const char * name);
    virtual ~Entity() = default; // Virtual destructor for proper cleanup of derived classes


private:
    // Generate a unique ID as a std::string
    static std::string generateUID();

public:
    [[nodiscard]] const char * uid() const {
        return m_uid;
    }

    void set_uid(const char *uid) {
        this->m_uid = uid;
    }

    [[nodiscard]] const char * name() const {
        return m_name;
    }

    void set_name(const char *name) {
        this->m_name = name;
    }

    [[nodiscard]] bool initialized() const {
        return m_initialized;
    }

    void set_initialized(bool initialized) {
        this->m_initialized = initialized;
    }

    [[nodiscard]] bool destroyed() const {
        return m_destroyed;
    }

    void set_m_destroyed(bool destroyed) {
        this->m_destroyed = destroyed;
    }
};

#endif // ENTITY_H
