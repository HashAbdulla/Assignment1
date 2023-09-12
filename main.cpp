#include "functions.h"

//function to display options to user
void Menu() {
    cout << "\nWelcome! What would you like to do with the array?:"
       << "\n======================="
       << "\n\t1 - check if a certain integer exists in the array"
       << "\n\t2 - modify the value of an integer"
       << "\n\t3 - add a new integer to the end of the array"
       << "\n\t4 - See contents of array"
       << "\n\t5 - replace a value with 0"
       << "\n\tQ - Quit"
       << "\n======================="
       << "\nYour Choice: ";
}


//A function to check if a certain integer exists in the array. If the number is present, return the index where the number is present
int check(int arr[], int size){
  int target;
  cout<<"please enter the number you are looking for ";
  cin>>target;
  
  for(int i = 0; i < size; i++){
    if(arr[i] == target){
      cout<<"specified integer found at index "<< i <<endl;
      return i;
    }
  }
  cout<<"specified integer not found!";
  return -1;
}

//A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
void modifyValue(int arr[], int size) {
    int index;
    int newValue;

    try {
        cout << "Enter the index of the value you want to modify: ";
        cin >> index;

        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index. Please enter a valid index within the array range.");
        }

        cout << "Enter the new value: ";
        cin >> newValue;

        int oldValue = arr[index];
        arr[index] = newValue;

        cout << "Old value at index " << index << ": " << oldValue << endl;
        cout << "Modified value at index " << index << ": " << newValue << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//A function that adds a new integer to the end of the array
void addIntegerToEnd(int arr[], int& size, int valueToAdd) {
    try {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input. Please enter a valid integer.");
        }

        // Add the value to the end of the array
        arr[size] = valueToAdd;
        size++;
        cout << "Added " << valueToAdd << " to the end of the array." << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//A function to see the contents of the dynamic array
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether.
void replaceValueAtIndex(int arr[], int& size, int index, int value) {
    if (index >= 0 && index < size) {
        if (value == 0) {
            cout << "Replaced value at index " << index << ": " << arr[index] << " with 0." << endl;
            arr[index] = 0;
        } else {
            cout << "Removed value at index " << index << ": " << arr[index] << endl;
            for (int i = index; i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    } else {
        cout << "Invalid index. Please enter a valid index within the array range." << endl;
    }
}

int main() {

  int* integers= nullptr;
  int size=0;
  string filename;
  cout<<"please input name of file to open: ";
  cin >> filename;
  
  //throws an error if can't open file
  ifstream fin(filename);
  while (!fin.is_open()) {
    cout << "File name invalid!" << endl;
    cout << "Please input the name of the file to open: ";
    cin >> filename;
    fin.open(filename);
  }


//load integers into the array
   int value;
   while (fin >> value) {
        // Increase the size of the array and reallocate memory
        int* newIntegers = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newIntegers[i] = integers[i];
        }
        newIntegers[size] = value;
        delete[] integers; // Free the old memory
        integers = newIntegers;
        ++size;
    }
  


while (true) {
    Menu();
    char choice= 'N';
    cin>>choice;
    choice= toupper(choice);
    cout<<"You chose "<<choice<<endl;
    switch(choice) {
    case '1':
     check(integers,size);
      break;
    case '2':
      modifyValue(integers, size);
      break;
    case '3':
      int valueToAdd;
      cout << "Enter the integer to add to the end of the array: ";
      cin >> valueToAdd;
      addIntegerToEnd(integers, size, valueToAdd);
      break;
    case '4':
      printArray(integers, size);
      break;
    case '5':
      int index;
  cout << "Enter the index of the value to replace with 0 or remove: ";
      cin >> index;
      int replaceValue;
  cout << "Enter 0 to replace with 0, or any other integer to remove: ";
     cin >> replaceValue;
      replaceValueAtIndex(integers, size, index, replaceValue);
      break;
    case 'Q':
      cout<<"Exiting..."<<endl;
      break;

    default:
      cout<<"please enter a valid choice";
      
    }
    if (choice=='Q') {
      cout <<"Thank you, have a nice day!"<<endl;
      break;
    }
    
  
}
delete[] integers; //deallocating the dynamic array, otherwise a memory leak will be caused
return 0;
} 

  
