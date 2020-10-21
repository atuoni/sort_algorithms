//************************************************************************************
// File:   merge_sort.cpp
// Author: Amauri Tuoni    
// 
// Program to test merge sort algorithm.
//
// Created on 18 de Outubro de 2020, 17:40
//************************************************************************************


void merge(int *, int, int, int); //prototype of merge function

//**********************************************************************************
// Merge Sort function using recursive mode
//**********************************************************************************
void merge_sort(int *data, const int start, const int end)    
{
    
    if(start < end) //if the index of the data_array doesn't get the end
    {
        int mid = start + (end-start)/2;  // calculate the mid index of the data array
        
        merge_sort(data,start,mid);     // call function merge sort using the left side of the data array
        merge_sort(data, mid+1, end);   //call function merge sort using the right side of the data array
        merge(data,start,mid,end);      // merge the right and left side of the data array
    }
    
}  //end of the function



//*****************************************************************************************
// Merge function to merge the left and right arrays
//*****************************************************************************************

void merge(int *data, int start, int mid, int end)
{
    int size_left = mid - start +1 ;  // calculate the size of the left array
    int size_right = end - mid;        // calculate the size of the right array
    
    int left_array[size_left];        // create the left aux array
    int right_array[size_right];       // create the right aux array
    
    for(int i=0; i<size_left; i++)          // loop of the left aux array 
        left_array[i] = data[start+i];   //copy data from data_array to the left aux array
    for (int j=0; j<size_right; j++)         // loop of the right aux array
        right_array[j] = data[mid+1+j];   // copy data from data_array to the right aux array
    
    int element_left = 0;  // set the element of the left array to zero
    int element_right = 0;  // set the element of the right array to zero
    int element_start = start;  // set the element to start index of the data array (0)
    
    while (element_left<size_left && element_right < size_right)  // loop until the size of aux arrays
    {
        if (left_array[element_left] <= right_array[element_right]) // verify which data of the aux arrays is less
        {
            data[start]= left_array[element_left]; //copy data of the left aux array to the start of the data_array 
            element_left++;   // increment the index of the left aux array
        }
        else    
        {
            data[start] = right_array[element_right];  //copy data of the right aux array to the start of the data_array
            element_right++;   //increment the index of the right auz array
        }
        start++;  //increment the index of the data_array
    } //end of the while
    
    while ( element_left < size_left)  //loop again until the size of the left aux array
    {
        data[start] = left_array[element_left]; //copy data of the left aux array to the start of the data_array 
        
        element_left++; //increment the index of the left aux array
        start++;  //increment the index of the data_array
        
    }  // end of the while
    
    while(element_right < size_right)  //loop again until the size of the right aux array
    {
        data[start] = right_array[element_right]; //copy data of the right aux array to the start of the data_array 
        
        element_right++; //increment the index of the right aux array
        start++;  //increment the index of the data_array
    }  //end of the while
    
}

