//
// Created by halma on 2025. 08. 03.
//
#ifndef ENTITY_H
#define ENTITY_H

struct Entity {

private:
    const char * m_uid = nullptr;
    const char * m_name = nullptr;
    bool m_initialized = false;
    bool m_destroyed = false;

public:
    virtual void init() {
        if (!m_initialized) {
            m_initialized = true;
        }
    }

    virtual void update(double delta_time);

    virtual void render();

    virtual void destroy() { if (!m_destroyed) m_destroyed = true; };

    [[nodiscard]] virtual bool isAlive() const {
        return m_initialized && !m_destroyed;
    }

    explicit Entity(const char * name);
    virtual ~Entity() = default;


private:
    static const char * generateUID();

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

    void set_name(const char *m_name) {
        this->m_name = m_name;
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
