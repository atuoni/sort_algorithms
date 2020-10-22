//************************************************************************************
// File:   quick_sort.cpp
// Author: Amauri Tuoni    
// 
// Program to test quick sort algorithm.
//
// Created on 19 de Outubro de 2020, 11:40
//************************************************************************************

int partition(int *,const int,const int); //prototype of partition function

void quick_sort(int *data, const int start, const int end)
{
    if (start>=end)   //return to main when the start>end (data_array checks finish)
        return;
    else
    {
        int pivot_index;  //variable to save the pivot index
        pivot_index = partition(data,start,end);  // function to divide the data array and return a pivot index
        quick_sort(data,start,pivot_index-1); // function to order the left side of data array
        quick_sort(data,pivot_index+1,end);   // function to order the right side of data array
    }
}
//******************************************************************************
// Function to divide the data array and return the pivot index 
// data less than pivot data = left side of the data array (no ordered)
// data greater than pivot data = right side of the data array (no ordered)
//******************************************************************************

int partition(int *data, const int start, const int end)
{
    int pivot = start; // choose a index to the pivot (start = 0)
    int temp;        // auxiliar variable
    int unknow;      // variable 
    
    for( unknow= start; unknow < end; unknow++) // loop to run the data_array until his end
    {
        if(data[unknow]<=data[end]) // verify if the data is less than the last data
        {
            temp= data[pivot];     //swap the unknow data with the pivot
            data[pivot]=data[unknow];
            data[unknow]=temp;
            pivot++;   //increase the pivot
        }
    }
    temp=data[pivot];  //swap the pivot data with the last data 
    data[pivot]=data[end];
    data[end]=temp;
    return pivot;  //return the pivot index
}