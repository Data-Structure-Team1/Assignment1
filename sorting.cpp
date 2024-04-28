#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>


using namespace std;


//template part of all sorting algorithms
template<class T>
void InsertionSort(T arr[], int n) {
    int num_comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        num_comparisons++;
        int j = 0;
        T temp = arr[i];
        for (int j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            num_comparisons++;
            arr[j] = arr[j - 1];
            arr[j-1] = temp;
        }

    }
    cout<<"number of comparisons: "<<num_comparisons<<endl;


}
//Selection sort
template<class T>
void selectionSort(T arr[], int n) {
    int num_comparisons =0;
    for (int i = 0; i < n - 1; i++)
    {
        T temp = i;
        for (int j = i + 1; j < n; j++)
        {
            num_comparisons++;
            if (arr[j] < arr[temp])
                temp = j;
        }

        swap(arr[i], arr[temp]);

    }
    cout<<"number of comparisons: "<<num_comparisons<<endl;


}

//Bubble sort
template<class T>
void BubbleSort(T arr[], int n) {
    int num_comparisons =0;
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                num_comparisons++;
                swap(arr[j], arr[j + 1]);
                flage = false;
            }

        }
        if (flage)
            break;
    }
    cout<<"number of comparisons: "<<num_comparisons<<endl;
}

//Shall sort
template <class T>
void shellSort(T arr[], int n){
    int num_comparisons =0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i ++)
        {

            T temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                num_comparisons++;

            }

            arr[j] = temp;
        }
    }
    cout<<"number of comparisons: "<<num_comparisons<<endl;

}
//merge sort
template <class T>
void merge(T arr[], size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    // Create temporary arrays for the left and right halves
    T* larr = new T[n1];
    T* rarr = new T[n2];

    // Copy data to temporary arrays larr[] and rarr[]
    for (size_t i = 0; i < n1; i++)
        larr[i] = arr[l + i];
    for (size_t j = 0; j < n2; j++)
        rarr[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    size_t i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (larr[i] <= rarr[j]) {
            arr[k++] = larr[i++];
        } else {
            arr[k++] = rarr[j++];
        }
    }

    // Copy the remaining elements of left array if any
    while (i < n1) {
        arr[k++] = larr[i++];
    }

    // Copy the remaining elements of right array if any
    while (j < n2) {
        arr[k++] = rarr[j++];
    }

    // Free dynamically allocated memory
    delete[] larr;
    delete[] rarr;
}

template <class T>
void mergeSort(T arr[], size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

//quick sort
template<typename T>
int partition_quick(T* arr, int l, int h);

// Forward declaration of swap_quick function
template<typename T>
void swap_quick(T* arr, unsigned int i, unsigned int j);

// Quick sort function with a single parameter
template<typename T>
void quickSort(T* arr, int size) {
    quickSort(arr, 0, size - 1);
}

// Recursive quickSort function for the generic class
template<typename T>
void quickSort(T* arr, int l, int h) {
    if (l < h) {
        int p = partition_quick(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

// Partition function for the generic class
template<typename T>
int partition_quick(T* arr, int l, int h) {
    T pivot = arr[h];
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

// Swap function for the generic class
template<typename T>
void swap_quick(T* arr, unsigned int i, unsigned int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//count sort
template<typename T>
void CountSort(T* data, int size);

// Implement the CountSort function for the data
template<typename T>
void CountSort(T* data, int size) {

    double maxValue = Max(data, size);

    // Create count array
    int maxIntValue = static_cast<int>(maxValue);
    int* count = new int[maxIntValue + 1]();

    // Update count array values based on data
    for (int i = 0; i < size; ++i) {
        count[static_cast<int>(data[i].getValue())]++;
    }

    // Update data array with sorted elements
    int i = 0;
    for (int j = 0; j <= maxIntValue; ++j) {
        while (count[j] > 0) {
            // Assuming there's a constructor for your data type that takes ID, name, and value
            data[i++] = T(data[0].getID(), data[0].getName(), j); // Use the first element's ID and name, and value of j
            count[j]--;
        }
    }

    delete[] count;
}

// Helper function to find the maximum value in the data array
template<class T>
double Max(T* data, int size) {
    double max = -32768.0; // Assuming values are non-negative
    for (int i = 0; i < size; ++i) {
        if (data[i].getValue() > max) {
            max = data[i].getValue();
        }
    }
    return max;
}


template<class T>
void print(T arr[], int n) {
    for (int i = 0; i <n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class student{
    string id;
    string name;
    double gpa;

public:
    student():id(""),name(""),gpa(0.0){};//default constructor to initilize array of this object
    student(string id,string name,double gpa);
    student(const student &other);
    bool operator <<(const student& student1){
        return name < student1.name;
    };

    string get_id(){
        return id;
    }
    string get_name(){
        return name;
    }
   double get_gpa(){
        return gpa;

    }



};

student::student(string id,string name, double gpa) {
    this->id = id;
    this->name=name;
    this->gpa=gpa;
}

student::student(const student &other) {
    id=other.id;
    name=other.name;
    gpa=other.gpa;
}


void InsertionSortBY_NAME(student arr[], int n,ofstream &of) {
    int num_comparisons=0;

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        student temp = arr[i];
        for (int j = i; j > 0 && temp.get_name() < arr[j - 1].get_name(); j--)
        {
            num_comparisons++;
            arr[j] = arr[j - 1];
            arr[j-1] = temp;
        }

    }
    of<<"number of comparisons: "<<num_comparisons<<endl;


}

void InsertionSortBY_GPA(student arr[], int n,ofstream &of) {
    int num_comparisons=0;
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        student temp = arr[i];
        for ( j=i-1; j >= 0 && temp.get_gpa() > arr[j].get_gpa(); j--)
        {
            num_comparisons++;
            arr[j+1] = arr[j];

        }
        arr[j+1] = temp;

    }
    of<<"number of comparisons: "<<num_comparisons<<endl;

}

void selectionSortBy_NAME(student arr[], int n,ofstream &of) {
    int num_comparisons=0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < n; j++)
        {
            num_comparisons++;
            if (arr[j].get_name() < arr[temp].get_name())
                temp = j;

        }

        swap(arr[i], arr[temp]);
    }
    of<<"number of comparisons: "<<num_comparisons<<endl;
}
void selectionSortBy_GPA(student arr[], int n,ofstream &of) {
    int num_comparisons=0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < n; j++)
        {
            num_comparisons++;
            if (arr[j].get_gpa() > arr[temp].get_gpa())
                temp = j;
        }

        swap(arr[i], arr[temp]);

    }
    of<<"number of comparisons: "<<num_comparisons<<endl;
}
void BubbleSortBY_NAME(student arr[], int n,ofstream &of) {
    int num_comparisons=0;
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].get_name() > arr[j + 1].get_name()) {
                swap(arr[j], arr[j + 1]);
                flage = false;
                num_comparisons++;
            }

        }
        if (flage)
            break;
    }
    of<<"number of comparisons: "<<num_comparisons<<endl;
}
void BubbleSortBY_GPA(student arr[], int n,ofstream &of) {
    int num_comparisons=0;
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].get_gpa() < arr[j + 1].get_gpa()) {
                swap(arr[j], arr[j + 1]);
                flage = false;
                num_comparisons++;
            }

        }
        if (flage)
            break;
    }of<<"number of comparisons: "<<num_comparisons<<endl;
}


void shellSortBY_NAME(student arr[], int n,ofstream &of){
    int num_comparisons=0;
    for (int gap = n / 2; gap > 0; gap /= 2){

        for (int i = gap; i < n; i ++){
            student temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap].get_name() > temp.get_name(); j -= gap) {
                arr[j] = arr[j - gap];
                num_comparisons++;
            }
            arr[j] = temp;
        }
    }
    of<<"number of comparisons: "<<num_comparisons<<endl;
}
void shellSortBY_GPA(student arr[], int n,ofstream &of){
    int num_comparisons=0;
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i ++)
        {

            student temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap].get_gpa() < temp.get_gpa(); j -= gap) {
                arr[j] = arr[j - gap];
                num_comparisons++;
            }

            arr[j] = temp;
        }
    }
    of<<"number of comparisons: "<<num_comparisons<<endl;
}
void printArray(student arr[], int n){//print result in the console
    for (int i=0;i<n;i++){
        cout<<"NAME: "<<arr[i].get_name()<<endl;
        cout<<"ID: "<<arr[i].get_id()<<endl;
        cout<<"GPA: "<<arr[i].get_gpa()<<endl;
        cout<<endl;
    }
}

void printInTXT(ofstream &of , student arr[], int n){//prints result in output file
    for (int i=0;i<n;i++){
        of<<arr[i].get_name()<<endl;
        of<<arr[i].get_id()<<endl;
        of<<arr[i].get_gpa()<<endl;
        of<<endl;
    }
}

// Quick sort function for sorting students by GPA
void quickSort_ByGPA(student arr[], int l, int h);

// Partition function for quickSort by GPA
int partition_quick_ByGPA(student arr[], int l, int h);

// Swap function for swapping student objects
void swap_quick_gpa(student arr[], int i, int j);

// Quick sort function with a single parameter
void quickSort_ByGPA(student arr[], int size) {
    quickSort_ByGPA(arr, 0, size - 1);
}

// Recursive quickSort function for sorting students by GPA
void quickSort_ByGPA(student arr[], int l, int h) {
    if (l < h) {
        int p = partition_quick_ByGPA(arr, l, h);
        quickSort_ByGPA(arr, l, p - 1);
        quickSort_ByGPA(arr, p + 1, h);
    }
}

// Partition function for quickSort by GPA
int partition_quick_ByGPA(student arr[], int l, int h) {
    student pivot = arr[h];
    int i = l;
    for (int j = l; j < h; j++) {
        if (arr[j].get_gpa() >= pivot.get_gpa()) {
            swap_quick_gpa(arr, i, j);
            i++;
        }
    }
    swap_quick_gpa(arr, i, h);
    return i;
}

// Swap function for swapping student objects
void swap_quick_gpa(student arr[], int i, int j) {
    student temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Quick sort function for sorting students by name
void quickSort_ByName(student* arr, int size);

// Recursive quickSort function for sorting students by name
void quickSort_ByName(student* arr, int l, int h);

// Partition function for quickSort by name
int partition_quick_ByName(student* arr, int l, int h);

// Quick sort function for sorting students by name
void quickSort_ByName(student* arr, int size) {
    quickSort_ByName(arr, 0, size - 1);
}

// Recursive quickSort function for sorting students by name
void quickSort_ByName(student* arr, int l, int h) {
    if (l < h) {
        int p = partition_quick_ByName(arr, l, h);
        quickSort_ByName(arr, l, p - 1);
        quickSort_ByName(arr, p + 1, h);
    }
}

// Partition function for quickSort by name
int partition_quick_ByName(student* arr, int l, int h) {
    student pivot = arr[h];
    int i = l;
    for (int j = l; j < h; j++) {
        if (arr[j].get_name() < pivot.get_name()) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[h]);
    return i;
}

//merge for gpa
// Merge sort function for sorting students by GPA
void mergeSort_ByGPA(student arr[], size_t l, size_t r);

// Merge function for merging two sorted halves by GPA
void merge_ByGPA(student arr[], size_t l, size_t m, size_t r);

// Merge sort function for sorting students by GPA
void mergeSort_ByGPA(student arr[], size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        mergeSort_ByGPA(arr, l, m);
        mergeSort_ByGPA(arr, m + 1, r);
        merge_ByGPA(arr, l, m, r);
    }
}

