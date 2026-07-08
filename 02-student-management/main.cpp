#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string emri;
    double nota;
};

void shtoStudent(vector<Student>& studentet) {
    Student s;
    cout << "Shkruaj emrin: ";
    cin >> s.emri;
    cout << "Shkruaj noten: ";
    cin >> s.nota;
    studentet.push_back(s);
    cout << "Studenti u shtua me sukses!\n" << endl;
}

void shfaqStudentet(const vector<Student>& studentet) {
    if (studentet.empty()) {
        cout << "Nuk ka studente ende.\n" << endl;
        return;
    }
    cout << "\n=== Lista e Studenteve ===" << endl;
    for (size_t i = 0; i < studentet.size(); i++) {
        cout << i + 1 << ". " << studentet[i].emri 
             << " - Nota: " << studentet[i].nota << endl;
    }
    cout << endl;
}

void fshiStudent(vector<Student>& studentet) {
    if (studentet.empty()) {
        cout << "Nuk ka studente per te fshire.\n" << endl;
        return;
    }
    shfaqStudentet(studentet);
    cout << "Shkruaj numrin e studentit per ta fshire: ";
    int index;
    cin >> index;

    if (index < 1 || index > (int)studentet.size()) {
        cout << "Numer i pavlefshem!\n" << endl;
        return;
    }
    studentet.erase(studentet.begin() + (index - 1));
    cout << "Studenti u fshi me sukses!\n" << endl;
}

int main() {
    vector<Student> studentet;
    int zgjedhje;

    do {
        cout << "=== Student Management System ===" << endl;
        cout << "1. Shto Student" << endl;
        cout << "2. Shfaq Studentet" << endl;
        cout << "3. Fshi Student" << endl;
        cout << "4. Dil" << endl;
        cout << "Zgjedhja jote: ";
        cin >> zgjedhje;
        cout << endl;

        switch (zgjedhje) {
            case 1:
                shtoStudent(studentet);
                break;
            case 2:
                shfaqStudentet(studentet);
                break;
            case 3:
                fshiStudent(studentet);
                break;
            case 4:
                cout << "Mirupafshim!" << endl;
                break;
            default:
                cout << "Zgjedhje e pavlefshme!\n" << endl;
        }
    } while (zgjedhje != 4);

    return 0;
}