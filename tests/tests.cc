// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "solution.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////


// PART 1

TEST_CASE("Unexceptional", "[part_1]") {
  REQUIRE(GenerateEmployeeCredentials("Zulu", 22) ==
          "Zulu can access office number 22 with Badge Number 154 and Passkey "
          "729.");
  REQUIRE(GenerateEmployeeCredentials("Peter", 36) ==
          "Peter can access office number 36 with Badge Number 13 and Passkey "
          "41.");
  REQUIRE(GenerateEmployeeCredentials("Tommy", 18) ==
          "Tommy can access office number 18 with Badge Number 151 and Passkey "
          "529.");
}

TEST_CASE("ExceptionalEmployeeBadgeNumber Exceptions", "[part_1]") {
  SECTION("std::invalid_argument") {
    REQUIRE(GenerateEmployeeCredentials("", 32) ==
            "ExceptionalEmployeeBadgeNumber threw std::invalid_argument with "
            "message: No nameless employees!");
    REQUIRE(GenerateEmployeeCredentials("", 38) ==
            "ExceptionalEmployeeBadgeNumber threw std::invalid_argument with "
            "message: No nameless employees!");
  }

  SECTION("std::out_of_range") { REQUIRE(true == true); }

  SECTION("std::runtime_error") {
    REQUIRE(GenerateEmployeeCredentials("Abby", 19) ==
            "ExceptionalEmployeeBadgeNumber threw std::runtime_error with "
            "message: Unknown employee.");
    REQUIRE(GenerateEmployeeCredentials("Charles", 23) ==
            "ExceptionalEmployeeBadgeNumber threw std::runtime_error with "
            "message: Unknown employee.");
    REQUIRE(GenerateEmployeeCredentials("Johnathan", 18) ==
            "ExceptionalEmployeeBadgeNumber threw std::runtime_error with "
            "message: Unknown employee.");
    REQUIRE(GenerateEmployeeCredentials("Lucy", 36) ==
            "ExceptionalEmployeeBadgeNumber threw std::runtime_error with "
            "message: Unknown employee.");
  }

  SECTION("std::logic_error") {
    REQUIRE(GenerateEmployeeCredentials("Zach", -1) ==
            "ExceptionalEmployeeBadgeNumber threw std::logic_error with "
            "message: Unable to locate office.");
    REQUIRE(GenerateEmployeeCredentials("Patty", 101) ==
            "ExceptionalEmployeeBadgeNumber threw std::logic_error with "
            "message: Unable to locate office.");
  }
}

TEST_CASE("ExceptionalSecretCode Exceptions", "[part_1]") {
  SECTION("std::invalid_argument") { REQUIRE(true == true); }

  SECTION("std::out_of_range") {
    REQUIRE(GenerateEmployeeCredentials("Zulu", 91) ==
            "ExceptionalSecretCode threw std::out_of_range with "
            "message: Seed too big/small.");
    REQUIRE(GenerateEmployeeCredentials("Ruth", 6) ==
            "ExceptionalSecretCode threw std::out_of_range with "
            "message: Seed too big/small.");
  }

  SECTION("std::runtime_error") {
    REQUIRE(GenerateEmployeeCredentials("Penelope", 10) ==
            "ExceptionalSecretCode threw std::runtime_error with "
            "message: Whoops! You got us!");
    REQUIRE(GenerateEmployeeCredentials("Xander", 20) ==
            "ExceptionalSecretCode threw std::runtime_error with "
            "message: Whoops! You got us!");
  }

  SECTION("std::logic_error") {
    REQUIRE(GenerateEmployeeCredentials("Zach", 16) ==
            "ExceptionalSecretCode threw std::logic_error with "
            "message: Didn't think of that!");
    REQUIRE(GenerateEmployeeCredentials("Yannie", 37) ==
            "ExceptionalSecretCode threw std::logic_error with "
            "message: Didn't think of that!");
  }

  SECTION("Mystery Exception") {
    REQUIRE(GenerateEmployeeCredentials("Zach", 65) ==
            "ExceptionalSecretCode caused an unknown error.");
    REQUIRE(GenerateEmployeeCredentials("Tyler", 100) ==
            "ExceptionalSecretCode caused an unknown error.");
  }
}

