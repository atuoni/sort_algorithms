
//******************************************************************************
// File:   selection_sort.cpp
// Author: Amauri Tuoni    
// 
// Program to test selection sort algorithms. 
//
// Created on 19 de Outubro de 2020, 17:40
//******************************************************************************


int selection_sort(int *data, int size)
{
    int less_element;  //variable to save the element
    int element;  // variable to save the index of data array
    int temp;     // auxiliar variable
    
    
    for(element=0; element<size;element++)   //loop to run the data_array
    {
        less_element=element;    //save current index as the less index
        for(int next_element=element+1;next_element<size;next_element++) //loop to run the data array with the next index
        {
            if(data[next_element]< data[less_element])  //compare if the next data is less than the data of the less index
            {
                less_element=next_element;  // save the next index as the less index
                
            }
            
        }
        temp=data[element];    
        data[element]=data[less_element]; //swap the data of the current element with the data of the less element
        data[less_element]=temp;
        
    }
    return 0;
}
