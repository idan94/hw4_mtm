#ifndef TEST_UTILITIES_H_
#define TEST_UTILITIES_H_

#include <cstdio>
#include <cmath>

void _print_error(int test_num, const char *errorName, int lineNumber) {
  printf("\t\tTest %2d failed\n", test_num + 1);
  printf(
      "\n***************************************************************************");
  printf("\nError Line: %d\nError description:\n%-80s", lineNumber, errorName);
  printf(
      "\n***************************************************************************\n");
}

void _print_test_number(int test_number, int line_num) {
  printf("Running test %2d at line number: %3d.", test_number + 1,
         line_num);
}

void _print_test_success(int test_number) {
  printf("\t\tTest %2d passed successfully\n", test_number + 1);
}

void _print_mode_name(const char *name) {
  printf(
      "---------------------------------------------------------------------------");
  printf("\n\t\t    %s", name);
  printf(
      "\n---------------------------------------------------------------------------\n");
}

void test(bool expression,
          const char *error_code,
          int line,
          int *test_number,
          int *tests_passed) {
  _print_test_number(*test_number, line);
  if (expression)
    _print_error(*test_number, error_code, line);
  else {
    _print_test_success(*test_number);
    *tests_passed += 1;
  }
  *test_number += 1;

}

void print_grade(int tests_number, int tests_passed) {
  auto grade = (int) (((double) tests_passed / tests_number) * 100);
  if (grade == 100) {
    printf(" \n __________________________________________________ \n");
    printf("| Windows Dialog                      [-] [ ] [X]  |\n");
    printf("| ''''''''''''''                                   |\n");
    printf("| Windows has detected that YOU are awesome!       |\n");
    printf("|    Do you agree?                                 |\n");
    printf("|                                                  |\n");
    printf("|         |YES!|      |YES!|      |YES!|           |\n");
    printf("|                                                  |\n");
    printf("|__________________________________________________|\n");
    printf("               Now go grab a beer!                  \n");
  }
  if (grade <= 99 && grade > 55) {
    printf("\n 		Not that much left!					             \n");
    printf("                                      &&   &&            \n");
    printf("  &&&&.                         &&&  .&&&&&              \n");
    printf("      &&     &&&                   &&&&&&&&&             \n");
    printf(" &&&&&&&&&  &         &`           &&       &&           \n");
    printf("      .&&&&&          &&&;        &8                     \n");
    printf("  .&&&:     &&        &` &      &&                       \n");
    printf("             8&&      &   `&   &&                        \n");
    printf("               &&    .&_ oO_&.-.-.                       \n");
    printf("                 && ( __     -/--'                       \n");
    printf("                  &&~ .'-__-'&                           \n");
    printf("                   &&&~`'\\`&                            \n");
    printf("                     &&&~` _&                            \n");
    printf("                      &&&&` &&                           \n");
    printf("                 &     &&8&&&&                           \n");
    printf("                  &    &&&&&&&                           \n");
    printf("                   &  &&&&&&&                            \n");
    printf("                 &&;&&&&&&&                              \n");
    printf("                &&&&&&&&&&     ~~~                       \n");
    printf("         .~~~~~ `&&&&&&&&&    ~~~~                       \n");
    printf("     ~~~~~~~~~;!&&&&&&&&&&~/~~~~~~~~~                    \n");
    printf("  ~~~~~~~~\\~~~~&/`      \\`~~~~~~~~~~~~                 \n");
    printf("   ~~~~~~~~             `~~~~~~~~~~                      \n");
    printf("    ~~~~~~              ~~~~~~~                          \n");
    printf("    ~~~~                ~~~~                             \n");
  }
  if (grade <= 55)
    printf(
        " \t  ___________\n\t/   R.I.P.   \\ \n\t| Here lies   |\n\t| Your  grade |\n\t|_____%2d______|\n",
        grade);
  printf("Your grade is: %d\n", grade);
  printf("You've passed %d tests out of %d\n", tests_passed, tests_number);
  printf("Good luck in the next part!\n");
}

#endif /* TEST_UTILITIES_H_ */
