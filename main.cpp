#include<bits/stdc++.h>
using namespace std;

template<class T>
void InsertionSort(T arr[], int n) {

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        T temp = arr[i];
        for (int j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];

            arr[j-1] = temp;
        }

    }


}
//Selection sort
template<class T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        T temp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[temp])
                temp = j;
        }

        swap(arr[i], arr[temp]);

    }


}
//Bubble sort
template<class T>
void BubbleSort(T arr[], int n) {
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flage = false;
            }

        }
        if (flage)
            break;
    }
}

//Shall sort
template <class T>
void shellSort(T arr[], int n)
{

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i ++)
        {

            T temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
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
void InsertionSortBY_NAME(student arr[], int n) {

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        student temp = arr[i];
        for (int j = i; j > 0 && temp.get_name() < arr[j - 1].get_name(); j--)
        {
            arr[j] = arr[j - 1];

            arr[j-1] = temp;
        }

    }


}

void InsertionSortBY_GPA(student arr[], int n) {

    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        student temp = arr[i];
        for ( j=i-1; j >= 0 && temp.get_gpa() > arr[j].get_gpa(); j--)
        {
            arr[j+1] = arr[j];

        }
        arr[j+1] = temp;

    }

}

void selectionSortBy_NAME(student arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].get_name() < arr[temp].get_name())
                temp = j;
        }

        swap(arr[i], arr[temp]);

    }
}
void selectionSortBy_GPA(student arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].get_gpa() > arr[temp].get_gpa())
                temp = j;
        }

        swap(arr[i], arr[temp]);

    }
}
void BubbleSortBY_NAME(student arr[], int n) {
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].get_name() > arr[j + 1].get_name()) {
                swap(arr[j], arr[j + 1]);
                flage = false;
            }

        }
        if (flage)
            break;
    }
}
void BubbleSortBY_GPA(student arr[], int n) {
    bool flage = true;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].get_gpa() < arr[j + 1].get_gpa()) {
                swap(arr[j], arr[j + 1]);
                flage = false;
            }

        }
        if (flage)
            break;
    }
}
void shellSortBY_NAME(student arr[], int n)
{

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i ++)
        {

            student temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap].get_name() > temp.get_name(); j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}
void shellSortBY_GPA(student arr[], int n)
{

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i ++)
        {

            student temp = arr[i];
            int j ;
            for (j = i; j >= gap && arr[j - gap].get_gpa() < temp.get_gpa(); j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}
void printArray(student arr[], int n){
    for (int i=0;i<n;i++){
        cout<<"NAME: "<<arr[i].get_name()<<endl;
        cout<<"ID: "<<arr[i].get_id()<<endl;
        cout<<"GPA: "<<arr[i].get_gpa()<<endl;
        cout<<endl;
    }
}

void printInTXT(ofstream &of , student arr[], int n){
    for (int i=0;i<n;i++){
        of<<arr[i].get_name()<<endl;
        of<<arr[i].get_id()<<endl;
        of<<arr[i].get_gpa()<<endl;
        of<<endl;
    }
}

int main() {
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

    //INSERTION SORT FOR BOTH BASES
    InsertionSortBY_NAME(arr_copy,stud_num);
    ofstream outFileName("C:\\data structure\\SortedByNAME.txt");
    outFileName<<"Algorithm: Insertion Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileName<<"Running Time: "<<endl;
    printInTXT(outFileName,arr_copy,stud_num);


    InsertionSortBY_GPA(arr_copy,stud_num);
    ofstream outFileGPA("C:\\data structure\\SortedByGPA.txt");
    outFileGPA<<"Algorithm: Insertion Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileGPA<<"Running Time: "<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //SELECTION SORT FOR BOTH BASES
    selectionSortBy_NAME(arr_copy,stud_num);
    outFileName<<"Algorithm: Selection Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileName<<"Running Time: "<<endl;
    printInTXT(outFileName,arr_copy,stud_num);


    selectionSortBy_GPA(arr_copy,stud_num);
    outFileGPA<<"Algorithm: Selection Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileGPA<<"Running Time: "<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);



    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //BUBBLE SORT FOR BOTH BASES
    BubbleSortBY_NAME(arr_copy,stud_num);
    outFileName<<"Algorithm: Bubble Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileName<<"Running Time: "<<endl;
    printInTXT(outFileName,arr_copy,stud_num);


    BubbleSortBY_GPA(arr_copy,stud_num);
    outFileGPA<<"Algorithm: Bubble Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileGPA<<"Running Time: "<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //SHELL SORT FOR BOTH BASES
    shellSortBY_NAME(arr_copy,stud_num);
    outFileName<<"Algorithm: shell Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileName<<"Running Time: "<<endl;
    printInTXT(outFileName,arr_copy,stud_num);


    shellSortBY_GPA(arr_copy,stud_num);
    outFileGPA<<"Algorithm: shell Sort"<<endl;
    outFileName<<"Number of Comparisons : "<<endl;
    outFileGPA<<"Running Time: "<<endl;
    printInTXT(outFileGPA,arr_copy,stud_num);


    for(int i=0;i<stud_num;i++){// different type of sorting
        arr_copy[i]=stud[i];
    }
    printArray(arr_copy,stud_num);


    //MERGE SORT FOR BOTH BASES

    //QUICK SORT FOR BOTH BASES

    //int COUNT SORT


}




