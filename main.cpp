#include <iostream>
#include "readCSV.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<csvData> csvData;
    string filePath = "../Bella_Beats_Analysis_Master_Dataset_Cleaned.csv";

    getDataFromFile(csvData, filePath);

    return 0;
}