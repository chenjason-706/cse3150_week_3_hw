
#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::string, std::cout, std::endl, std::cin;

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
	if (size >= capacity) 
		throw string("List full");
	names[size] = name;
	gpas[size] = gpa;
	size++;
}

void updateGPA(double* gpaPtr, double newGpa) {
	if (gpaPtr != nullptr) 
		*gpaPtr = newGpa;
}
void printStudent(const char* name, const double& gpa) {
	cout << name << endl
		<< gpa << endl;
}

double averageGPA(const double gpas[], int size) {
	if (size == 0)
		throw string("No students");
	
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += gpas[i];
	
	return static_cast<int>(sum) / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
		try {
			string student;
			double gpa;

			cout << "Enter Student name: ";	
			cin >> student;
			
			char* name = new char[student.length() + 1];
                	strcpy(name, student.c_str());


			cout << "Enter Student GPA: ";
			cin >> gpa;
			addStudent(name, gpa, names, gpas, size, capacity);

		} catch(string error_msg) {
			cout << error_msg << endl;
		}
		break;
            }
            case 2: {
		int gpa_index;
	        double new_gpa;
		cout << "Enter gpa index to update: ";
		cin >> gpa_index;
		
		cout << "Enter new GPA: ";
		cin >> new_gpa;

		updateGPA(&gpas[gpa_index], new_gpa);
                break;
            }
            case 3: {
                for (int i = 0; i < size; i++) {
			printStudent(names[i], gpas[i]);
		}
		break;

            }
            case 4: {
		try {
                	cout << "Average GPA is " << averageGPA(gpas, size) << endl;
		}catch(string error_msg) {
			cout << error_msg << endl;
		}
		break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    return 0;
}
