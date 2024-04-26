#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

// Define the Student class
template<typename T>
class Student {
private:
    string name;
    string id;
    double gpa;

public:
    // Constructors
    Student() : id(""), name(""), gpa(0.0) {}
    Student(string id, string name, double gpa) : id(id), name(name), gpa(gpa) {}
    Student(const Student &other) : id(other.id), name(other.name), gpa(other.gpa) {}

    // Member functions
    bool operator<(const Student& other) const {
        return this->name < other.name;
    }

    // Getter functions
    string getID() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getGPA() const {
        return gpa;
    }

    // Static member functions (declaration only)
    static int getCount();
    static void create(string id, string name, double gpa);
};

// Implement the create function for the Student class
template <typename T>
void Student<T>::create(string id, string name, double gpa) {
    Student<T>(id, name, gpa);
}

// Implement the quickSort function for the Student class
template <typename T>
void quickSort(vector<Student<T>>& arr);

// Implement the quickSort function for the Student class with l and h parameters
template <typename T>
void quickSort(vector<Student<T>>& arr, int l, int h);

// Implement the partition function for the Student class
template <typename T>
int partition(vector<Student<T>>& arr, int l, int h);

// Implement the swap_quick function for the Student class
template <typename T>
void swap_quick(vector<Student<T>>& arr, unsigned int i, unsigned int j);

// Implement the mergeSort function for the Student class
template <typename T>
void mergeSort(vector<Student<T>>& array, int l, int r);

// Implement the merge function for the Student class
template<class T>
void merge(vector<Student<T>>& array, int l, int m, int r);

// Implement the CountSort function for the Student class
template <typename T>
void CountSort(vector<Student<T>>& students);

// Implement the Max function for the Student class
template <typename T>
double Max(const vector<Student<T>>& students);

// Implement the readData function for the Student class
template <typename T>
vector<Student<T>> readData(const string& filename);

// Implement the writeData function for the Student class
template <typename T>
void writeData(const string& filename, const vector<Student<T>>& students, const string& algorithmName, double elapsedTime);



// Implement the merge function for the Student class
template<class T>
void merge(vector<Student<T>>& array, int l, int m, int r) {
    int i = 0, j = 0, k = l;
    int nl = m - l + 1;
    int nr = r - m;

    vector<Student<T>> larr(nl), rarr(nr);

    // Copy data to temporary vectors larr[] and rarr[]
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];

    // Merge the temporary vectors back into array[l..r]
    i = 0;
    j = 0;
    while (i < nl && j < nr) {
        if (larr[i] < rarr[j]) {
            array[k] = larr[i];
            i++;
        } else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of larr[] if any
    while (i < nl) {
        array[k] = larr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rarr[] if any
    while (j < nr) {
        array[k] = rarr[j];
        j++;
        k++;
    }
}

// Implement the mergeSort function for the Student class
template<class T>
void mergeSort(vector<Student<T>>& array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // Merge the sorted halves
        merge(array, l, m, r);
    }
}

// Implement the quickSort function for the Student class
template<class T>
void quickSort(vector<Student<T>>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// Implement the quickSort function for the Student class with l and h parameters
template <typename T>
void quickSort(vector<Student<T>>& arr, int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

// Implement the partition function for the Student class
template <typename T>
int partition(vector<Student<T>>& arr, int l, int h) {
    Student<T> pivot = arr[h];
    int i = l;
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            swap_quick(arr, i, j);
            i++;
        }
    }
    swap_quick(arr, i, h);
    return i;
}

// Implement the swap_quick function for the Student class
template <typename T>
void swap_quick(vector<Student<T>>& arr, unsigned int i, unsigned int j) {
    Student<T> temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Implement the CountSort function for the Student class
template <typename T>
void CountSort(vector<Student<T>>& students) {
    double maxGPA = Max(students);

    // Create count array
    vector<int> count(static_cast<int>(maxGPA) + 1, 0);

    // Update count array values based on student GPAs
    for (const auto& student : students) {
        count[static_cast<int>(student.getGPA())]++;
    }

    // Update students vector with sorted elements
    int i = 0;
    for (int j = 0; j <= static_cast<int>(maxGPA); ++j) {
        while (count[j] > 0) {
            students[i++] = Student<T>(students[0].getID(), students[0].getName(), j); // Use the first student's ID and name, and GPA of j
            count[j]--;
        }
    }
}

template <class T>
double Max(const vector<Student<T>>& students) {
    double max = -32768.0; // Assuming GPAs are non-negative
    for (const auto& student : students) {
        if (student.getGPA() > max) {
            max = student.getGPA();

        }
    }
    return max;
}


// Implement the readData function for the Student class
template <typename T>
vector<Student<T>> readData(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error in opening the file" << endl;
        exit(1);
    }

    vector<Student<T>> students;
    string id, name;
    double gpa;
    while (fin >> id >> name >> gpa) {
        students.emplace_back(id, name, gpa);
    }
    fin.close();
    return students;
}

