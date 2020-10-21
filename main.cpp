

//************************************************************************************
// File:   main.cpp
// Author: Amauri Tuoni    Version 1.0
// 
// Program to test sort algorithms. User can choose the size of the array that will be
// ordered.
//
// Created on 19 de Outubro de 2020, 17:40
//************************************************************************************

#include <cstdlib>     //general library
#include <iostream>   //library for the cout function
#include <new>        //library for the new function
#include <limits>     // library

#include "array_generator.h"   //header of the array generator
#include "selection_sort.h"    //header of the selection sort algorithm
#include "insertion_sort.h"    // header
#include "merge_sort.h"        // header
#include "quick_sort.h"        // header
#include "bubble_sort.h"       // header

#define RAND_MAX 10       // define the random number range  

int data_array_size(void);     //prototype of the data array size function
void show_data_array(int*,int,bool);     //prototype of the show data array function

using namespace std;

//************************************************************************************
// * Main function (Show menu screen)
//**********************************************************************************

int main(void) 
{
    int menu_item;    //variables 
    int size_array, end_index;                          //variable to save the size of data_array
    int *data_array;                         // pointer to the data array
    cout << " ********************** Sort Algorithms v1.0 **************** Made by: A.T. " << endl<<endl;  // print on the screen the name of the program
    size_array=data_array_size();            // call the function to get the size of the data array 
    const int start_index = 0;
    end_index = size_array-1;
    int copy_array[size_array];
    try
    {
        data_array=new int [size_array];         // create a dynamic memory allocation of the data array
   
    }
    catch (bad_alloc &memoryAllocationException) //treat exception bad allocation of memory
    {
        cerr << "Exception occurred: "<< memoryAllocationException.what() << endl;  //print on the screen a message 
    }
    
    array_generator(data_array,size_array);  //call funtion to generate the array elements
    copy(data_array,data_array+size_array,copy_array);
    
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
            cin.clear(ios::goodbit);   //clean the goodbit
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
            cin>> menu_item;   //get the menu item option from the user
        }
            
       
        switch(menu_item)  //test menu option chosen by user
        {
            case 1:
                show_data_array(data_array,size_array,false);
                selection_sort(copy_array,size_array);   //call function to do a linear search
                show_data_array(copy_array,size_array,true);    //call function to show the data array created
                break;
            case 2:
                show_data_array(data_array,size_array,false);
                insertion_sort(copy_array,size_array); //call funtion to do a better linear search
                show_data_array(copy_array,size_array,true);  //call function to show the data array created
                break;
            case 3:
                show_data_array(data_array,size_array,false);
                merge_sort(copy_array,start_index,end_index);      //call funtion to do a sentinel linear search
                show_data_array(copy_array,size_array,true);    //call function to show the data array created
                break;
            case 4:
                show_data_array(data_array,size_array,false);
                quick_sort(copy_array,start_index,end_index); //call function to do a recursive linear search
                show_data_array(copy_array,size_array,true);   //call function to show the data array created
                break;
            case 5:
                show_data_array(data_array,size_array,false);
                bubble_sort(copy_array,size_array);  //call function to do a binary search
                show_data_array(copy_array,size_array,true);  // call function to print the result on the screen
                break;
            case 6:
                show_data_array(data_array,size_array,false);             //call funtion to show the array generated
                break;
            case 7:
                size_array=data_array_size();                  // call the function to get the new size of the data array 
                delete [] data_array;                          // delete the old data array that was allocated (free space)
                try                               // verify the allocation done
                {
                    data_array= new int[size_array];                // create a new memory dynamic allocation of the data array
                }
                catch (bad_alloc &memoryAllocationException)             //treat exception bad allocation of memory
                {
                    cerr << "Exception occurred: "<< memoryAllocationException.what()<< endl;       //print on the screen a message 
                }
                array_generator(data_array,size_array);            //call funtion to generate the new array elements
                copy(data_array,data_array+size_array,copy_array);
                break;
            case 8:
                cout<<"Ending..."<<endl;                          //print on screen a exit message
                delete [] data_array;                            //delete the old data array that was allocated before exit
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
        cout<<"data_array_ordered   = {";             //print on the screen
    else
        cout<<"data_array = {";
    
    for(int element=0;element<size;element++)     //loop to run the elements of the array
       cout<<data[element]<<",";                  //print on the screen the element
    cout<<"}\n"<<endl;                     //print on the screen 

} //end of the function

