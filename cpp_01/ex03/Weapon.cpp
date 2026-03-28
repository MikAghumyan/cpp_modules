#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string &type) : m_type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(const std::string &type) { this->m_type = type; }

const std::string &Weapon::getType() const { return this->m_type; }