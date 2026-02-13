#include <iostream>

#include "solution.hpp"

int main() {
  // PART 1

  std::string employee_name;
  int employee_office_number = 0;

  std::cout << "Enter Employee Name: ";
  std::cin >> employee_name;
  std::cout << "Enter Employee Office Number: ";
  std::cin >> employee_office_number;

  std::cout << GenerateEmployeeCredentials(employee_name,
                                           employee_office_number)
            << std::endl;

  // PART 2

  return 0;
}
