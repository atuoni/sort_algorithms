//************************************************************************************
// File:   arraygenerator.cpp
// Author: Amauri Tuoni
// 
// Program to generated a array of random integer numbers. Interval from 0 to 10.
//
// Created on 26 de Setembro de 2020, 17:40
//************************************************************************************

#include <iostream>  //prototype for the cout function
#include <cstdlib>
#include <ctime>   //prototype for the function time

#include "array_generator.h"   //header of this function 

//#define RAND_MAX 10

using namespace std;

void array_generator(int *data,int size)       
{
    int number;   //variable to store the number
    unsigned int seed; //variable to store the seed
    
    seed = time(0); //generate the seed using the actual time
    srand(seed);   //put the seed on the random number generator 
    for(int element=0;element<size;element++)   //run each element of the data array
    {
        number = rand()%100;   //generate random number in the 0-10 interval
        data[element]=number;   // put the number on the data array
        cout<<"Generating array with "<<element+1<<" elements ..."<< endl;  //print on the screen a message for each element generated
    }
   
    cout<<"Done."<<endl<<endl;  // print on the screen that the array generation was done. 
}