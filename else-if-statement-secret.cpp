#include <iostream>
using namespace std;

int main() {
  int number = 10;

  // First condition
  if (number < 5) {
    cout << "Number is less than 5" << endl;
  }

  // "else if" means:
  // If the previous "if" was false,
  // THEN check another "if" condition
  else if (number < 15) {
    cout << "Number is less than 15 but not less than 5" << endl;
  }

  // If none of the above conditions were true
  else {
    cout << "Number is 15 or greater" << endl;
  }

  // Above else-if and else statement are same as:
  // else {
  //     if (number < 15) {   // this is the "if" that forms "else if"
  //         cout << "Number is less than 15 but not less than 5" << endl;
  //     }
  //     else {
  //         cout << "Number is 15 or greater" << endl;
  //     }

  return 0;
}
