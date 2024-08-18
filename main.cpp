#include <bits/stdc++.h>
using namespace std;

vector<int> quicksort(vector<int> array1) {
  // if an array has 1 or 0 elements it is already sorted
  if (array1.size() <= 1) {
    return array1;
  }

  // pick a pivot element
  int middle = array1.size() / 2;
  int pivot = array1[middle];

  // create two arrays to hold elements less than and greater than the pivot
  vector<int> lo;
  vector<int> hi;

  for (auto i = 0; i < array1.size(); i++) {

    // skip the pivot value itself
    if (i == middle) {
      continue;
    }

    // put the currentitem in the appropriate array
    int currentitem = array1[i];
    if (currentitem < pivot) {
      lo.push_back(currentitem);
    } else if (currentitem > pivot) {
      hi.push_back(currentitem);

      // if it's equal to the pivot, decide based on position
    } else {
      if (i < middle) {
        lo.push_back(currentitem);
      } else {
        hi.push_back(currentitem);
      }
    }
  }

  // recursively sort the two arrays
  vector<int> output;
  lo = quicksort(lo);
  hi = quicksort(hi);

  // combine the smaller array, the pivot, and the larger array
  for (int i = 0; i < lo.size(); i++) {
    output.push_back(lo[i]);
  }

  output.push_back(pivot);

  for (int i = 0; i < hi.size(); i++) {
    output.push_back(hi[i]);
  }

  return output;
}

// function to obtain the array to be sorted from the user
vector<int> obtain_user_input(void) {
  vector<int> input_array;
  string user_input;
  cout << "Press enter after each number, and enter after nothing to finish: "
       << endl;

  while (1) {
    getline(cin, user_input);
    if (user_input.empty()) {
      break;
    }
    try {
      int num = stoi(user_input);
      input_array.push_back(num);
    } catch (invalid_argument &e) {
      cout << "invalid input. Please enter a valid number: ";
    }
  }

  return input_array;
}

int main() {
  vector<int> sorted = quicksort(obtain_user_input());

  // print sorted array
  cout << "Sorted array: ";
  for (int i = 0; i < sorted.size(); i++) {
    cout << sorted[i] << " ";
  }
  return 0;
}
