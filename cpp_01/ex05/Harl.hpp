#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl
{
public:
    void complain(std::string level);

private:
    static void (Harl::*const funcPoints[4])(void);
    static const std::string levels[4];

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif