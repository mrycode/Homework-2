/****
* PSEUDOCODE:
*
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

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
  //cout << fixed << showpoint << setprecision(precision+1);

  for (int integer = 0; integer < number; integer++) {
    if (power_num(integer, nth) <= number) {
      left_handside = integer;
    }
    else if (power_num(integer, nth) > number) {
      break;
    }
  }

  long double precision_number = static_cast<double>(left_handside);
  long double test_num = static_cast<double>(left_handside);
  long double round_up, precision_location, precision_location_counter, output_precision_number, output_precision_number_round_up;
  
  
  for (int precision_index = 1; precision_index < precision + 2; precision_index++) {
    precision_location = 1/static_cast<double>(power_num(10, precision_index));
    precision_location_counter = 0;

    for (int precision_counter = 0; precision_counter < 10; precision_counter++) {
      test_num += precision_location;;
      precision_location_counter += precision_location;
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

    //cout << precision_location_counter - precision_location << endl;
    //cout << precision_location * 5 << endl;

    if (precision_index == precision) {
      //cout << "setting" << endl;
      output_precision_number = precision_number;
      output_precision_number_round_up = round_up;
    }
    else if (precision_index == precision+1) {
      //cout << "in" << endl;
      if (precision_location_counter - precision_location >= precision_location * 5) {
        stringstream output_string;
        output_string << fixed << showpoint << setprecision(precision) << output_precision_number_round_up;
        return output_string.str(); 
        //cout << "this is a string " << test << endl;
        //cout << output_precision_number_round_up << endl;
      }
      else {
        stringstream output_string;
        output_string << fixed << showpoint << setprecision(precision) << output_precision_number;
        return output_string.str(); 
        //cout << "this is a string " << test << endl;
        //cout << output_precision_number << endl;
      }
    }
  }
  //cout << precision_location_counter - precision_location << endl;
  //cout << precision_number << endl;
  //cout << round_up << endl;
  
  

  return "";
}
