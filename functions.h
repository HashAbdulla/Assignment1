#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#include <random>


void Menu();

int check(int arr[], int size);

void modifyValue(int arr[], int size);

void addIntegerToEnd(int arr[], int& size, int valueToAdd);

void printArray(const int* arr, int size);

void replaceValueAtIndex(int arr[], int& size, int index, int value);



using namespace std;