#include <iostream>
#include "readCSV.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<csvData> csvData;
    string filePath = "../Bella_Beats_Analysis_Master_Dataset_Cleaned.csv";

    int size = getDataFromFile(csvData, filePath);

    double avg = getAverageFromRow(csvData, "minutes");
    double avg2 = getAverageFromRow(csvData, "heartBeatRate");
    double avg3 = getAverageFromRow(csvData, "calories");
    double avg4 = getAverageFromRow(csvData, "steps");

    cout << "Total rows in CSV:" << size << endl;
    cout << "Average of Minutes: " << avg << endl;
    cout << "Average of HeartBeats: " << avg2 << endl;
    cout << "Average of Calories: " << avg3 << endl;
    cout << "Average of Steps: " << avg4 << endl;


    return 0;
}