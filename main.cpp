// Čudars Jēkabs 231RDB342
#include <cmath>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

std::vector<std::vector<int>>* readCSV(std::vector<std::vector<int>>* array, std::string fileName) {
    // In case there is some garbage value in array
    array->clear();
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return array;
    }


    std::string line;
    int x1, x2, x3;

    std::getline(file, line); // skips the first line
    int i =0;
    //ChatGPT provided this efficient method
    while (std::getline(file, line)) {
        std::istringstream ss(line); // turns line into string stream so its easier to read.
        char comma;  // To discard the commas during parsing

        if (ss >> x1 >> comma >> x2 >> comma >> x3) {
            // used push back method to easily append new element array to the existing array
            array->push_back({x1, x2, x3});
        }

        i++;
    }

    file.close();
    return array;
}


int minValue(std::vector<std::vector<int>>* array) {
    // accessing array using at() notation to conveniently access the array
    //https://www.geeksforgeeks.org/arrayat-c-stl/
    int minVal=array->at(0).at(0);
    for (int i = 0; i < array->size(); i++) {
        if (array->at(i).at(0) < minVal) {
            minVal = array->at(i).at(0);
        }
    }
    return minVal;
}


double meanValue(std::vector<std::vector<int>>* array, int collumn) {
    if (array->empty()) return 0.0; // Safe check for an empty array
    double sum=0;

    // looping through to calculate the sum
    for (int i = 0; i < array->size(); i++) {
        sum += array->at(i).at(collumn);
    }
    return sum/array->size();
}

double standardDeviationValue(std::vector<std::vector<int>>* array, int collumn) {
    if (array->empty()) return 0.0; // Safe check for an empty array
    double mean =meanValue(array, collumn);
    int sdsum =0;

    for (int i = 0; i < array->size(); i++) {
        sdsum += pow((array->at(i).at(collumn)-mean), 2);
    }
    return sqrt(sdsum/array->size());
}

int main(){
    std::string fileName="C:\\Users\\jekab\\CLionProjects\\RapHomework\\2d.csv";
    std::vector<std::vector<int>>* array = new std::vector<std::vector<int>>();
    array=readCSV(array, fileName);
    int minVal = minValue(array);
    double mean = meanValue(array, 1);
    double standardDeviation = standardDeviationValue(array, 2);
    std::cout << "minValue: " << minVal << std::endl;
    std::cout << "meanValue: " << mean << std::endl;
    std::cout << "standardDeviationValue: " << standardDeviation << std::endl;

    array->clear();
    return 0;
}