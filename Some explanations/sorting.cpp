#include<bits/stdc++.h>
#include <chrono>
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


template<class T>
void merge(Student<T> arr[], size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    // Create temporary arrays for the left and right halves
    Student<T>* larr = new Student<T>[n1];
    Student<T>* rarr = new Student<T>[n2];

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

template<class T>
void mergeSort(Student<T> arr[], size_t l, size_t r) {
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
//count sort

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
    float gpa;

public:
        student():id(""),name(""),gpa(0.0){};//default constructor to initilize array of this object
    student(string id,string name,float gpa);
    student(const student &other);
    bool operator<(const student& student1){
        return name < student1.name;
    };

    string get_id(){
        return id;
    }
    string get_name(){
        return name;
    }
    float get_gpa(){
        return gpa;
    }

};

student::student(string id,string name, float gpa) {
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

int main() {
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    ifstream inputFile("C:\\data structure\\students.txt");// opens students txt file
    int stud_num;
    inputFile>>stud_num;//this will read the first line of the file which is the number of students obj
    student stud[stud_num];//array of students
    if (!inputFile) cout<<"error opening the file"<<endl;


    for (int i=0;i<stud_num;i++){//this will loop on every single line right after the first line read in int stud_num
        string id,name;
        float gpa;
        inputFile.ignore();//this ignores newline char right after first character
        getline(inputFile,name);//this will include space also while reading name
        inputFile>>id;
        inputFile>>gpa;
        stud[i] = student(id,name,gpa);//then it will store each data of a student in one obj of this student
    }

    student arr_copy[stud_num];//coping array to get to original non-sorted array whenever we measure
    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }


    inputFile.close();

    double runTime;
    //INSERTION SORT FOR BOTH BASES
    //for name
    start = chrono::high_resolution_clock::now();
    ofstream outFileName("C:\\data structure\\SortedByNAME.txt");
    InsertionSortBY_NAME(arr_copy,stud_num,outFileName);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName<<"Algorithm: Insertion Sort"<<endl;
    outFileName<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileName,arr_copy,stud_num);

    //for gpa
    start = chrono::high_resolution_clock::now();
    ofstream outFileGPA("C:\\data structure\\SortedByGPA.txt");
    InsertionSortBY_GPA(arr_copy,stud_num,outFileGPA);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA<<"Algorithm: Insertion Sort"<<endl;
    outFileGPA<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //SELECTION SORT FOR BOTH BASES
    //for name
    start = chrono::high_resolution_clock::now();
    selectionSortBy_NAME(arr_copy,stud_num,outFileName);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName<<"Algorithm: Selection Sort"<<endl;
    outFileName<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileName,arr_copy,stud_num);


    //for gpa
    start = chrono::high_resolution_clock::now();
    selectionSortBy_GPA(arr_copy,stud_num,outFileGPA);
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA<<"Algorithm: Selection Sort"<<endl;
    outFileGPA<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);



    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //BUBBLE SORT FOR BOTH BASES
    start = chrono::high_resolution_clock::now();
    BubbleSortBY_NAME(arr_copy,stud_num,outFileName);
    outFileName<<"Algorithm: Bubble Sort"<<endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileName,arr_copy,stud_num);

    start = chrono::high_resolution_clock::now();
    BubbleSortBY_GPA(arr_copy,stud_num,outFileGPA);
    outFileGPA<<"Algorithm: Bubble Sort"<<endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //SHELL SORT FOR BOTH BASES
    start = chrono::high_resolution_clock::now();
    shellSortBY_NAME(arr_copy,stud_num,outFileName);
    outFileName<<"Algorithm: shell Sort"<<endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileName<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileName,arr_copy,stud_num);

    start = chrono::high_resolution_clock::now();
    shellSortBY_GPA(arr_copy,stud_num,outFileGPA);
    outFileGPA<<"Algorithm: shell Sort"<<endl;
    end = chrono::high_resolution_clock::now();
    runTime = chrono::duration<double, std::milli>(end - start).count();
    outFileGPA<<"Running Time: "<<runTime<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //MERGE SORT FOR BOTH BASES

    //QUICK SORT FOR BOTH BASES

    //int COUNT SORT


}




