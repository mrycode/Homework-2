#include <iostream>
#include "nth_root_finder.h"
#include "search.h"
#include "dictionary.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
  /* Search
  int list[] = {1,2,4,5,6,7,8,9};
  int array_length = 8;
  int number = 11;
  
  std::cout << "Linear Search: " << LinearSearch(list,array_length,number) <<  std::endl;

  std::cout << "Binar Search: " << BinarySearch(list,array_length,number) <<  std::endl;
  */
  
  /*
  string names[] = {"a", "bb", "bb", "bb", "ccc", "ccc", "ccc", "ccc"};
  int list_size = 8;

  cout << "Min Length: " << MinWordLength(names,list_size) << endl;
  cout << "Max Length: " << MaxWordLength(names,list_size) << endl;
  cout << "Range Length: " << WordLengthRange(names,list_size) << endl;
  cout << "Average Length: " << AverageWordLength(names,list_size) << endl;
  cout << "Mode Length: " << MostCommonWordLength(names,list_size) << endl;
  */

  cout << "string " << FindNthRoot(3, 6, 9) << endl;

  //2.4494897427832

  return 0;
}