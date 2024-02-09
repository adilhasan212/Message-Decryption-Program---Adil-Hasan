#include <iostream>
#include <fstream>

using namespace std;

char decryptChar(int[][10], int row, int column);

int main()
{
    string fileName;
    cout << "Please enter the key filename: ";
    cin >> fileName;
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error opening file \"" << fileName << "\"" << endl;
        return 1;
    }
    int key[10][10];
    int row = 0;
    int column = 0;
    // Every number placed in the two dimensional array
    while (row < 10 && inFile >> key[row][column]) {
        column++;
        if (column == 10) {
            // Reset for next row
            column = 0;
            row++;
        }
    }
    cout << "Please enter the coded message: ";
    // How many characters allowed
    int columnNum[100];
    int rowNum[100];
    char character;
    int counter = 0;
    // Inputting every character in the next element of the columnNum and rowNum array
    while (cin >> columnNum[counter] >> rowNum[counter]) {
        character = decryptChar(key, columnNum[counter], rowNum[counter]);
        // Stop condition if array element = 0
        if (key[rowNum[counter]][columnNum[counter]] == 0) {
            cout << character;
            break;
        }
        else {
            cout << character;
            // Go to the next element
            counter++;
        }
    }
    cout << endl;
    return 0;
}

char decryptChar(int key[][10], int row, int column) {
    // Return the char of the number in that row and column
    return static_cast<char>(key[row][column]);
}
