/****
* PSEUDOCODE:
*
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int power_num(int number, int nth) {
  int power_counter = number;
  for (int nth_counter = 1; nth_counter < nth; nth_counter++) {
    power_counter *= number;
  }
  return power_counter;
}

long double power_num(long double number, int nth) {
  double power_counter = number;
  for (int nth_counter = 1; nth_counter < nth; nth_counter++) {
    power_counter *= number;
  }
  return power_counter;
}




string FindNthRoot(int number, int nth, int precision) {
  int left_handside;
  cout << fixed << showpoint << setprecision(precision);

  for (int integer = 0; integer < number; integer++) {
    if (power_num(integer, nth) <= number) {
      left_handside = integer;
    }
    else if (power_num(integer, nth) > number) {
      break;
    }
  }

 
  /*
  double start_precision_point = static_cast<double>(left_handside);
  double end_precision_point = static_cast<double>(left_handside)+(1-(1/static_cast<double>(power_num(10, precision))));
  double mid_precision_number = static_cast<double>(left_handside)+((1-(1/static_cast<double>(power_num(10, precision))))/2);

  cout << mid_precision_number << endl;
  */

  //cout << power_num(5.5, 2) << endl;

  //int precision_counter = precision;
  long double precision_number = static_cast<double>(left_handside);
  long double test_num = static_cast<double>(left_handside);
  long double round_up;
  
  for (int precision_index = 1; precision_index < precision+1; precision_index++) {
    double precision_location = 1/static_cast<double>(power_num(10, precision_index));
    

    for (int precision_counter = 0; precision_counter < 10; precision_counter++) {
      test_num += precision_location;
      //cout << test_num << endl;
      if (power_num(test_num, nth) < number) {
        precision_number = test_num;
      }
      else if (power_num(test_num, nth) >= number) {
        round_up = test_num;
        test_num = precision_number;
        break;
      }
    }
  }
  
  cout << round_up << endl;


//2.449489743

  return "";
}
/*
if (power_num(precision_multiplier, nth) <= number) {
        left_handside = precision_multiplier;
      }
      else if (power_num(precision_multiplier, nth) > number) {
        break;
      }*/