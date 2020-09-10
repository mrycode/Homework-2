/****
* PSEUDOCODE:
* LinearSearch takes in the arguments list, list size and number to find.
* Loop through array and compare with number to the number to find.
* Return index if number exists in the list.
* Return -1 if the number is not in the list.
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
* While loop through the list and adjust the mid_point of list to attempt to
* locate the number to find is in the list.
* Return index if the mid_point matches the number to find.
* If mid_point number is less than the number to find, change start point to
* mid_point + 1.
* If mid_point number is greater than the number to find, change end point to
* mid_point - 1.
* Return -1 if number is not found in list.
*/
int BinarySearch(int numbers[], int length, int find_number) {
  int start_point = 0;
  int mid_point;
  int end_point = length-1;

  bool found = false;

  while (!found && start_point <= end_point) {
    mid_point = (start_point + end_point)/2;

    if (numbers[mid_point] == find_number) {
      found = true;
      return mid_point;
    }
    else if (numbers[mid_point] > find_number) {
      end_point = mid_point - 1;
    }
    else {
      start_point = mid_point + 1;
    }
  }
  return -1;
}
