#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <stdexcept>
#include <string>
#include <vector>

#include "exceptional.hpp"

// PART 1

// Returns a string of the form "[Employee Name] can access office number
// [Office Number] with Badge Number [Badge Number] and Passkey [Secret Code]."
// or an error string as specificed in the documentation.
// When a seed is necessary, use the office number + 5.
std::string GenerateEmployeeCredentials(const std::string& employee_name,
                                        int office_no);

// PART 2

// Data struct containing all the information to represent a date
struct Date {
  int month;
  int day;
  int year;
};

// Data struct that details a step in the password generation process
struct Instruction {
  char operation;
  std::string operand;
};

// Determines is a Date is valid as specified in the documentation.
bool IsValidDate(Date date);

// Runs through an instruction using the given starting value. If the
// instruction is invalid or there is an arithmetic/range error, throws the
// required exception.
int ExecuteInstruction(Date date, Instruction instruction, int value);

// Generates a password following the procedure for the given date with the
// initial value.
int PasswordFromDate(Date date,
                     const std::vector<Instruction>& procedure,
                     int salt);

#endif  // SOLUTION_HPP