// PART 2

TEST_CASE("IsValidDateTrue", "[part_2][IsValidDate]") {
  REQUIRE(IsValidDate({10, 18, 1987}));
  REQUIRE(IsValidDate({2, 26, 3040}));
  REQUIRE(IsValidDate({9, 10, 2005}));
}

TEST_CASE("IsValidDateBasicRange", "[part_2][IsValidDate]") {
  REQUIRE_FALSE(IsValidDate({41, 18, 1987}));
  REQUIRE_FALSE(IsValidDate({-10, 26, 3040}));
  REQUIRE_FALSE(IsValidDate({9, -10, 2005}));
  REQUIRE_FALSE(IsValidDate({6, 31, 2002}));
  REQUIRE_FALSE(IsValidDate({7, 31, 1964}));
}

TEST_CASE("IsValidDateLeapYear", "[part_2][IsValidDate]") {
  REQUIRE(IsValidDate({2, 29, 1980}));
  REQUIRE_FALSE(IsValidDate({2, 29, 1961}));
  REQUIRE_FALSE(IsValidDate({2, 29, 2100}));
  REQUIRE(IsValidDate({2, 29, 2000}));
}

TEST_CASE("InstructionFunctionality", "[part_2][ExecuteInstruction]") {
  REQUIRE(ExecuteInstruction({7, 19, 2002}, {'+', "-20"}, 50) == 30);
  REQUIRE(ExecuteInstruction({6, 4, 2007}, {'+', "day"}, 3) == 7);
  REQUIRE(ExecuteInstruction({8, 13, 2004}, {'*', "month"}, 12) == 96);
  REQUIRE(ExecuteInstruction({2, 28, 3213}, {'-', "year"}, 3216) == 3);
  REQUIRE(ExecuteInstruction({4, 9, 2026}, {'/', "day"}, 89) == 9);
}

TEST_CASE("InvalidInstruction", "[part_2][ExecuteInstruction]") {
  REQUIRE_THROWS_AS(ExecuteInstruction({1, 2, 1984}, {'?', "100"}, 10),
                    std::invalid_argument);
  REQUIRE_THROWS_AS(ExecuteInstruction({1, 2, 1984}, {'+', "blergh"}, 10),
                    std::invalid_argument);
  REQUIRE_THROWS_AS(ExecuteInstruction({1, 2, 1984}, {'%', "0"}, 10),
                    std::domain_error);
  REQUIRE_THROWS_AS(ExecuteInstruction({1, 2, 1984}, {'*', "1000"}, 1000),
                    std::range_error);
}

TEST_CASE("PasswordFromDateFunctionality", "[part_2][PasswordFromDate]") {
  Instruction i1 = {'+', "70"};
  Instruction i2 = {'*', "day"};
  Instruction i3 = {'%', "7"};
  Instruction i4 = {'/', "month"};
  REQUIRE(PasswordFromDate({1, 3, 1992}, {i1, i2}, 13) == 249);
  REQUIRE(PasswordFromDate({6, 14, 2012}, {i4, i3}, 1880) == 5);
}

TEST_CASE("PasswordFromDateException", "[part_2][PasswordFromDate]") {
  Instruction i1 = {'+', "70"};
  Instruction i2 = {'*', "day"};
  Instruction i3 = {'%', "0"};
  REQUIRE_THROWS_AS(PasswordFromDate({1, 3, 1964}, {i1, i2}, 13), std::invalid_argument);
  REQUIRE_THROWS_AS(PasswordFromDate({6, 14, 2012}, {i3, i1}, 1880), std::domain_error);
}

/////////////////////////////////////////////////////////////////////////////////////////////