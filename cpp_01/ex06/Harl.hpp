#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

class Harl
{
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    static const std::string levels[4];
    static void (Harl::*const funcPtrs[4])(void);

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif