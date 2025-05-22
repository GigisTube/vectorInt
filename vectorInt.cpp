#include <iostream> 

#include "vectorInt.h"

using namespace std;

// Costruttori del vettore
vectorInt::vectorInt(){
    data = new int[0];
}

vectorInt::vectorInt(int size){
    dim = size;
    data = new int[dim];
    
    for (int i = 0; i < dim; i++) {
        data[i] = 0; 
    }
}

// Distruttore
vectorInt::~vectorInt(){ 
    delete []data;
    data = NULL;
}


// Funzioni pubbliche
void vectorInt::add_back(int enteredValue){
    dim++;
    
    if(dim == 1){
        
        vectorInt::fill_slot(dim - 1, enteredValue);
        
    } else {
        
        vectorInt::createCopy();
        vectorInt::createMain();
        vectorInt::fill_slot(dim - 1, enteredValue);
        
    }
}

void vectorInt::remove_back(){
    if (dim == 0) {
        return; 
    }

    if (dim == 1){
        delete []data;
        data = new int[0];
        dim = 0;
        
    } else { 
        vectorInt::createCopy(); 
        dim--;
        vectorInt::createMain(); 
    }
}

void vectorInt::fill_slot(int slot, int enteredValue){
    data[slot] = enteredValue;
}

void vectorInt::print_screen(){
    for(int j = 0; j < dim; j++){
        cout << data[j] << " "; 
    }
}

int vectorInt::get_size(){
    return dim;
}


// Funzioni private
void vectorInt::createCopy(){
    copyData = new int[dim - 1];
        
    for(int i = 0; i < dim - 1; i++){
        *(copyData + i) = *(data + i);
    }
    
    delete []data;
    data = NULL;
}

void vectorInt::createMain(){
    data = new int[dim];
        
    for(int i = 0; i < dim; i++){
        *(data + i) = *(copyData + i);
    }
    
    delete []copyData;
    copyData = NULL;
}

