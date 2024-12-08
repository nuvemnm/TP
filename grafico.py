import matplotlib.pyplot as plt
import csv

def plot_sort_times(csv_filename):
    # Dados a serem armazenados
    indices = []  # Índices representando cada linha do arquivo (1, 2, 3, ...)
    selection_name = []
    selection_cpf = []
    selection_address = []
    quick_name = []
    quick_cpf = []
    quick_address = []
    insertion_name = []
    insertion_cpf = []
    insertion_address = []

    # Ler o arquivo CSV
    with open(csv_filename, 'r') as file:
        reader = csv.reader(file)
        for idx, row in enumerate(reader):
            indices.append(idx + 1)  # Adiciona 1 ao índice para começar de 1
            selection_name.append(float(row[0]))
            selection_cpf.append(float(row[1]))
            selection_address.append(float(row[2]))
            quick_name.append(float(row[3]))
            quick_cpf.append(float(row[4]))
            quick_address.append(float(row[5]))
            insertion_name.append(float(row[6]))
            insertion_cpf.append(float(row[7]))
            insertion_address.append(float(row[8]))

    # Gráficos para cada tipo de ordenação
    plt.figure(figsize=(12, 8))

    # Selection Sort
    plt.subplot(3, 1, 1)
    plt.plot(indices, selection_name, label="Selection Sort - Nome", marker='o')
    plt.plot(indices, selection_cpf, label="Selection Sort - CPF", marker='s')
    plt.plot(indices, selection_address, label="Selection Sort - Endereço", marker='^')
    plt.title("Selection Sort")
    plt.xlabel("Execução (Linha no Arquivo)")
    plt.ylabel("Tempo (segundos)")
    plt.legend()
    plt.grid()

    # Quick Sort
    plt.subplot(3, 1, 2)
    plt.plot(indices, quick_name, label="Quick Sort - Nome", marker='o')
    plt.plot(indices, quick_cpf, label="Quick Sort - CPF", marker='s')
    plt.plot(indices, quick_address, label="Quick Sort - Endereço", marker='^')
    plt.title("Quick Sort")
    plt.xlabel("Execução (Linha no Arquivo)")
    plt.ylabel("Tempo (segundos)")
    plt.legend()
    plt.grid()

    # Insertion Sort
    plt.subplot(3, 1, 3)
    plt.plot(indices, insertion_name, label="Insertion Sort - Nome", marker='o')
    plt.plot(indices, insertion_cpf, label="Insertion Sort - CPF", marker='s')
    plt.plot(indices, insertion_address, label="Insertion Sort - Endereço", marker='^')
    plt.title("Insertion Sort")
    plt.xlabel("Execução (Linha no Arquivo)")
    plt.ylabel("Tempo (segundos)")
    plt.legend()
    plt.grid()

    # Ajustar layout e exibir
    plt.tight_layout()
    plt.savefig("grafico_sorts.png")  # Salva o gráfico em um arquivo
    # plt.show()  # Comente ou remova esta linha se não precisar

# Chamada da função
plot_sort_times("tempos.csv")
