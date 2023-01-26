/*
*   Filename: main.cpp
*   Created on: Jan. 26, 2023
*   Authors: Veenkamp, James, Brooks
*/

#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

int main()
{
  rapidcsv::Document doc("");
  vector<string> col = doc.GetColumn<string>("ISBN");
  cout << "Read " << col.size() << " values." << endl;
}
