/****
* PSEUDOCODE:
* LinearSearch takes in the arguments list, list size and number to find.
* for loop through array and compare with number to the number to find.
*   return index if number exists in the list.
* return -1 if the number is not in the list.
*/
int LinearSearch(int numbers[], int length, int find_number) {
  for (int index = 0; index < length; index++) {
    if (numbers[index] == find_number) {
      return index;
    }
  }
  return -1;
}

/****
* PSEUDOCODE:
* BinarySearch takes in the arguments list, list size and number to find.
* Initialize local variables for start, mid, and end points for the list.
*   While loop through the list and adjust the mid_point of list to attempt to
*   locate the number to find is in the list.
*   return index if the mid_point matches the number to find.
*   if mid_point number is less than the number to find, 
*     then change start point to mid_point + 1.
*   else if mid_point number is greater than the number to find, 
*     then change end point to mid_point - 1.
* return -1 if number is not found in list.
*/
int BinarySearch(int numbers[], int length, int find_number) {
  int start_point = 0;
  int mid_point;
  int end_point = length-1;
  bool found = false;

  //Loop until variable is found or not found in the list
  while (!found && start_point <= end_point) {
    mid_point = (start_point + end_point)/2;
    //Locate variable in list
    if (numbers[mid_point] == find_number) {
      found = true;
      return mid_point;
    }
    //Adjust end points if mid point variable is less than or greater than the search criteria
    else if (numbers[mid_point] > find_number) {
      end_point = mid_point - 1;
    }
    else {
      start_point = mid_point + 1;
    }
  }
  return -1;
}
