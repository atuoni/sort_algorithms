

//************************************************************************************
// File:   main.cpp
// Author: Amauri Tuoni    Version 1.2
// 
// Program to test sort algorithms. User can choose the size of the array that will be
// ordered.
//
// Created on 19 de Outubro de 2020, 17:40
//************************************************************************************

#include <cstdlib>     //general library
#include <iostream>   //library for the cout function
#include <new>        //library for the new function
#include <limits>     // library for the cin.ignore function
#include <time.h>     // library for the clock function
#include <iomanip>    // library for the setprecision function
#include <chrono>

#include "array_generator.h"   //header of the array generator
#include "selection_sort.h"    //header 
#include "insertion_sort.h"    // header
#include "merge_sort.h"        // header
#include "quick_sort.h"        // header
#include "bubble_sort.h"       // header

#define RAND_MAX 100       // define the random number range  

int data_array_size(void);     //prototype of the data array size function
void show_data_array(int*,int,bool);     //prototype of the show data array function
void time_calc(int,int,int);      //prototype of the time calculate function

using namespace std;

//************************************************************************************
// * Main function (Show menu screen)
//**********************************************************************************

int main(void) 
{
    int menu_item;    //variable of the menu typed function 
    clock_t start_time, end_time;   // variable to store the start and end clock time
    int size_array;                          //variable to save the size of data_array
    int *data_array, *copy_array;            // pointer to the data array and a copy data array
    cout << " ********************** Sort Algorithms v1.2"
    " **************** Made by: A.T. " << endl<<endl;  // print on the screen the name of the program
    size_array=data_array_size();            // call the function to get the size of the data array 
    const int start_index = 0;             // set the start index of data array as zero 
    try    // verify a exception
    {
        data_array=new int [size_array];         // create a dynamic memory allocation of the data array
        copy_array= new int[size_array];         // create a dynamic memory allocation of the copy data array
    }
    catch (bad_alloc &memoryAllocationException) //treat exception bad allocation of memory
    {
        cerr << "Exception occurred: "<< memoryAllocationException.what() << endl;  //print on the screen a message 
    }
    
    array_generator(data_array,size_array);  //call funtion to generate the array elements
    copy(data_array,data_array+size_array,copy_array); // call function  to copy the data array 
    
    do  //print the menu on the screen
    {
       
        cout<<"\nChoose the algorithm: "<<endl;
        cout <<"1 - Selection sort"<<endl;
        cout<<"2 - Insertion sort"<<endl;
        cout<<"3 - Merge sort"<<endl;
        cout<<"4 - Quick sort"<<endl;
        cout<<"5 - Bubble sort"<<endl;
        cout<<"6 - Show array"<<endl;
        cout<<"7 - Modify array"<<endl;
        cout<<"8 - Exit"<<endl<<endl;
    
        cout<<"Type the menu option: "<<endl;        //print on the screen message
        cin.clear(ios::goodbit);    //clean the goodbit
        
        cin >> menu_item;                            //get the menu option
            
        
        while (!cin.good())  //loop while an incorrect value is typed
        {
            cout<<"Incorrect data typed! Type a number..."<<endl;
            cin.clear(ios::goodbit);                                   //clean the goodbit
            cin.ignore(numeric_limits<streamsize>::max(),'\n');     
            
            cin>> menu_item;   //get the menu item option from the user
        }
            
       
        switch(menu_item)  //test menu option chosen by user
        {
            case 1:
                show_data_array(data_array,size_array,false);  //call function to show the data array
                start_time=clock();                       //save the start clock tick
                selection_sort(copy_array,size_array);   //call function to do a linear search
                end_time=clock();                        //save the end clock tick
                show_data_array(copy_array,size_array,true);    //call function to show the data array ordered
                time_calc(start_time,end_time,menu_item);    // call function to calculate the time spent
                break;
            case 2:
                show_data_array(data_array,size_array,false);  //call function to show the data array
                start_time=clock();                        //save the start clock tick
                insertion_sort(copy_array,size_array); //call funtion to do a better linear search
                end_time=clock();                   //save the end clock tick
                show_data_array(copy_array,size_array,true);  //call function to show the data array ordered
                time_calc(start_time,end_time,menu_item);   // call function to calculate the time spent
                break;
            case 3:
                show_data_array(data_array,size_array,false);  //call function to show the data array
                start_time=clock();                           //save the start clock tick
                merge_sort(copy_array,start_index,size_array-1);      //call funtion to do a sentinel linear search
                end_time=clock();                                //save the end clock tick
                show_data_array(copy_array,size_array,true);    //call function to show the data array ordered
                time_calc(start_time,end_time,menu_item);          // call function to calculate the time spent
                break;
            case 4:
                show_data_array(data_array,size_array,false);  //call function to show the data array
                start_time=clock();                          //save the start clock tick
                quick_sort(copy_array,start_index,size_array-1); //call function to do a recursive linear search
                end_time=clock();                       //save the end clock tick
                show_data_array(copy_array,size_array,true);   //call function to show the data array ordered
                time_calc(start_time,end_time,menu_item);    // call function to calculate the time spent
                break;
            case 5:
                show_data_array(data_array,size_array,false);  //call function to show the data array
                start_time=clock();                      //save the start clock tick
                bubble_sort(copy_array,size_array);  //call function to do a binary search
                end_time=clock();                               //save the end clock tick
                show_data_array(copy_array,size_array,true);  ///call function to show the data array ordered
                time_calc(start_time,end_time,menu_item);      // call function to calculate the time spent
                break;
            case 6:
                show_data_array(data_array,size_array,false);             //call funtion to show the array generated
                break;
            case 7:
                size_array=data_array_size();                  // call the function to get the new size of the data array 
                delete [] copy_array;                           // delete the old copy array that was allocated (free space)
                delete [] data_array;                          // delete the old data array that was allocated (free space)
                try                               // verify a exception
                {
                    data_array= new int[size_array];                // create a new memory dynamic allocation of the data array
                    copy_array=new int[size_array];                  // create a new memory dynamic allocation of the copy array
                }
                catch (bad_alloc &memoryAllocationException)             //treat exception bad allocation of memory
                {
                    cerr << "Exception occurred: "<< memoryAllocationException.what()<< endl;       //print on the screen a message 
                }
                array_generator(data_array,size_array);            //call funtion to generate the new array elements
                copy(data_array,data_array+size_array,copy_array);   // call function  to copy the data array 
                break;
            case 8:
                cout<<"Ending..."<<endl;                          //print on screen a exit message
                delete [] data_array;                            //delete the old data array that was allocated before exit
                delete [] copy_array;
                exit(0);  //terminate program and go to the system
                break;
        
            default:
                cout<<"Incorrect menu option...Try again! "<<endl;                   //print on the screen a message about the wrong option
                cout<<endl;
                break;
        
        }
    
    }while(1);  //loop to show the menu forever 

}   //end of main function



