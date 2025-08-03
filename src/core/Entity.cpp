//
// Created by halma on 2025. 08. 03.
//

#include "Entity.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>

std::string Entity::generateUID() {
    static boost::uuids::random_generator generator;

    // Generate a new UUID
    boost::uuids::uuid uuid = generator();
    // Convert to string and return
    return boost::uuids::to_string(uuid);
}

Entity::Entity(const char * name) {
    m_name = name;

    // Generate a new unique ID for each entity
    std::string generated_uid = generateUID();
    // Store the generated UID in a member variable to maintain its lifetime
    m_uid_storage = generated_uid;
    m_uid = m_uid_storage.c_str();
}

void Entity::update(double delta_time) {

}

void Entity::render() {
    // Default render implementation does nothing
}

