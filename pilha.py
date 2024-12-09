import pandas as pd
import matplotlib.pyplot as plt

def plot_sort_times(csv_filename):
    # Ler o arquivo CSV usando pandas
    df = pd.read_csv(csv_filename)

    # Verificar as primeiras linhas do DataFrame

    # Plotar os dados
    plt.figure(figsize=(10, 8))
    plt.bar(df.index, df["index"])
    plt.title("Quick Sort")
    plt.xlabel("Índices")
    plt.ylabel("Valores")
    #plt.legend()
    #plt.grid()

    # Ajustar layout e exibir
    plt.tight_layout()
    plt.savefig("grafico_sorts.png")  # Salva o gráfico em um arquivo
    # plt.show()  # Comente ou remova esta linha se não precisar

# Chamada da função
plot_sort_times("pilha.xcsv")