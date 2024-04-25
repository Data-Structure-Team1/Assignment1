#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

template<class T>
class Student {
private:
    string name;
    string id;
    double gpa;

public:
    Student() : id(""), name(""), gpa(0.0) {}
    Student(string id, string name, double gpa) : id(id), name(name), gpa(gpa) {}
    Student(const Student &other) : id(other.id), name(other.name), gpa(other.gpa) {}

    bool operator<(const Student& student1) {
        return name < student1.name;
    }

    string getID() {
        return id;
    }

    string getN() {
        return name;
    }

    double getGPA() const{
        return gpa ;
    }

    static int getCount();

    static void create(string id, string name, double gpa);
};

template <typename T>
void Student<T>::create(string id, string name, double gpa) {
    Student<T>(id, name, gpa);
}

template <typename T>
void quickSort(vector<Student<T>>& arr);

template <typename T>
void quickSort(vector<Student<T>>& arr, int l, int h);

template <typename T>
int partition(vector<Student<T>>& arr, int l, int h);

template <typename T>
void swap_quick(vector<Student<T>>& arr, unsigned int i, unsigned int j);

template <typename T>
void mergeSort(vector<Student<T>>& array, int l, int r);

template<class T>
void merge(vector<Student<T>>& array, int l, int m, int r);

template <typename T>
void CountSort(vector<Student<T>>& students);

template <typename T>
double Max(const vector<Student<T>>& students);

template <typename T>
vector<Student<T>> readData(const string& filename);

template <typename T>
void writeData(const string& filename, const vector<Student<T>>& students, const string& algorithmName, int comparisons, double elapsedTime);

int comparisonCount = 0;

void resetComparisonCount() {
    comparisonCount = 0;
}

int getComparisonCount() {
    return comparisonCount;
}

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

template <typename T>
void quickSort(vector<Student<T>>& arr) {
    resetComparisonCount();
    quickSort(arr, 0, arr.size() - 1);
}

template <typename T>
void quickSort(vector<Student<T>>& arr, int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

template <typename T>
int partition(vector<Student<T>>& arr, int l, int h) {
    Student<T> pivot = arr[h];
    int i = l;
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            swap_quick(arr, i, j);
            i++;
        }
        comparisonCount++;
    }
    swap_quick(arr, i, h);
    return i;
}

template <typename T>
void swap_quick(vector<Student<T>>& arr, unsigned int i, unsigned int j) {
    Student<T> temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void CountSort(vector<Student<T>>& students) {
    double maxGPA = Max(students);

    // Create count array
    vector<int> count(static_cast<int>(maxGPA) + 1, 0);

    // Update count array values based on student GPAs
    for (const auto& student : students) {
        count[static_cast<int>(student.getGPA())]++; // Corrected from students.getGPA() to student.getGPA()
    }

    // Update students vector with sorted elements
    int i = 0;
    for (int j = 0; j <= static_cast<int>(maxGPA); ++j) {
        while (count[j] > 0) {
            students[i++] = Student<T>("", "", j); // Dummy constructor, you might want to provide real data here
            count[j]--;
        }
    }
}


template <typename T>
double Max(const vector<Student<T>>& students) {
    double max = -32768.0; // Assuming GPAs are non-negative
    for (const auto& student : students) {
        if (student.getGPA() > max) {
            max = student.getGPA();

        }
    }
    return max;
}

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

template <typename T>
void writeData(const string& filename, const vector<Student<T>>& students, const string& algorithmName, int comparisons, double elapsedTime) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Error in opening the file " << filename << endl;
        return;
    }

    fout << "Algorithm name: " << algorithmName << endl;
    fout << "Number of comparisons: " << comparisons << endl;
    fout << "Running Time (in milliseconds): " << elapsedTime << endl;
    fout << "Sorted Student Elements:" << endl;

    for (const auto& student : students) {
        if constexpr (is_same<T, string>::value) {
            fout << student.getN() << " " << student.get_gpa() << endl;
        } else if constexpr (is_same<T, double>::value) {
            fout << student.get_gpa() << " " << student.getN() << endl;
        }
    }
    fout.close();
}

int main() {
    int x;
    cout << "Do you want to sort data by :\n"
         << "1- Names\n"
         << "2- GPA" << endl;
    cin >> x;

    string filename = "students.txt";
    vector<Student<string>> students_str; // For sorting by names
    vector<Student<double>> students_gpa; // For sorting by GPAs

    if (x == 1) {
        students_str = readData<string>(filename);
    } else if (x == 2) {
        students_gpa = readData<double>(filename);
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
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
         << "7- Count Sort" << endl;
    cin >> algorithmNumber;

    auto start = chrono::system_clock::now();
    switch(algorithmNumber) {
        case 1:
            // Implement insertion sort
            break;
        case 2:
            // Implement selection sort
            break;
        case 3:
            // Implement bubble sort
            break;
        case 4:
            // Implement shell sort
            break;
        case 5:
            if (x == 1) {
                mergeSort(students_str, 0, students_str.size() - 1);
            } else if (x == 2) {
                mergeSort(students_gpa, 0, students_gpa.size() - 1);
            }
            break;
        case 6:
            int h;
            cout << "Choose the pivot index: ";
            cin >> h;
            if (x == 1) {
                quickSort(students_str);
            } else if (x == 2) {
                quickSort(students_gpa);
            }
            break;
        case 7:
            if (x == 1) {
                CountSort(students_str);
            } else if (x == 2) {
                CountSort(students_gpa);
            }
            break;
        default:
            cout << "Invalid input!" << endl;
            return 0;
    }

    auto end = chrono::system_clock::now();
    cout << "Sorting time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
