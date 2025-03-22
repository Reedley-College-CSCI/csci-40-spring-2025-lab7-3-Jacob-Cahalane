#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Jacob

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord
{
    int day;
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord monthTemp[], int& size); // TODO: Fix the parameters
void printTemperatures(ofstream& dataOut, const TemperatureRecord monthTemp[], int size);
TemperatureRecord findMin(const TemperatureRecord monthTemp[], int size);
TemperatureRecord findMax(const TemperatureRecord monthTemp[], int size); 
double findAverage(const TemperatureRecord monthTemp[], int size);

int main() {

    ofstream dataOut;
    dataOut.open("outputfile.txt");

    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord monthTemp[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(monthTemp, size);

    // TODO: Step 4 - Print the temperatures
    dataOut << "Day Temp" << endl;
    printTemperatures(dataOut, monthTemp, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    TemperatureRecord minTemp = findMin(monthTemp, size);
    TemperatureRecord maxTemp = findMax(monthTemp, size);
    double avgTemp = findAverage(monthTemp, size);

    dataOut << "on day " << minTemp.day << " Minimum Temperature: " << minTemp.temperature << endl;
    dataOut << "on day " << maxTemp.day << " Maximum Temperature: " << maxTemp.temperature << endl;
    dataOut << "Average Temperature: " << fixed << showpoint << setprecision(2) << avgTemp << endl;

    dataOut.close();  

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord monthTemp[], int &size)
{
    ifstream dataIn;
    dataIn.open("temps.txt");

    while (size < MAX_DAYS && dataIn >> monthTemp[size].day >> monthTemp[size].temperature)
    {
        size++;
    }

    dataIn.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(ofstream& dataOut, const TemperatureRecord monthTemp[], int size)
{
    for (int position = 0; position < size; position++)
    {
        dataOut << monthTemp[position].day << " " << monthTemp[position].temperature << endl;
    }
} 


// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord monthTemp[], int size)
{
    TemperatureRecord minTemp = monthTemp[0];
    for (int position = 1; position < size; position++)
    {
        if (monthTemp[position].temperature < minTemp.temperature)
        {
            minTemp = monthTemp[position];
        }
    }
    return minTemp;
}


// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord monthTemp[], int size)
{
    TemperatureRecord maxTemp = monthTemp[0];
    for (int position = 1; position < size; position++)
    {
        if (monthTemp[position].temperature > maxTemp.temperature)
        {
            maxTemp = monthTemp[position];
        }
    }
    return maxTemp;
}


// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord monthTemp[], int size)
{
    double sum = 0;
    for (int position = 0; position < size; position++)
    {
        sum += monthTemp[position].temperature;
    }
    return sum / size;
}