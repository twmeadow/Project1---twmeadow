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
        int steps, minutes, heartBeatRate, calories, dataEntry;

    public:
        //only one constructor with all fields initialized, because this is the only way I am going to call it
        csvData(int dataEntry, string id, string date, int steps, int calories, int minutes, int heartBeatRate)
        {
            // initializing variables
            this->dataEntry = dataEntry;
            this->id = id;
            this->date = date;
            this->steps = steps;
            this->calories = calories;
            this->minutes = minutes;
            this->heartBeatRate = heartBeatRate;
        }

        // default constructor so Queue can return a blank object
        csvData()
        {
            this->dataEntry = 0;
            this->id = "";
            this->date = "";
            this->steps = 0;
            this->calories = 0;
            this->minutes = 0;
            this->heartBeatRate = 0;
        }

        //Getters and setters
        int getDataEntry() const {return dataEntry;}
        string getId() const {return id;}
        string getDate() const { return date; }
        int getSteps() const {return steps;}
        int getMinutes() const {return minutes;}
        int getHeartBeatRate() const {return heartBeatRate;}
        int getCalories() const {return calories;}

        void setDataEntry(int dataEntry) {this->dataEntry = dataEntry;}
        void setId(string id) {this->id = id;}
        void setDate(string date) {this->date = date;}
        void setSteps(int steps) {this->steps = steps;}
        void setCalories(int calories) {this->calories = calories;}
        void setMinutes(int minutes) {this->minutes = minutes;}
        void setHeartBeatRate(int hbr) {heartBeatRate = hbr;}

        // Overloaded << operator for printing
        friend std::ostream& operator<<(std::ostream& os, const csvData& data)
        {
            os << "Data Entry: " << data.dataEntry << ", "
                << "ID:" << data.id << ", "
               << "Date:" << data.date << ", "
               << data.steps << ", "
               << data.calories << ", "
               << data.minutes << ", "
               << data.heartBeatRate;
            return os;
        }
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
        int dataNum, steps, calories, minutes, heartBeatRate;
        char comma;
        int count = 0;

        //read and check header
        getline(fileIn, header);
        //cout << header << endl;

        //loop until file is empty
        while (fileIn.peek() != EOF)
        {
            fileIn >> dataNum;   // read "Data_Entry"
            fileIn.get(comma);     // eat the comma so id lines up properly

            //read id and date into strings for simplicity
            getline(fileIn, id, ',');
            getline(fileIn, date, ',');

            //I wanted to remove all of the 'dud' data,
            //so if there were no steps those day I made the value -1, so its easily noticeable
            fileIn >> steps;
            if (steps == 0)
            {
                steps = -1;
            }
            fileIn >> comma;

            //I repeated this process for calories aswell.
            fileIn >> calories;
            if (calories == 0) { calories = -1; }
            fileIn >> comma;

            //I did something similar for minutes and heart beat rate
            getline(fileIn, temp, ',');
            if (temp.empty() || temp == "Not-Given") {
                minutes = -1;
            } else {
                minutes = std::stoi(temp);
            }

            getline(fileIn, temp, '\r');
            if (temp.empty() || temp == "Not-Given") {
                heartBeatRate = -1;
            } else {
                heartBeatRate = std::stoi(temp);
            }

            //If any of the data is left out, it will be set to negative 1, and it wont add the data to the vector
            if (steps > 0 && calories > 0 && minutes > 0 && heartBeatRate > 0)
            {
                //create new csvData object, then push it to the vector of objects
                csvDataV.push_back(csvData(dataNum, id, date, steps, calories, minutes, heartBeatRate));
                //cout << "id:" << id << endl;
                //cout << "Date:" << date << endl;
                //cout << "steps:" << steps << endl;
                //cout << "calories:" << calories << endl;
                //cout << "minutes:" <<minutes << endl;
                //cout << "heartBeatRate:" << heartBeatRate << endl;

                //Count was just to check how many items there were
                count = count + 1;
            }
        }

        //cout << endl << "Count: " << count  << endl;
        return count;
    }
}

double getAverageFromRow(vector<csvData>& csvDataV, string rowName)
{
    //Check that rowName is a valid string, these are the only options that have numeric data so you must enter one of these
    if (rowName == "steps" || rowName == "calories" || rowName == "minutes" || rowName == "heartBeatRate")
    {
        //initializing variables
        int sum = 0;
        int count = 0;
        double avg;
        //loop over the length of the vector
        for (int i = 0; i < csvDataV.size(); i++)
        {
            //update sum depending on the row that was input via rowName
            if (rowName == "steps") { sum = sum + csvDataV[i].getSteps();}
            if (rowName == "calories") { sum = sum + csvDataV[i].getCalories();}
            if (rowName == "minutes") { sum = sum + csvDataV[i].getMinutes();}
            if (rowName == "heartBeatRate") {sum = sum + csvDataV[i].getHeartBeatRate();}

            //update count
            count = count + 1;
        }

        //preform standard average calculation
        avg = static_cast<double>(sum) / count;
        //return average
        return avg;

        //if its not a valid row that has been entered just return -1
    } else {return -1.0;}
}

#endif //PROJECT1_readCSV_H
