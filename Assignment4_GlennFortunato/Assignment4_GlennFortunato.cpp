// Assignment4_GlennFortunato.cpp
// COP3014 001
// 10/30/2023   

#include <iostream>
#include <iomanip>

using namespace std;

// 3 assignments    100 points each	    25%
// Midterm		    100 points			30%
// Final		    100 points			45%
class COP3014 {

private:
	string studentFirstName;
	string studentLastName;
	int studentZNumber;
    const int numOfGrades = 5;
	int grades[5];
	double totalGrade;
	char finalGrade;

public:
    // Default Constructor
    COP3014() {
        studentFirstName = "";
        studentLastName = "";
        studentZNumber = 0;
        for (int i = 0; i < numOfGrades; i++) {
            grades[i] = 0;
        }
        totalGrade = 100;
    }

    // Setters
    void setFirstName() {
        cout << "Enter Student First Name: ";
        cin >> studentFirstName;
    }

    void setLastName() {
        cout << "Enter Student Last Name: ";
        cin >> studentLastName;
    }

    void setZNumber() {
        do {
            cout << "Enter Student zNumber (8 digits only):  ";
            cin >> studentZNumber;

            if (studentZNumber < 10000000 || studentZNumber > 99999999 || cin.fail()) {
                cout << "Please only enter an 8 digit number";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (studentZNumber < 10000000 || studentZNumber > 99999999);
    }

    void setGrades() {
        for (int i = 0; i < numOfGrades; i++) {
            if (i < numOfGrades-2) {
                cout << "Enter Grade for Assingnment " << i + 1 << ": ";
                cin >> grades[i];

            }
            if (i == numOfGrades-2) {
                cout << "Enter Grade for Midterm: ";
                cin >> grades[i];

            }
            if (i == numOfGrades-1) {
                cout << "Enter Grade for Final: ";
                cin >> grades[i];
            }
            if (cin.fail() || grades[i] < 0 || grades[i] > 100) {
                cout << "Input is Invalid.  Please try again using only positve integers, up to a score of 100. \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
            }
        }
        examChecker();
    }

    // Getters
    string getFirstName() const {
        return studentFirstName;
    }

    string getLastName() const {
        return studentLastName;
    }

    int getZNumber() const {
        return studentZNumber;
    }

    int getNumOfGrades() {
        return numOfGrades;
    }

    int* getGrades() {
        return grades;
    }

    double getTotalGrade() {
        return totalGrade;
    }

    char getFinalGrade() {
        return finalGrade;
    }

    // Input Function
    void inputStudentInfo(int numOfGrades) {
        setFirstName();
        setLastName();
        setZNumber();
        setGrades();
    }

    double totalGradeCalc() {
        totalGrade = ((grades[0] + grades[1] + grades[2]) / 3.0) * 0.25 + grades[3] * 0.3 + grades[4] * 0.45;
        return totalGrade;
    }

    void examChecker() {

        if (grades[numOfGrades - 2] == 0 or grades[numOfGrades - 1] == 0) {
            finalGrade = 'F';
        }
    }

    char finalGradeCalc() {
        
        if (totalGrade >= 90) {
            finalGrade = 'A';
        }
        else if (totalGrade >= 80 && totalGrade < 90) {
            finalGrade = 'B';
        }
        else if (totalGrade >= 70 && totalGrade < 80) {
            finalGrade = 'C';
        }
        else if (totalGrade >= 60 && totalGrade < 70) {
            finalGrade = 'D';
        }
        else if (totalGrade < 60) {
            finalGrade = 'F';
        }
        
        if (grades[3] == 0 or grades[4] == 0) {
            finalGrade = 'F';
        }
        return finalGrade;
    }

    void outputStudentInfo() {
        cout << "Student name: " << studentLastName << ", " << studentFirstName << endl;
        cout << "Student zNumber: Z" << studentZNumber << endl; 
        for (int i = 0; i < 3; i++) {
            cout << "Assignment " << i+1 << ": " << grades[i] << endl;
        }
        cout << "Midterm: " << grades[3] << endl;
        cout << "Final: " << grades[4] << endl;
        cout << "Total Grade: " << fixed << setprecision(2) << totalGradeCalc() << endl;
        cout << "Final Grade: " << finalGradeCalc() << endl;
    }
};

// Fall Semester
// 4 assignments    100 points each	    25%
// Midterm		    100 points			30%
// Final		    100 points			45%
class Fall23 : public COP3014 {
private:
    const int numOfGrades = 6;
    int grades[6];
    char finalGrade;

public:
    Fall23() {
        for (int i = 0; i < numOfGrades; i++) {
            grades[i] = 0;
        }
        finalGrade = ' ';
    }

    void inputStudentInfo() {
        setFirstName();
        setLastName();
        setZNumber();
        setGrades();
    }

    void setGrades() {
        for (int i = 0; i < numOfGrades; i++) {
            if (i < numOfGrades - 2) {
                cout << "Enter Grade for Assingnment " << i + 1 << ": ";
                cin >> grades[i];

            }
            if (i == numOfGrades - 2) {
                cout << "Enter Grade for Midterm: ";
                cin >> grades[i];

            }
            if (i == numOfGrades - 1) {
                cout << "Enter Grade for Final: ";
                cin >> grades[i];
            }
            if (cin.fail() || grades[i] < 0 || grades[i] > 100) {
                cout << "Input is Invalid.  Please retry again using only positve integers, up to a score of 100. \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
            }
        }
    }

    double totalGradeCalc() {
        double total = ((grades[0] + grades[1] + grades[2] + grades[3]) / 4.0) * 0.25 + grades[4] * 0.3 + grades[5] * 0.45;
        return total;
    }

    char finalGradeCalc(double total) {
        if (total >= 90) {
            finalGrade = 'A';
        }
        else if (total >= 80 && total < 90) {
            finalGrade = 'B';
        }
        else if (total >= 70 && total < 80) {
            finalGrade = 'C';
        }
        else if (total >= 60 && total < 70) {
            finalGrade = 'D';
        }
        else if (total < 60) {
            finalGrade = 'F';
        }
        return finalGrade;

    }

    void examChecker() {

        if (grades[numOfGrades - 2] == 0 or grades[numOfGrades - 1] == 0) {
            finalGrade = 'F';
        }
    }

    void outputStudentInfo() {
        examChecker();
        cout << "\nStudent name: " << getFirstName() << " " << getLastName() << " - " << getZNumber() << endl;
        for (int i = 0; i < numOfGrades-2; i++) {
            cout << "           Assignment " << i+1 << ": " << grades[i] << endl;
        }
        cout << "           Midterm: " << grades[numOfGrades-2] << endl;
        cout << "           Final: " << grades[numOfGrades-1] << endl;
        cout << "           Total Grade: " << fixed << setprecision(2) << totalGradeCalc() << endl;
        cout << "           Final Grade: " << finalGradeCalc(totalGradeCalc()) << endl;
    }
    
};


// Summer Semester
// 3 assignments    100 points each	    25%
// Midterm		    100 points			30%
// Final		    100 points			45%
// Bonus            3   points          3%
class Summer23 : public COP3014 {
private:
    int bonus;

public:
    Summer23() {
        bonus = 0;
    }
    void inputStudentInfo() {
        setFirstName();
        setLastName();
        setZNumber();
        setGrades();
        setBonus();
    }

    void setBonus() {
        bool valid = false;
        while (!valid) {
            cout << "Bonus percent (0-3): ";
            cin >> bonus;
            if (cin.fail() || bonus > 3 || bonus < 0) {
                cout << "Input is Invalid.  Please try again using only positive integers within the listed range. \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = true;
            }
        }
    }

    void outputStudentInfo() {

        int numOfGrades = getNumOfGrades();
        int* grades = getGrades();

        cout << "\nStudent name: " << getFirstName() << " " << getLastName() << " - " << getZNumber() << endl;
        for (int i = 0; i < getNumOfGrades() - 2; i++) {
            cout << "               Assignment " << i + 1 << ": " << grades[i] << endl;
        }
        cout << "               Midterm: " << grades[numOfGrades - 2] << endl;
        cout << "               Final: " << grades[numOfGrades - 1] << endl;
        cout << "               Bonus Percent: " << bonus << endl;
        cout << "               Total Grade: " << fixed << setprecision(2) << totalGradeCalc() + bonus << endl;
        cout << "               Final Grade: " << finalGradeCalc() << endl;
    }
};

int menu() {
    cout << "\n-------------------------------------------------";
    cout << "\n       COP3014 Student Grade Calculator" << endl;
    cout << "\n                Select Semester";
    cout << "\n-------------------------------------------------\n1. Fall 2023 \n2. Summer 2023\n3. Exit Program" << endl;

    int selection;
    bool valid = false;
    do {
        cin >> selection;
        if (cin.fail() || selection != 1 && selection != 2 && selection != 3) {
            cout << "Input is Invalid.  Select one of the numbered options. \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        else {
            valid = true;
        }

        if (selection == 3) {
            exit(0);
            }
        
    } while (!valid);
    
    return selection;
}

int main() {
    bool usingCalculator = true;
    while (usingCalculator) {
        int semester = menu();
        COP3014 Course;
        Fall23 fallCourse;
        Summer23 summerCourse;

        // Fall Course Selection
        if (semester == 1) {
            cout << "\n- COP3014 Fall Semester - \n";
            fallCourse.inputStudentInfo();
            fallCourse.outputStudentInfo();
        }

        // Summer Course Selection
        if (semester == 2) {
            cout << "\n- COP3014 Summer Semester - \n";
            summerCourse.inputStudentInfo();
            summerCourse.outputStudentInfo();
        }

        /*  Base class (Without extra assignments or bonus).
        *   Unused in final version.
        *
        *    Course.inputStudentInfo(Course.getNumOfGrades());
        *    Course.outputStudentInfo();
        */
    }

}