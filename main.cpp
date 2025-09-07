#include <iostream>
#include "readCSV.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<csvData> csvData;
    string filePath = "../Bella_Beats_Analysis_Master_Dataset_Cleaned.csv";

    getDataFromFile(csvData, filePath);

    double avg = getAverageFromRow(csvData, "minutes");
    double avg2 = getAverageFromRow(csvData, "heartBeatRate");
    double avg3 = getAverageFromRow(csvData, "calories");
    double avg4 = getAverageFromRow(csvData, "steps");


    cout << avg4 << endl;

    return 0;
}