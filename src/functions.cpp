#include "../include/functions.hpp"


void swap(int* index1, int* index2) {
    int temp = *index1;
    *index1 = *index2;
    *index2 = temp;
    //std::cout << &index1 << std::endl;
    //std::cout << &index2 << std::endl;
}

void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
        //std::cout << &indice[i] << std::endl;
    }
}

void merge(std::string * array, int * index, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int * L = new int[n1];
    int * R = new int[n2];

    for(int i = 0; i < n1; i++){
        L[i] = index[left + i];
        //std::cout << &index[left + i] << std::endl;
    }
    for(int j = 0; j < n2; j++){
        R[j] = index[mid + 1 + j];
        //std::cout << &index[mid + 1 + j] << std::endl;
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(array[L[i]] <= array[R[j]]){
            index[k] = L[i];
            //std::cout << &index[k] << std::endl;
            i++;
        }else{
            index[k] = R[j];
            //std::cout << &index[k] << std::endl;
            j++;
        }
        k++;
    }

    while(i < n1){
        index[k] = L[i];
        //std::cout << &index[k] << std::endl;
        i++;
        k++;
    }

    while(j < n2){
        index[k] = R[j];
        //std::cout << &index[k] << std::endl;
        j++;
        k++;
    }

    // Libera memória alocada dinamicamente
    delete[] L;
    delete[] R;
}

void mergeSort(std::string * array, int * index, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(array, index, left, mid);
        mergeSort(array, index, mid + 1, right);

        merge(array, index, left, mid, right);
    }
}

int partition(std::string * array, int * index, int low, int high){
    //Seleciona o elemento mais a direita como pivo
    std::string pivo = array[index[high]];
    //std::cout << &index[high] << std::endl;
    //Indicce do maior elemento
    int i = (low - 1);

    for(int j = low; j < high; j++){
        //std::cout << &index[j] << std::endl;
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

void shellSort(std::string * array, int * index, int n){
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int tempIndex = index[i];
            //std::cout << &index[i] << std::endl;
            int j;
            for(j = i; j >= gap && array[index[j - gap]] > array[tempIndex]; j -= gap){
                //std::cout << &index[j - gap] << std::endl;
                index[j] = index[j - gap];
                //std::cout << &index[j] << std::endl;
            }
            index[j] = tempIndex;
            //std::cout << &index[j] << std::endl;
        }
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


void printOutput(int * index, std::string * header, std::string * names, std::string * cpf, std::string * address, std::string * payload, int n){
    for (int i = 0; i < 6; i++){
        std::cout << header[i] << std::endl;
    }

    for (int j = 0; j < n ; j++){
        std::cout << names[index[j]]<< "," << cpf[index[j]] << "," << address[index[j]] << "," << payload[index[j]] << std::endl;
    }
}

void saveToCSV( std::string filename, std::string charges[], double * mergeTimes, double * quickTimes, double * shellTimes) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar os tempos!" << std::endl;
        return;
    }

    // Escrever os dados
    for(int i = 0; i < 4; i++)
    file << charges[i] << ","
         << mergeTimes[i] << ","
         << quickTimes[i] << "," 
         << shellTimes[i] << "\n";
    

    file.close();
}

