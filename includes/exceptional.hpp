#ifndef EXCEPTIONAL_HPP
#define EXCEPTIONAL_HPP

#include <string>

// Generates an exceptionally super-secret code based on the provided seed.
int ExceptionalSecretCode(int seed);

// Generates an exceptional employee badge number based on the employee's name
// and office number. Seems to only work for employees at Exceptional Software
// LLC?!
int ExceptionalEmployeeBadgeNumber(std::string employee_name, int office_no);

#endif  // EXCEPTIONAL_HPP
