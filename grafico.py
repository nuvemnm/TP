import matplotlib.pyplot as plt
import csv

def plot_sort_times(csv_filename):
    # Dados a serem armazenados
    charge = []  # Índices representando cada linha do arquivo (1, 2, 3, ...)
    selection = []
    quick = []
    insertion = []

    # Ler o arquivo CSV
    with open(csv_filename, 'r') as file:
        reader = csv.reader(file)
        for idx, row in enumerate(reader):
            charge.append(str(row[0]))  # Adiciona 1 ao índice para começar de 1
            selection.append(float(row[1]))
            quick.append(float(row[2]))
            insertion.append(float(row[3]))

    # Gráficos para cada tipo de ordenação
    plt.figure(figsize=(10, 8))

    # Selection Sort
    #plt.subplot(3, 1, 1)
    plt.plot(charge, selection, label="Merge Sort", marker='o')
    plt.plot(charge, quick, label="Quick Sort - CPF", marker='s')
    plt.plot(charge, insertion, label="Shell Sort", marker='^')
    plt.title("Algoritmos de Ordenação")
    plt.xlabel("Carga de Trabalho")
    plt.ylabel("Tempo (segundos)")
    plt.legend()
    plt.grid()

    # Ajustar layout e exibir
    plt.tight_layout()
    plt.savefig("grafico_sorts.png")  # Salva o gráfico em um arquivo
    # plt.show()  # Comente ou remova esta linha se não precisar

# Chamada da função
plot_sort_times("tempos.csv")
