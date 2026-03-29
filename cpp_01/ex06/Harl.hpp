#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    static const std::string levels[4];

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif