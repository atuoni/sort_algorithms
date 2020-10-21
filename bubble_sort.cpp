
//************************************************************************************
// File:   bubble_sort.cpp
// Author: Amauri Tuoni    
// 
// Program to test the bubble sort algorithm. 
//
// Created on 19 de Outubro de 2020, 15:10
//************************************************************************************

void bubble_sort(int *data, int size)
{
    int temp;  //auxiliar variable
    for(int element=0;element<size;element++)   //loop to run until the end of array
    {
        for(int element_next=element+1; element_next<size; element_next++) //loop to run the array with an next index  
        {
            if(data[element_next] < data[element])  // verify if the next data is less than the current data 
            {
                temp=data[element];      //save the current data
                data[element]=data[element_next];  // swap data
                data[element_next]=temp;      // save the current data on the next index position
            }
        }
    }
}  // end of function