// Merge function for merging two sorted halves by GPA
void merge_ByGPA(student arr[], size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    // Create temporary arrays for the left and right halves
    student* larr = new student[n1];
    student* rarr = new student[n2];

    // Copy data to temporary arrays larr[] and rarr[]
    for (size_t i = 0; i < n1; i++)
        larr[i] = arr[l + i];
    for (size_t j = 0; j < n2; j++)
        rarr[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    size_t i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (larr[i].get_gpa() >= rarr[j].get_gpa()) {
            arr[k++] = larr[i++];
        } else {
            arr[k++] = rarr[j++];
        }
    }

    // Copy the remaining elements of left array if any
    while (i < n1) {
        arr[k++] = larr[i++];
    }

    // Copy the remaining elements of right array if any
    while (j < n2) {
        arr[k++] = rarr[j++];
    }

    // Free dynamically allocated memory
    delete[] larr;
    delete[] rarr;
}

//merge for name
// Merge sort function for sorting students by name
void mergeSort_ByNAME(student arr[], size_t l, size_t r);

// Merge function for merging two sorted halves by name
void merge_ByNAME(student arr[], size_t l, size_t m, size_t r);

// Merge sort function for sorting students by name
void mergeSort_ByNAME(student arr[], size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        mergeSort_ByNAME(arr, l, m);
        mergeSort_ByNAME(arr, m + 1, r);
        merge_ByNAME(arr, l, m, r);
    }
}

// Merge function for merging two sorted halves by name
void merge_ByNAME(student arr[], size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    // Create temporary arrays for the left and right halves
    student* larr = new student[n1];
    student* rarr = new student[n2];

    // Copy data to temporary arrays larr[] and rarr[]
    for (size_t i = 0; i < n1; i++)
        larr[i] = arr[l + i];
    for (size_t j = 0; j < n2; j++)
        rarr[j] = arr[m + 1 + j];

// Merge the temporary arrays back into arr[l..r]
    size_t i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (larr[i].get_name() <= rarr[j].get_name()) {
            arr[k++] = larr[i++];
        } else {
            arr[k++] = rarr[j++];
        }
    }

    // Copy the remaining elements of left array if any
    while (i < n1) {
        arr[k++] = larr[i++];
    }

    // Copy the remaining elements of right array if any
    while (j < n2) {
        arr[k++] = rarr[j++];
    }

    // Free dynamically allocated memory
    delete[] larr;
    delete[] rarr;
}


//count sort for int
void countSort(double arr[], int n) {
    // Find the maximum and minimum elements in the array
    double maxElement = *std::max_element(arr, arr + n);
    double minElement = *std::min_element(arr, arr + n);

    // Convert the double array to integer array for sorting
    std::vector<int> intArr(n);
    for (int i = 0; i < n; ++i) {
        intArr[i] = static_cast<int>((arr[i] - minElement) * 1000);
    }

    // Find the maximum integer element in the converted array
    int maxIntElement = *std::max_element(intArr.begin(), intArr.end());

    // Create a count array to store the count of each element
    std::vector<int> count(maxIntElement + 1, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < n; ++i) {
        count[intArr[i]]++;
    }

    // Modify the count array to store the actual position of each element in the output array
    for (int i = 1; i <= maxIntElement; ++i) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted integer elements
    std::vector<int> output(n);

    // Fill the output array by placing elements in their correct sorted positions
    for (int i = n - 1; i >= 0; --i) {
        output[count[intArr[i]] - 1] = intArr[i];
        count[intArr[i]]--;
    }

    // Convert the sorted integer array back to double array
    for (int i = 0; i < n; ++i) {
        arr[i] = static_cast<double>(output[i]) / 1000.0 + minElement;
    }
}


