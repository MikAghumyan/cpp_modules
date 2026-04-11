#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        m_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        m_templates[i] = other.m_templates[i] ? other.m_templates[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete m_templates[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < templatesSize; ++i)
        {
            if (m_templates[i])
                delete m_templates[i];
            m_templates[i] = other.m_templates[i] ? other.m_templates[i]->clone() : NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return;
    for (int i = 0; i < templatesSize; ++i)
    {
        if (!m_templates[i])
        {
            m_templates[i] = materia;
            return;
        }
    }

    delete materia;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < templatesSize; ++i)
        if (m_templates[i] && m_templates[i]->getType() == type)
            return (m_templates[i]->clone());
    return (NULL);
}