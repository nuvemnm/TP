#include "../include/functions.hpp"


void swap(int* index1, int* index2) {
    int temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}



void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
    }
}

void selectionSort(std::string *string, int * index, int tam){
    for(int i = 0; i < tam-1; i++){
        int minor = i;
        for(int j = i+1; j < tam; j++){
            if(string[index[j]] < string[index[minor]]){
                minor = j;
            }
        }
        
        if(minor != i){
            swap(&index[i], &index[minor]);
        }
            
    }
    return;
}

int partition(std::string * array, int * index, int low, int high){
    //Seleciona o elemento mais a direita como pivo
    std::string pivo = array[index[high]];
    //Indicce do maior elemento
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(array[index[j]] <= pivo){
            //Se o elemento for menor que o pivo 
            //troca ele com o maior elemento (i)
            i++;
            swap(&index[i], &index[j]);
        }
    }
    //Troca o pivo com o maior elemento a aprtir de i
    swap(&index[i+1], &index[high]);

    return (i+1);
}

void quickSort(std::string * array, int * index, int low, int high){
    if(low < high){
        //Encontra o pivo
        //Elementos menores do que o pivo ficam a esquerda
        //Elemetnos maiores do que o pivo ficam a direita
        int point = partition(array, index, low, high);

        //Chamada recursiva para os elementos a esquerda do pivo
        quickSort(array, index, low, point - 1);
        //Chamada recursiva para os elementos a direita do pivo
        quickSort(array, index, point + 1, high);
    }
}

void insertionSort(std::string * array,int * index, int tam){
     for(int i = 1;  i < tam; i++){
        int keyIndex = index[i];
        std::string key = array[keyIndex];
        int j = i - 1;

        while(j >= 0 && array[index[j]] > key){
            index[j+1] = index[j];
            j--;
        }
        index[j+1] = keyIndex;
     }
}

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive){
    
    std::string line = "";

    int j = 0;
    int position = 0;
    while(getline(archive, line)){

        position = line.find(',');
        names[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        cpf[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        address[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        payload[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        j++;
    }
}



void selectionNameSort(int tam, std::string * names, int * index){  
    initIndice(tam, index);
    selectionSort(names, index, tam);
}

void selectionCpfSort(int tam, std::string * cpf, int * index){
    initIndice(tam, index);
    selectionSort(cpf, index, tam);   
}

void selectionAddressSort(int tam, std::string * address, int * index){
    initIndice(tam, index);
    selectionSort(address, index, tam);
}

void quickNameSort(int tam, std::string * names, int * index){
    initIndice(tam, index);
    quickSort(names, index, 0, tam - 1);
}

void quickCpfSort(int tam, std::string * cpf, int * index){
    initIndice(tam, index);
    quickSort(cpf, index, 0, tam - 1);
}

void quickAddressSort(int tam, std::string * address, int * index){
    initIndice(tam, index);
    quickSort(address, index, 0, tam - 1);
}

void insetionNameSort(std::string * names, int * index, int tam){
    initIndice(tam, index);
    insertionSort(names, index, tam);
}

void insetionCpfSort(std::string * cpf, int * index, int tam){
    initIndice(tam, index);
    insertionSort(cpf, index, tam);
}

void insetionAddressSort(std::string * address, int * index, int tam){
    initIndice(tam, index);
    insertionSort(address, index, tam);
}