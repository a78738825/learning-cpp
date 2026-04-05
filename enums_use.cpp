#include <iostream>  // Allows us to use input/output like cout
using namespace std; // So we don't have to write std:: every time

/*
    WHAT IS AN ENUM?

    "enum" stands for "enumeration".

    It is a user-defined data type that allows you to assign names
    to a set of integer values.

    Instead of writing:
        int day = 2;

    You can write:
        Day day = WEDNESDAY;

    This makes the code MUCH more readable and meaningful.
*/

// Define an enum named Day
enum Day {
  MONDAY,    // Automatically assigned value 0
  TUESDAY,   // 1
  WEDNESDAY, // 2
  THURSDAY,  // 3
  FRIDAY,    // 4
  SATURDAY,  // 5
  SUNDAY     // 6
};

/*
    Important notes:
    - By default, the first value = 0
    - Each next value increases by 1
    - You CAN manually assign values if you want (we'll mention later)
*/

int main() {

  // Create a variable of type Day
  Day today;

  /*
      "today" can ONLY store one of the values defined in the enum:
      MONDAY, TUESDAY, ..., SUNDAY

      It cannot store random numbers like 100 (without casting).
  */

  // Assign a value to the enum variable
  today = WEDNESDAY;

  /*
      Internally, WEDNESDAY = 2
      But we use the name instead of the number for clarity.
  */

  // Print the numeric value
  cout << "Numeric value of today: " << today << endl;

  /*
      Output will be:
      Numeric value of today: 2

      Because WEDNESDAY maps to 2
  */

  // Using enum in an if statement
  if (today == WEDNESDAY) {
    cout << "It's Wednesday!" << endl;
  }

  /*
      We compare enum values just like integers,
      but using names instead of numbers.
  */

  // Using enum in a switch statement
  switch (today) {

  case MONDAY:
    cout << "Start of the week" << endl;
    break;

  case FRIDAY:
    cout << "Almost weekend!" << endl;
    break;

  case SATURDAY:
  case SUNDAY:
    cout << "Weekend vibes!" << endl;
    break;

  default:
    cout << "Midweek day" << endl;
  }

  /*
      switch works very nicely with enums because:
      - The values are fixed
      - The names are clear
  */

  return 0;
}
