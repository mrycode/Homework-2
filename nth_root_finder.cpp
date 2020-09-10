#include "nth_root_finder.h"

/****
* PSEUDOCODE:
* PowerNum accepts number and nth term
*   for loop to increase the number by multiplying itself by nth times
* return value
*/
long long int PowerNum(int number, int nth) {
  long long int power_counter = number;
  if (nth == 0) {
    return 1;
  }
  else {
    for (int nth_counter = 1; nth_counter < nth; nth_counter++) {
      power_counter *= number;
    }
  }
  return power_counter;
}

//Overload power_num to accept and output floating point values
long double PowerNum(long double number, int nth) {
  long double power_counter = number;
  if (nth == 0) {
    return 1;
  }
  else {
    for (int nth_counter = 1; nth_counter < nth; nth_counter++) {
      power_counter *= number;
    }
  }
  return power_counter;
}

/****
* PSEUDOCODE:
* FindNthRoot accepts number, nth term and precision as arguments
*   Initialize left most variable
*     for loop integers until number is reached
*       if passed integer into the power function is less than or equal to the number,
*         then assign the integer to the left most variable
*       else if passed integer into the power function is greater than the number,
*         then break out of loop and the left most value has been located
*   If precision is 0, then return let most variable
*   else
*     Initialize variable for precision variables, test variables, and output variables
*     for loop incrementing for each precision position
*       Initialize the precision position value by dividing the powers of 10
*       for loop from 1 - 9 based on the precision position
*         if passed integer into the power function is less than or equal to the number,
*           then add the value to the precision position
*         else if passed integer into the power function is greater than the number,
*           then break out of loop and the precision position value has been located
*     if precision index equal precision,
*       then assign the values to the output variables
*     else if precision index equal precision +1
*       if output variable needs to round up
*         then create object stringstream with rounded up output variable, 
*         setprecision to requested precision, stream floar to string,
*         and return string
*       else if output variable does not need to round up
*         then create object stringstream with output variable, 
*         setprecision to requested precision, stream floar to string,
*         and return string
*/
string FindNthRoot(int number, int nth, int input_precision) {
  int left_handside;

  //Loop through until the left most value is located and exit loop once located
  for (int integer = 0; integer < number; integer++) {
    if (PowerNum(integer, nth) <= number) {
      left_handside = integer;
    }
    else if (PowerNum(integer, nth) > number) {
      break;
    }
  }

  if (input_precision == 0) {
    stringstream output_string;
    output_string << left_handside;
    return output_string.str();
  }
  else {
    //Initialize variables for output, testing, and counters to track position
    long double precision_number = static_cast<double>(left_handside);
    long double test_variable = static_cast<double>(left_handside);
    long double round_up, precision_position, precision_position_counter, output_precision_number, output_precision_number_rounded_up;

    //Outer loop that sets the precision value to be used for testing and incrementing postion index
    for (int precision_index = 1; precision_index < input_precision + 2; precision_index++) {
      //Initialize precision position value and precision counter
      precision_position = 1/static_cast<double>(PowerNum(10, precision_index));
      precision_position_counter = 0;

      //Inner loop to locate the value raised to the nth position
      for (int precision_counter = 0; precision_counter < 10; precision_counter++) {
        test_variable += precision_position;;
        precision_position_counter += precision_position;

        //If precision value is not found, then assign to the precision number to track the value
        if (PowerNum(test_variable, nth) < number) {
          precision_number = test_variable;
        }
        //If precision value is to large, then save the value as the rounded up value of the precision point and exit inner loop
        else if (PowerNum(test_variable, nth) >= number) {
          round_up = test_variable;
          test_variable = precision_number;
          break;
        }
      }

      //If requested precision is reached, then assign the precision and the rounded up value to the output variables
      if (precision_index == input_precision) {
        output_precision_number = precision_number;
        output_precision_number_rounded_up = round_up;
      }
      //If the precision index has reached the end of the outer loop, then test if the out put variable must round up
      else if (precision_index == input_precision+1) {
        //If the precision position + 1 value is greater than or equal to 5, then convert the rounded up variable to a string and return the string output 
        if (precision_position_counter - precision_position >= precision_position * 5) {
          stringstream output_string;
          output_string << fixed << showpoint << setprecision(input_precision) << output_precision_number_rounded_up;
         return output_string.str();
        }
        else {
          //If the precision position + 1 value is less than 5, then convert the rounded up variable to a string and return the string output
          stringstream output_string;
          output_string << fixed << showpoint << setprecision(input_precision) << output_precision_number;
          return output_string.str();
        }
      }
    }
  }
  return "";
}