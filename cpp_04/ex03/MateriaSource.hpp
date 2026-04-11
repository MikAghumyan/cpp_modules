#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    virtual ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &other);

    virtual void learnMateria(AMateria *materia);
    virtual AMateria *createMateria(std::string const &type);

private:
    static const int templatesSize = 4;
    AMateria *m_templates[4];
};

#endif