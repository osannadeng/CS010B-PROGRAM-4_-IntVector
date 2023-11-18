#include <iostream>
using namespace std;

#include "IntVector.h"

//string tof(IntVector);

int main() {
    IntVector vectOne;
    IntVector vectTwo(5);
    IntVector vectThree(3, 2);

    for (unsigned i = 0; i < vectTwo.size(); ++i) {
        cout << vectTwo.at(i) << " ";
    }
    cout << endl;

    for (unsigned i = 0; i < vectThree.size(); ++i) {
        cout << vectThree.at(i) << " ";
    }
    cout << endl << endl;
    
    cout << "Vector sizes:" << endl;
    cout << "vectOne: " << vectOne.size() << endl;
    cout << "vectTwo: " << vectTwo.size() << endl;
    cout << "vectThree: " << vectThree.size() << endl << endl;

    cout << "Vector capacities:" << endl;
    cout << "vectOne: " << vectOne.capacity() << endl;
    cout << "vectTwo: " << vectTwo.capacity() << endl;
    cout << "vectThree: " << vectThree.capacity() << endl << endl;

    cout << "Empty or not:" << endl;
    cout << "vectOne: " << vectOne.empty() << endl;
    cout << "vectTwo: " << vectTwo.empty() << endl;
    cout << "vectThree: " << vectThree.empty() << endl << endl;

    //cout << "Testing out of range:" << endl;
    //cout << "vectOne: " << vectOne.at(0) << endl;
    //cout << "vectTwo: " << vectTwo.at(6) << endl;
    //cout << "vectThree: " << vectThree.at(3) << endl << endl;

    cout << "A value in vector:" << endl;
    cout << "vectTwo: " << vectTwo.at(0) << endl;
    cout << "vectThree: " << vectThree.at(0) << endl << endl;
    

    cout << "First value in vector:" << endl;
    cout << "vectTwo: " << vectTwo.front() << endl;
    cout << "vectThree: " << vectThree.front() << endl << endl;

    cout << "Last value in vector:" << endl;
    cout << "vectTwo: " << vectTwo.back() << endl;
    cout << "vectThree: " << vectThree.back() << endl << endl;

    cout << "Inserting numbers:" << endl;
    //vectOne.insert(1, 1);
    vectOne.insert(0, 2);
    cout << "vectOne: " << vectOne.at(0) << endl;
    vectTwo.insert(3, 6);
    cout << "vectTwo: " << vectTwo.at(3) << endl;
    vectThree.insert(1, 9);
    cout << "vectThree: " << vectThree.at(1) << endl << endl;
    
    for (unsigned i = 0; i < vectTwo.size(); ++i) {
        cout << vectTwo.at(i) << " ";
    }
    cout << endl;

    for (unsigned i = 0; i < vectThree.size(); ++i) {
        cout << vectThree.at(i) << " ";
    }
    cout << endl << endl;

    cout << "Erasing numbers:" << endl;
    cout << "vectOne size: (before) " << vectOne.size();
    vectOne.erase(0);
    cout << " (after) " << vectOne.size() << endl;
    cout << "vectTwo size: (before) " << vectTwo.size();
    vectTwo.erase(4);
    cout << " (after) " << vectTwo.size() << endl;
    cout << "vectThree size: (before) " << vectThree.size();
    vectThree.erase(vectThree.size() - 1);
    cout << " (after) " << vectThree.size() << endl << endl;

    cout << "Inserting numbers at end:" << endl;
    vectOne.push_back(6);
    cout << "vectOne: " << vectOne.at(vectOne.size() - 1) << endl;
    vectTwo.push_back(45);
    cout << "vectTwo: " << vectTwo.at(vectTwo.size() - 1) << endl;
    vectThree.push_back(7);
    cout << "vectThree: " << vectThree.at(vectThree.size() - 1) << endl << endl;
    
    for (unsigned i = 0; i < vectOne.size(); ++i) {
        cout << vectOne.at(i) << " ";
    }
    cout << endl << endl;
    
    vectOne.resize(25, -585);

    for (unsigned i = 0; i < vectOne.size(); ++i) {
        cout << vectOne.at(i) << " ";
    }
    cout << endl << endl;

    cout << vectOne.at(10) << endl << endl;

    //destructing
    vectOne.~IntVector();
    vectTwo.~IntVector();
    vectThree.~IntVector();

    return 0;
}

/*
string tof(IntVector vect) {
    if (vect.empty() == 1) {
        return "true";
    } else {
        return "false";
    }
}
*/