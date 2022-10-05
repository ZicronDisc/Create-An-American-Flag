#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void createFlag(string fileName) {
    char americanFlag[3][48]{
       {"* * * * * * ==================================\n"},
       {" * * * * *  ==================================\n"},
       {"==============================================\n"}
    };

    ofstream flagFile(fileName + ".txt");

    //UpperPotion
    int topPortion = 0;
    do {

        if (topPortion % 2 != 0) {
            for (int j = 0; j < 48; j++) {
                flagFile << americanFlag[1][j];
            }
        }
        else {
            for (int j = 0; j < 48; j++) {
                flagFile << americanFlag[0][j];
            }
        }

        topPortion++;

    } while (topPortion != 9);

    //Lower Portion
    int lowerPortion = 0;
    do {

        for (int j = 0; j < 48; j++) {
            flagFile << americanFlag[2][j];
        }

        lowerPortion++;

    } while (lowerPortion != 6);

    flagFile.close();
}

void readFile(string readFileName) {
    string values;
    ifstream readFile(readFileName + ".txt");

    while (getline(readFile, values)) {
        cout << values << endl;
    }

    readFile.close();
}

int main()
{
    string fileName;
    char optionInput;

    cout << "---Generate your American Flag---\n";
    cout << "[C] - Create the document\n";
    cout << "[E] - Exit the Program\n";
    cin >> optionInput;

    if (optionInput == 'C' || optionInput == 'c') {
        cout << "Input the name of the File: ";
        cin >> fileName;

        createFlag(fileName);
        cout << "---Your file has been generated---\n";


        cout << "[R] - Read the File\n";
        cout << "[E] - Exit the Program\n";
        cin >> optionInput;

        if (optionInput == 'R' || optionInput == 'r') {
            readFile(fileName);
            cout << "Exited...";
        }
        else if (optionInput == 'E' || optionInput == 'e') {
            cout << "Exited...";
        }
        else {
            cout << "Invalid Input...";
        };
    }
    else if (optionInput == 'E' || optionInput == 'e') {
        cout << "Exited...";
    }
    else {
        cout << "Invalid Input...";
    }

    return 0;
}
