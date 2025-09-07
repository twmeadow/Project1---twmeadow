//
// Created by Tyler Meadows on 9/6/25.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef PROJECT1_readCSV_H
#define PROJECT1_readCSV_H

using std::cout, std::endl, std::vector, std::string, std::ifstream;

class csvData
{
    //Variable declaration
    private:
        string date, id;
        int steps, minutes, heartBeatRate, calories;

    public:

        //only one constructor with all fields initialized, because this is the only way I am going to call it
        csvData(string id, string date, int steps, int calories, int minutes, int heartBeatRate)
        {
            this->id = id;
            this->date = date;
            this->steps = steps;
            this->calories = calories;
            this->minutes = minutes;
            this->heartBeatRate = heartBeatRate;
        }

        //Getters and setters

        string getId() const {return id;}

        string getDate() const { return date; }

        int getSteps() const {return steps;}

        int getMinutes() const {return minutes;}

        int getHeartBeatRate() const {return heartBeatRate;}

        int getCalories() const {return calories;}


        void setId(string id) {this->id = id;}

        void setDate(string date) {this->date = date;}

        void setSteps(int steps) {this->steps = steps;}

        void setCalories(int calories) {this->calories = calories;}

        void setMinutes(int minutes) {this->minutes = minutes;}

        void setHeartBeatRate(int hbr) {heartBeatRate = hbr;}




};


int getDataFromFile(vector<csvData>& csvDataV, const string &fileName)
{
    //open file
    ifstream fileIn;
    fileIn.open(fileName);

    if (fileIn)
    {
        //define variables for file
        string id, date, header, endstr, temp;
        int steps, calories, minutes, heartBeatRate;
        char comma;
        int count = 0;

        //read and check header
        getline(fileIn, header);
        //cout << header << endl;

        while (fileIn.peek() != EOF)
        {
            getline(fileIn, id, ',');
            getline(fileIn, date, ',');

            fileIn >> steps;
            if (steps == 0)
            {
                steps = -1;
            }
            fileIn >> comma;

            fileIn >> calories;
            if (calories == 0) { calories = -1; }
            fileIn >> comma;

            getline(fileIn, temp, ',');
            if (temp != "Not-Given")
            {
                minutes = std::stoi(temp);
            }else{ minutes = -1;}

            getline(fileIn, temp);
            if (temp != "Not-Given")
            {
                heartBeatRate = std::stoi(temp);
            }else{ heartBeatRate = -1;}

            if (steps > 0 && calories > 0 && minutes > 0 && heartBeatRate > 0)
            {
                csvDataV.push_back(csvData(id, date, steps, calories, minutes, heartBeatRate));
                //cout << "id:" << id << endl;
                //cout << "Date:" << date << endl;
                //cout << "steps:" << steps << endl;
                //cout << "calories:" << calories << endl;
                //cout << "minutes:" <<minutes << endl;
                //cout << "heartBeatRate:" << heartBeatRate << endl;

                count = count + 1;
            }


        }
    cout << endl << "Count: " << count  << endl;
    return count;
    }

}

double getAverageFromRow(vector<csvData>& csvDataV, string rowName)
{
    if (rowName == "steps" || rowName == "calories" || rowName == "minutes" || rowName == "heartBeatRate")
    {

        int sum = 0;
        int count = 0;
        double avg;
        for (int i = 0; i < csvDataV.size(); i++)
        {
            if (rowName == "steps") { sum = sum + csvDataV[i].getSteps();}
            if (rowName == "calories") { sum = sum + csvDataV[i].getCalories();}
            if (rowName == "minutes") { sum = sum + csvDataV[i].getMinutes();}
            if (rowName == "heartBeatRate") {sum = sum + csvDataV[i].getHeartBeatRate();}

            count = count + 1;
        }

        avg = static_cast<double>(sum) / count;
        return avg;

    } else {return -1.0;}

}


#endif //PROJECT1_readCSV_H