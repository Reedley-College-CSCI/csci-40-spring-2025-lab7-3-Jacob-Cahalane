#include <iostream>
#include <fstream>
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
void printTemperatures(const TemperatureRecord monthTemp[], int size);
TemperatureRecord findMin(const ???);
TemperatureRecord findMax(const ???);
double findAverage(const ???);

int main() {

    ofstream dataOut;

    
    dataOut.open("outputfile.txt");

    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord monthTemp[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(monthTemp, size);

    // TODO: Step 4 - Print the temperatures
    cout << "Day Temp" << endl;
    printTemperatures(monthTemp, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature


    dataOut.close();  

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord monthTemp[], int &size)
{
    ifstream dataIn;
    dataIn.open("temps.txt");

    TemperatureRecord monthTemp[MAX_DAYS];

    while (size < MAX_DAYS && dataIn >> monthTemp[MAX_DAYS].day >> monthTemp[MAX_DAYS].temperature)
    {
        size++;
    }

    dataIn.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord monthTemp[], int size)
{
    for (int position = 0; position < size; position++)
    {
        cout << monthTemp[position].day << " " << monthTemp[position].temperature << endl;
    }
} 


// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature



// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature



// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
