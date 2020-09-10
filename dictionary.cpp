#include <iostream>
#include <string>
using namespace std;

/****
* PSEUDOCODE:
* MinWordLength take in a list and list size as arguments
* Initialize word length with first element in list to use as initial comparison
* For loop through list size
* if element in list's word length is less than the currnet smallest word legth,
*   then replace the smallest word length to new smallest word length value
* return smallest word length value
*/
int MinWordLength(string words[], int length) {
    //Locate the min word length
    int min_word_length = words[0].length();
    for (int index = 1; index < length; index++) {
      if (words[index].length() < min_word_length) {
        min_word_length = words[index].length();
      }
    }
    return min_word_length;
    throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* MaxWordLength take in a list and list size as arguments
* Initialize word length with first element in list to use as initial comparison
* For loop through list size
* if element in list's word length is greater than the currnet largest word legth,
*   then replace the largest word length to new largest word length value
* return largest word length value
*/
int MaxWordLength(string words[], int length) {
    //Locate the max word length
    int max_word_length = words[0].length();
    for (int index = 1; index < length; index++) {
      if (words[index].length() > max_word_length) {
        max_word_length = words[index].length();
      }
    }
    return max_word_length;
    throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* WordLengthRange take in a list and list size as arguments
* Find smallest word length
*   Initialize word length with first element in list to use as initial comparison
*   For loop through list size
*   if element in list's word length is less than the currnet smallest word legth,
*     then replace the smallest word length to new smallest word length value
* Find largest word length
*   Initialize word length with first element in list to use as initial comparison
*   For loop through list size
*   if element in list's word length is greater than the currnet largest word legth,
*     then replace the largest word length to new largest word length value
* return range (largest word length - smallest word length)
*/

int WordLengthRange(string words[], int length) {
    //Locate the min word length
    int min_word_length = words[0].length();
    for (int index = 1; index < length; index++) {
      if (words[index].length() < min_word_length) {
        min_word_length = words[index].length();
      }
    }
    //Locate the max word length
    int max_word_length = words[0].length();
    for (int index = 1; index < length; index++) {
      if (words[index].length() > max_word_length) {
        max_word_length = words[index].length();
      }
    }
    //Return the range by subtracting th max - min word length
    return max_word_length - min_word_length;
    throw "Unsupported Operation";
}

int AverageWordLength(string words[], int length) {
    int total_counter = 0;
    for (int index = 0; index < length; index++) {
      total_counter += words[index].length();
    }
    return total_counter/length;
    throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* MostCommonWordLength take in a list and list size as arguments
* Initialize variables to hold mode, mode counter, test value and test value conuter
* Outer for loop through index size to compare each element to itself
*   Initialize test mode and test mode counter
*   if test mode counter is less than mode counter
*     for loop through index to provide the value for camparison to the outer loop
*       if outer test mode equals the compared value,
*         then increment the test mode counter
*     if test mode counter is greater than mode counter,
*       then replace mode and mode counter with test mode and test mode counter
* return mode number that has the highest mode counter
*/
int MostCommonWordLength(string words[], int length) {
    int mode_num = 0;
    int mode_counter = 0;
    int test_mode = 0;
    int test__mode_counter = 0;
    for (int outer_index; outer_index < length; outer_index++) {
      test_mode = words[outer_index].length();
      test__mode_counter = 0;
      if (test__mode_counter <= mode_counter) {
        for (int inner_test_index = 0; inner_test_index < length; inner_test_index++) {
          if (test_mode == words[inner_test_index].length()) {
            test__mode_counter++;
          }
        }
        if (test__mode_counter >= mode_counter) {
          mode_num = test_mode;
          mode_counter = test__mode_counter;
        }
      }
    }
    return mode_num;
    throw "Unsupported Operation";
}