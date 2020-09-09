#include <iostream>
#include <string>
using namespace std;

/****
* PSEUDOCODE:
*
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
*
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
*
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
*
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