int main() {
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    ifstream inputFile("C:\\data structure\\students.txt");// opens students txt file
    int stud_num;
    inputFile >> stud_num;//this will read the first line of the file which is the number of students obj
    student stud[stud_num];//array of students
    if (!inputFile) cout << "error opening the file" << endl;


    for (int i = 0; i < stud_num; i++) {//this will loop on every single line right after the first line read in int stud_num
        string id, name;
        float gpa;
        inputFile.ignore();//this ignores newline char right after first character
        getline(inputFile, name);//this will include space also while reading name
        inputFile >> id;
        inputFile >> gpa;
        stud[i] = student(id, name, gpa);//then it will store each data of a student in one obj of this student
    }

    student arr_copy[stud_num];//coping array to get to original non-sorted array whenever we measure
    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }


    inputFile.close();

    double runTime;
    //INSERTION SORT FOR BOTH BASES
    //for name
    start = chrono::high_resolution_clock::now();
    ofstream outFileName("C:\\data structure\\SortedByNAME.txt");
    InsertionSortBY_NAME(arr_copy, stud_num, outFileName);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Algorithm: Insertion Sort" << endl;
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);

    //for gpa
    start = chrono::high_resolution_clock::now();
    ofstream outFileGPA("C:\\data structure\\SortedByGPA.txt");
    InsertionSortBY_GPA(arr_copy, stud_num, outFileGPA);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Algorithm: Insertion Sort" << endl;
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);


    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }


    //SELECTION SORT FOR BOTH BASES
    //for name
    start = chrono::high_resolution_clock::now();
    selectionSortBy_NAME(arr_copy, stud_num, outFileName);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Algorithm: Selection Sort" << endl;
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);


    //for gpa
    start = chrono::high_resolution_clock::now();
    selectionSortBy_GPA(arr_copy, stud_num, outFileGPA);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Algorithm: Selection Sort" << endl;
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);



    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }


    //BUBBLE SORT FOR BOTH BASES
    start = chrono::high_resolution_clock::now();
    BubbleSortBY_NAME(arr_copy, stud_num, outFileName);
    outFileName << "Algorithm: Bubble Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);

    start = chrono::high_resolution_clock::now();
    BubbleSortBY_GPA(arr_copy, stud_num, outFileGPA);
    outFileGPA << "Algorithm: Bubble Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);


    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }
    printArray(arr_copy, stud_num);


    //SHELL SORT FOR BOTH BASES
    start = chrono::high_resolution_clock::now();
    shellSortBY_NAME(arr_copy, stud_num, outFileName);
    outFileName << "Algorithm: shell Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);

    start = chrono::high_resolution_clock::now();
    shellSortBY_GPA(arr_copy, stud_num, outFileGPA);
    outFileGPA << "Algorithm: shell Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);



    //MERGE SORT FOR BOTH BASES

    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }
    printArray(arr_copy, stud_num);


    start = chrono::high_resolution_clock::now();
    mergeSort_ByNAME(arr_copy, 0, stud_num - 1);
    outFileName << "Algorithm: Merge Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);

    start = chrono::high_resolution_clock::now();
    mergeSort_ByGPA(arr_copy, 0, stud_num - 1);
    outFileGPA << "Algorithm: Merge Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);

    //QUICK SORT FOR BOTH BASES
    for (int i = 0; i < stud_num; i++) {// different type of sorting
        arr_copy[i] = stud[i];
    }
    printArray(arr_copy, stud_num);
    start = chrono::high_resolution_clock::now();
    quickSort_ByName(arr_copy, stud_num);
    outFileName << "Algorithm: quick Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName << "Running Time: " << runTime << endl;
    printInTXT(outFileName, arr_copy, stud_num);

    start = chrono::high_resolution_clock::now();
    quickSort_ByGPA(arr_copy, stud_num);
    outFileGPA << "Algorithm: quick Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);


    start = chrono::high_resolution_clock::now();
    countSort(reinterpret_cast<double*>(arr_copy), stud_num);
    outFileGPA << "Algorithm: count Sort" << endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA << "Running Time: " << runTime << endl;
    printInTXT(outFileGPA, arr_copy, stud_num);


    //deallocate the array
    for (int i = 0; i < stud; i++)
        delete[] arr_copy[i];
    delete[] arr_copy;
}




