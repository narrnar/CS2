//Daren Sathasivam
//CS2 0122
//Assignment #1, Problem #6
//A program that gathers data on how many movies students have gone and watched. The program will prompt the user to input the number of students and how many each has watched, which will be stored in a dynamically allocated array. The stored vales will be taken into functions that calculate the average and median and then outputs the results.
#include <iostream>
#include <iomanip>
using namespace std;

//declare functions with parameters that take in movies pointer and int students
void numOfMovies(int *movies, int students);
float average(int *movies, int students);
float median(int *movies, int students);
void bubbleSort(int * moveis, int students);

int main()
{
    cout << setprecision(2) << fixed << showpoint;
    int students;   //declare number of students and pointer var for number of movies
    int *movies;
    cout << "Enter the number of students surveyed: ";  //Prompt/get num of students
    cin >> students;
    while (students < 0)    //Validate number of students
    {
        cout << "Invalid number of students! Re-enter: ";
        cin >> students;
    }
    //dynamically store values in movie var
    movies = new int[students];
    //call functions into main
    numOfMovies(movies, students);
    bubbleSort(movies, students);
    
    //print out results by calling float funcs
    cout << endl << "Number of students surveyed: " << students << endl;
    cout << "Average number of movies watched: " << average(movies, students) << endl;
    cout << "Median number of movies watched: " << median(movies, students) << endl;
    delete []movies; //delete bc movies is dyn allocated
    return 0;
}

//function that stores the number of movies for each corresponding student
void numOfMovies(int *movies, int students)
{
    for (int i = 0; i < students; i++)
    {
        cout << "How many movies has student #" << (i + 1) << " seen?: ";
        cin >> movies[i];
        while (movies[i] < 0)    //Validate number of movies
        {
            cout << "Invalid number of movies! Re-enter: ";
            cin >> movies[i];
        }
    }
}

//function for average number of movies watched and returns float
float average(int *movies, int students)
{
    float sum = 0;
    for (int i = 0; i < students; i++)
    {
        sum += movies[i];
    }
    return (sum / students);
}

//Bubble sort function referenced from Kalisch CSCI-1. Used for finding median.
void bubbleSort(int *movies, int students)
{
    bool hasSwapped;
    do{
        hasSwapped = false;
        for (int i = 0; i < students; i++)
        {
            if(movies[i - 1] > movies[i])
            {
                int tmp = movies[i - 1];
                movies[i - 1] = movies[i];
                movies[i] = tmp;
                hasSwapped = true;
            }
        }
    } while(hasSwapped);
}

//function for median number of movies watched and returns float
float median(int *movies, int students)
{
    int mid;
    if(students % 2 == 1) //if odd number of students
    {
        mid = (students + 1) / 2;   //i.e. mid of 5 is 3. (5+1)/2=3
        return (movies[mid - 1]);   //-1 bc array starts at 0
    }
    else                //number of students is even
    {
        mid = students / 2;
        return ((movies[mid - 1] + movies[mid]) / 2);   //find median between two mid vals
    }
}
