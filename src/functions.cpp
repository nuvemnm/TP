#include "../include/functions.hpp"

/*
void swap(int* index1, int* index2) {
    int* temp = index1;
    index1 = index2;
    index2 = temp;
}
*/


void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
    }
}

void selectionSort(int numLines, std::string *string, int * index){
    for(int i = 0; i < numLines-1; i++){
        int minor = i;
        for(int j = i+1; j < numLines; j++){
            if(string[index[j]] < string[index[minor]]){
                minor = j;
            }
        }
        
        if(minor != i){
            std::swap(index[i], index[minor]);
        }
            
    }
    return;
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



void ordenaNome(int numLines, std::string * names, int * index){
    
    initIndice(numLines, index);
    selectionSort(numLines, names, index);

}





