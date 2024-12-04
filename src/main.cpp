#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main(){
    std::ifstream file("cad.r1000.p1000.xcsv");


        // Verificar se o arquivo foi aberto com sucesso
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return 1;
        }

        std::string line;
        std::string *fields = new std::string[1000];
        int count = 0;
        // Ler linha por linha do arquivo
        while (std::getline(file, line)) {
            //std::stringstream ss(line);    
            // Separar os campos por vírgula
            if(count < 1000){
                fields[count++] = line;
            }else{
                break;
            }
            
        }

        // Exibir os campos lidos
        for (int j = 0; j < 6; j++) {
            std::cout << fields[j] << "\n";
        }
        std::cout << std::endl;

        // Fechar o arquivo
        file.close();

        return 0;
}