#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string name;
    int studentCount = 0;
    double totalClassAverage = 0.0;

    cout << fixed << setprecision(1);

    while (true) {
        cout << "Student name (or end to finish): ";
        getline(cin, name);

        if (name == "end") {
            break;
        }

        double scoreSum = 0.0;

        for (int i = 1; i <= 5; i++) {
            double score;

            // Inner validation loop: handles non-numeric input (Bonus) and out-of-range values
            while (true) {
                cout << "Score " << i << ": ";
                cin >> score;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100.\n";
                } else if (score < 0.0 || score > 100.0) {
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100.\n";
                } else {
                    cin.ignore(1000, '\n'); // Clear leftover newline before next input
                    break;
                }
            }

            scoreSum += score;
        }

        double average = scoreSum / 5.0;
        char grade;

        // Grading scale matching the example run (89.4 -> B, 67.0 -> C)
        // Adjust thresholds below if your Part 2 scale uses different cutoffs
        if (average >= 90.0) {
            grade = 'A';
        } else if (average >= 75.0) {
            grade = 'B';
        } else if (average >= 60.0) {
            grade = 'C';
        } else if (average >= 50.0) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        cout << name << ": average " << average << ", grade " << grade << "\n";

        studentCount++;
        totalClassAverage += average;
    }

    if (studentCount == 0) {
        cout << "No students entered\n";
    } else {
        double classAverage = totalClassAverage / studentCount;
        cout << "Students entered: " << studentCount << "\n";
        cout << "Class average: " << classAverage << "\n";
    }

    return 0;
}
