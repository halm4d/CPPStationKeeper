//
// Created by halma on 2025. 08. 03.
//

#include "Entity.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>

const char * Entity::generateUID() {
    static boost::uuids::random_generator generator;

    boost::uuids::uuid uuid = generator();
    static std::string uid_str = boost::uuids::to_string(uuid);

    return uid_str.c_str();
}

Entity::Entity(const char * name) : name(name) {
    static std::string generated_uid = generateUID();
    uid = generated_uid.c_str();
}

void Entity::update(double delta_time) {

}

void Entity::render() {
    // Default render implementation does nothing
}

