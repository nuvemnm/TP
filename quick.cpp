#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int partition(std::string * array, int low, int high){
    //Seleciona o elemento mais a direita como pivo
    std::string pivo = array[high];
    //Indicce do maior elemento
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(array[j] <= pivo){
            //Se o elemento for menor que o pivo 
            //troca ele com o maior elemento (i)
            i++;
            std::swap(array[i], array[j]);
        }
    }
    //Troca o pivo com o maior elemento a aprtir de i
    std::swap(array[i+1], array[high]);

    return (i+1);
}

void quickSort(std::string * array, int low, int high){
    if(low < high){
        //Encontra o pivo
        //Elementos menores do que o pivo ficam a esquerda
        //Elemetnos maiores do que o pivo ficam a direita
        int point = partition(array, low, high);

        //Chamada recursiva para os elementos a esquerda do pivo
        quickSort(array, low, point - 1);
        //Chamada recursiva para os elementos a direita do pivo
        quickSort(array, point + 1, high);
    }
}

int main(){
    std::string array[] = {"abacaxi", "pera", "carro", "mesa", "cadeira", "premio", "força"};
    int n = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < n; i++){
        std::cout<< array[i] << " ";
    }
    std::cout<<'\n';
    
    quickSort(array, 0, n-1);
    for(int i = 0; i < n; i++){
        std::cout<< array[i] << " ";
    }
    std::cout<<'\n';
    
}