//*******************************************************************************************************************************************************
// Function to get the size of the data array
//*******************************************************************************************************************************************************

int data_array_size(void)
{
    cout<<"Type the size of the data array :"<<endl;  //print on the screen the message
    int size;                                      // create the variable to store the size of array
    cin.clear(ios::goodbit);                         //clean the goodbit
    cin >> size;                                   // get the array size 
    
    while (!cin.good())   //loop while an incorrect value is typed
    {
        cout<<"Incorrect size data! Type a number..."<<endl;   //print on the screen a message of error
        cin.clear(ios::goodbit);                               //clean the goodbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //check unexpected type
        cin >> size;    // get the array size again
    }
    cout<<"Data Array Interval 0 - "<<RAND_MAX<<" with "<<size<<" elements"<< endl;  //print on the screen the number elements and the range of the array that will be generated
    return size;        //return the size of array value
} //end of the function


//**********************************************************************************
// Function to show the data array generated
//**********************************************************************************

void show_data_array(int *data, int size, bool ordered)
{
    if(ordered)
        cout<<"data_array_ordered   = {";             //print on the screen the data array ordered
    else
        cout<<"data_array = {";                      //print on the screen the data array not ordered
    
    for(int element=0;element<size;element++)     //loop to run the elements of the array
       cout<<data[element]<<",";                  //print on the screen the element
    cout<<"}\n"<<endl;                     //print on the screen 

} //end of the function

//*************************************************************************************
// Function to calculate and print the processing time of each algorithm
//*************************************************************************************
void time_calc (int start, int end, int item)
{
    string algorithm;  
    switch(item)        //verify the menu option selected
    {
        case 1:          // if "1"
            algorithm = " Selection Sort ";  // write the algorithm used on the screen
            break;
        case 2:
            algorithm = " Insertion Sort ";
            break;
        case 3:
            algorithm = " Merge Sort ";
            break;
        case 4:
            algorithm = " Quick Sort ";
            break;
        case 5:
            algorithm = " Bubble Sort ";
            break;
    }
    
    double elapsed_time; 
    elapsed_time = double(end - start)/double(CLOCKS_PER_SEC); //calculate the total time spent by the algorithm
 
    cout << "Time spent by" << algorithm << "was " << fixed  << elapsed_time << setprecision(6);  // print on the screen the time spent
    cout << " seconds" << endl;
}