// Implement the writeData function for the Student class
template <typename T>
void writeData(const string& filename, const vector<Student<T>>& students, const string& algorithmName, double elapsedTime) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open the file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    outFile << "Algorithm name: " << algorithmName << endl;
    outFile << "Running Time (in milliseconds): " << elapsedTime << endl;
    outFile << "Sorted Student Elements:" << endl;

    for (const auto& student : students) {
        outFile << student.getID() << endl;
        outFile << student.getName() << endl;
        outFile << student.getGPA() << endl;
        outFile << endl;
    }

    outFile.close();
}






int main() {
    int choice;
    cout << "How would you like to sort the data?" << endl;
    cout << "1. Sort by names" << endl;
    cout << "2. Sort by GPAs" << endl;
    cin >> choice;

    string filename = "students.txt";
    vector<Student<string>> studentsByName;
    vector<Student<double>> studentsByGPA;

    switch (choice) {
        case 1:
            studentsByName = readData<string>(filename);
            break;
        case 2:
            studentsByGPA = readData<double>(filename);
            break;
        default:
            cerr << "Invalid choice. Exiting..." << endl;
            return 1;
    }

    cout << "Welcome to the Student System! You can sort the data based on names or GPAs." << endl;
    int algorithmNumber;
    cout << "Which sorting algorithm do you want to use ?\n"
         << "1- Insertion Sort\n"
         << "2- Selection Sort\n"
         << "3- Bubble Sort\n"
         << "4- Shell Sort\n"
         << "5- Merge Sort\n"
         << "6- Quick Sort\n"
         << "7- Count Sort\n"
         << "Your choice :" << endl;

    cin >> algorithmNumber;
    string algorithmName;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    double runTime = 0;

    switch (algorithmNumber) {
        case 1:
            algorithmName = "Insertion Sort";
            // Implement insertion sort
            break;
        case 2:
            algorithmName = "Selection Sort";
            // Implement selection sort
            break;
        case 3:
            algorithmName = "Bubble Sort";
            // Implement bubble sort
            break;
        case 4:
            algorithmName = "Shell Sort";
            // Implement shell sort
            break;
        case 5:
            algorithmName = "Merge Sort";
            if (choice == 1) {
                mergeSort(studentsByName, 0, studentsByName.size() - 1);
                // Debug print sorted data
                cout << "Sorted by name:" << endl;
                writeData("SortedByName.txt", studentsByName, algorithmName, 0);
            } else if (choice == 2) {
                mergeSort(studentsByGPA, 0, studentsByGPA.size() - 1);
                // Debug print sorted data
                cout << "Sorted by GPA:" << endl;
                writeData("SortedByGPA.txt", studentsByGPA, algorithmName, 0);
            }
            break;
        case 6:
            algorithmName = "Quick Sort";
            if (choice == 1) {
                quickSort(studentsByName);
            } else if (choice == 2) {
                quickSort(studentsByGPA);
            }
            break;
        case 7:
            algorithmName = "Count Sort";
            if (choice == 1) {
                CountSort(studentsByName);
            } else if (choice == 2) {
                CountSort(studentsByGPA);
            }
            break;
        default:
            cerr << "Invalid input!" << endl;
            return 0;
    }

    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    switch (choice) {
        case 1:
            writeData("SortedByName.txt", studentsByName, algorithmName + " (by name)", runTime);
            break;
        case 2:
            writeData("SortedByGPA.txt", studentsByGPA, algorithmName + " (by GPA)", runTime);
            break;
        default:
            cerr << "Invalid choice. Exiting..." << endl;
            return 1;
    }

    return 0;
}
