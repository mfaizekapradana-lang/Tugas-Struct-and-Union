struct nameType {
    string first;
    string last;
};

struct courseType {
    string callNum;
    int credits;
    char grade;
};

struct studentType {
    nameType name;
    double gpa;
    courseType course;
};

studentType student;
studentType classList[100];
courseType course;
nameType name;
