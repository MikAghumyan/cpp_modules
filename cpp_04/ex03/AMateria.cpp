#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : m_type(type)
{
}

AMateria::AMateria(const AMateria &other) : m_type(other.m_type)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    (void)other;
    return *this;
}

std::string const &AMateria::getType() const
{
    return m_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << m_type << " on " << target.getName() << " *" << std::endl;
}