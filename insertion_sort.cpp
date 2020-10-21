//************************************************************************************
// File:   insertion_sort.cpp
// Author: Amauri Tuoni    
// 
// Program to test insertion sort algorithm. 
//
// Created on 19 de Outubro de 2020, 18:10
//************************************************************************************


void insertion_sort(int *data, int size)
{
    int element; // variable to save the index
    int previous_element;  // variable to save the previous index
    int key_aux;           // auxiliar variable
    for (element=1; element<size; element++)   // loop to run the data array until his end
    {
        key_aux = data[element];  // save the data of the current element 
        previous_element = element-1;  // save previous index 
        
        while ((previous_element>=0) && (data[previous_element]>key_aux)) // verify if previous data is greater then the current data and greater than zero
        {
            data[previous_element+1] = data[previous_element];   //save the previous data in the current index 
        
            previous_element = previous_element-1;   // decrease the previous index  
        }   
        data[previous_element+1] = key_aux; // save the current index data after the previous index    
    }
}   