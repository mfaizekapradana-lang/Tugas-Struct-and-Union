#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int numStudents = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Fungsi untuk membaca data
void getData(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nama Depan, Nama Belakang, dan Nilai ke-" << i + 1 << ": ";
        cin >> s[i].studentFName >> s[i].studentLName >> s[i].testScore;
    }
}

// Fungsi untuk menentukan grade
void assignGrade(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i].testScore >= 90) s[i].grade = 'A';
        else if (s[i].testScore >= 80) s[i].grade = 'B';
        else if (s[i].testScore >= 70) s[i].grade = 'C';
        else if (s[i].testScore >= 60) s[i].grade = 'D';
        else s[i].grade = 'F';
    }
}

// Fungsi untuk mencari nilai tertinggi
int highestScore(studentType s[], int n) {
    int highest = s[0].testScore;
    for (int i = 1; i < n; i++) {
        if (s[i].testScore > highest)
            highest = s[i].testScore;
    }
    return highest;
}

// Fungsi untuk menampilkan siswa dengan skor tertinggi
void printHighest(const studentType s[], int n, int highest) {
    cout << "\nSiswa dengan skor tertinggi (" << highest << "):\n";
    for (int i = 0; i < n; i++) {
        if (s[i].testScore == highest)
            cout << s[i].studentLName << ", " << s[i].studentFName << endl;
    }
}

// Fungsi untuk menampilkan semua data siswa
void printAll(const studentType s[], int n) {
    cout << left << setw(15) << "Last Name" << setw(15) << "First Name" << setw(10)
         << "Score" << setw(10) << "Grade" << endl;
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << s[i].studentLName
             << setw(15) << s[i].studentFName
             << setw(10) << s[i].testScore
             << setw(10) << s[i].grade << endl;
    }
}

int main() {
    studentType students[numStudents];
    getData(students, numStudents);
    assignGrade(students, numStudents);
    printAll(students, numStudents);
    int highest = highestScore(students, numStudents);
    printHighest(students, numStudents, highest);
    return 0;
}

