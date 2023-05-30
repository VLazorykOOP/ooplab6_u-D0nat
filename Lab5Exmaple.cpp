#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Person {
protected:
    string name;
    int age;
    float weight;

public:
    Person(string name = "", int age = 0, float weight = 0.0) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }

    virtual ~Person() {}

    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }

    void setAge(int age) {
        this->age = age;
    }
};

class Student : public Person {
private:
    int grade;

public:
    Student(string name = "", int age = 0, float weight = 0.0, int grade = 0) : Person(name, age, weight) {
        this->grade = grade;
    }

    ~Student() {}

    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Grade: " << grade << endl;
    }

    void setAge(int age) {
        this->age = age;
        this->grade += 1;
    }

    void setGrade(int grade) {
        this->grade = grade;
    }
};

//////////////////////////////////////////

class Window {
protected:
    int width;
    int height;

public:
    Window(int width = 0, int height = 0) {
        this->width = width;
        this->height = height;
    }

    virtual ~Window() {}

    virtual void show() {
        cout << "Window" << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

class TitledWindow : public Window {
protected:
    string title;

public:
    TitledWindow(int width = 0, int height = 0, string title = "") : Window(width, height) {
        this->title = title;
    }

    ~TitledWindow() {}

    void show() {
        cout << "Titled Window" << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Title: " << title << endl;
    }
};

class ButtonWindow : public TitledWindow {
private:
    string buttonText;

public:
    ButtonWindow(int width = 0, int height = 0, string title = "", string buttonText = "") : TitledWindow(width, height, title) {
        this->buttonText = buttonText;
    }

    ~ButtonWindow() {}

    void show() {
        cout << "Button Window" << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Title: " << title << endl;
        cout << "Button Text: " << buttonText << endl;
    }
};


/////////////////////

class Student2 {
protected:
    string name;
    int age;
    string university;

public:
    Student2(string name = "", int age = 0, string university = "") {
        this->name = name;
        this->age = age;
        this->university = university;
    }

    virtual ~Student2() {}

    virtual void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university << endl;
    }

    friend istream& operator>>(istream& in, Student2& s) {
        cout << "Enter name: ";
        in >> s.name;
        cout << "Enter age: ";
        in >> s.age;
        cout << "Enter university: ";
        in >> s.university;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student2& s) {
        out << "Name: " << s.name << endl;
        out << "Age: " << s.age << endl;
        out << "University: " << s.university << endl;
        return out;
    }

    Student2(const Student2& s) {
        name = s.name;
        age = s.age;
        university = s.university;
    }

    Student2& operator=(const Student2& s) {
        if (this != &s) {
            name = s.name;
            age = s.age;
            university = s.university;
        }
        return *this;
    }
};

class GraduateStudent : public Student2 {
private:
    string thesisTitle;

public:
    GraduateStudent(string name = "", int age = 0, string university = "", string thesisTitle = "") : Student2(name, age, university) {
        this->thesisTitle = thesisTitle;
    }

    ~GraduateStudent() {}

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university << endl;
        cout << "Thesis Title: " << thesisTitle << endl;
    }

    friend istream& operator>>(istream& in, GraduateStudent& gs) {
        cout << "Enter name: ";
        in >> gs.name;
        cout << "Enter age: ";
        in >> gs.age;
        cout << "Enter university: ";
        in >> gs.university;
        cout << "Enter thesis title: ";
        in >> gs.thesisTitle;
        return in;
    }

    friend ostream& operator<<(ostream& out, const GraduateStudent& gs) {
        out << "Name: " << gs.name << endl;
        out << "Age: " << gs.age << endl;
        out << "University: " << gs.university << endl;
        out << "Thesis Title: " << gs.thesisTitle << endl;
        return out;
    }

    GraduateStudent(const GraduateStudent& gs) : Student2(gs) {
        thesisTitle = gs.thesisTitle;
    }

    GraduateStudent& operator=(const GraduateStudent& gs) {
        if (this != &gs) {
            Student2::operator=(gs);
            thesisTitle = gs.thesisTitle;
        }
        return *this;
    }
};



int main() {
    cout << "Task 1" << endl;
    Person person("Ivan Ivanov", 25, 70.5);
    person.print();
    cout << endl;

    Student student("Petro Petrov", 16, 60.0, 10);
    student.print();
    cout << endl;

    cout << "change age and grade" << endl;
    student.setAge(17);
    student.print();
    cout << endl;

    student.setGrade(11);
    student.print();
    cout << endl;
   
    cout << "Task 2\n" << endl;

    Window window(500, 300);
    window.show();
    cout << endl;

    TitledWindow titledWindow(500, 300, "My Titled Window");
    titledWindow.show();
    cout << endl;

    ButtonWindow buttonWindow(500, 300, "My Button Window", "Click Me");
    buttonWindow.show();
    cout << endl;


    cout << "Task 3\n" << endl;

    cout << "Student2 stud1(\"John Smith\", 20, \"Harvard\"); \n" << endl;
    Student2 stud1("John Smith", 20, "Harvard");
    cout << stud1 << endl;
    
    cout << "GraduateStudent gradStud1(\"Jane Doe\", 25, \"CHNU\", \"A Study of Chnu\"); \n" << endl;
    GraduateStudent gradStud1("Jane Doe", 25, "CHNU", "A Study of Chnu");
    cout << gradStud1 << endl;

    cout << "cin >> stud1;\n";
    cin >> stud1;
    cout << endl << stud1 << endl;

    return 0;
}
