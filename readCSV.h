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
        int steps, minutes, heartBeatRate;

    public:

        //only one constructor with all fields initialized, because this is the only way I am going to call it
        csvData(string id, string date, int steps, int minutes, int heartBeatRate)
        {
            this->id = id;
            this->date = date;
            this->steps = steps;
            this->minutes = minutes;
            this->heartBeatRate = heartBeatRate;
        }

        //Getters and setters

        string getId() const {return id;}

        string getDate() const { return date; }

        int getSteps() const {return steps;}

        int getMinutes() const {return minutes;}

        int getHeartBeatRate() const {return heartBeatRate;}


        void setId(string id) {this->id = id;}

        void setDate(string date) {this->date = date;}

        void setSteps(int steps) {this->steps = steps;}

        void setMinutes(int minutes) {this->minutes = minutes;}

        void setHeartBeatRate(int hbr) {heartBeatRate = hbr;}




};


bool getDataFromFile(vector<csvData> &csvData, const string &fileName)
{
    //open file
    ifstream fileIn;
    fileIn.open(fileName);

    if (fileIn)
    {
        //define variables for file
        string id, date, header, endstr;
        int steps, minutes, heartBeatRate;
        char comma;

        //read and check header
        getline(fileIn, header);
        cout << header << endl;

        while (fileIn.peek() != EOF)
        {
            getline(fileIn, id, ',');
            getline(fileIn, date, ',');

            if (fileIn.peek() != 0)
            {
                fileIn >> steps;
            } else { steps = -1;}
            fileIn >> comma;

            if (fileIn.peek() != "Not-Given")
            {
                fileIn >> minutes;
            }else{ minutes = -1;}
            fileIn >> comma;
        }


    }

}




#endif //PROJECT1_readCSV_H