# Project 1 Report

For my dataset I chose a set of FitBit user activity data of users on a daily basis. 
* **What each of the 5+ attributes of your dataset represent.**

There are 6 columns in the dataset that I chose. 
1) ID - this is a unique user ID used to hide the real owners identity
2) Date - The date the activity data is from 
3) Total Steps - How many steps the user had that given day
4) Calories - How many calories the user burned on a given day 
5) Total Minutes Asleep - How many minutes the user slept for on a given night
6) Heart Beat Rate - Not exactly sure what this measures, possibly average heart beat? Its something to do with the users heartbeat data on  a given day 
* **Where you got the data from.**

I got this data set from Kaggle. Found at this link: https://www.kaggle.com/datasets/joyalsusilan/bellabeat-smart-device-wellness-dataset?resource=download
* **Why you chose that dataset.**

I own an apple watch and I like to look at my own health metrics. I was curious to see how the others stacked up. Also, this is a very big robust data set that I thought would be easy to work with 
* How the rows are ordered by default (i.e. is the data sorted by a particular column?).

I think it is sorted by the User ID, but since this is just a large series of numbers its not particularly meaningful to sort by this. 
* How you know your functions work correctly.

There are over 15,000 rows even after removing the extra rows that did not contain all the data. However the data operation function I used was average which returned these values:
* Total rows in CSV:14980 

* Average of Minutes: 420.259
* Average of HeartBeats: 93.7677
* Average of Calories: 2590.01
* Average of Steps: 9104.39

This makes reasonable sense to me based off of my own health data. Before cleaning the set had 28,000 rows, so it seems very reasonable to have 15,000 after cleaning. Also the averages all make reasonable sense for an average of each of individual data.

* **Why you chose that calculation for your dataset**.

I chose this calculation because I wanted to see how my own data compared to the average of this massive data set. It actually lines up pretty relatably which I find very cool. 


