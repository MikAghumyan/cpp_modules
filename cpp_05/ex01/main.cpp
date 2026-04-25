#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form1("mashni paymanagir", 130, 130);
    Bureaucrat b1("Vigen", 125);
    Bureaucrat b2("Vazgen", 135);

    std::cout << form1 << std::endl;
    b1.signForm(form1);
    b2.signForm(form1);

    return (0);
}