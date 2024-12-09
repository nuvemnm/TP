import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'DejaVu Serif'
plt.rcParams['mathtext.fontset'] = 'cm'

def plot_histogram(file_path, output_file, title):
    df = pd.read_csv(file_path, header=None)
    values = df[0]

    plt.hist(values, bins=1000)
    plt.xlabel('Distância de Pilha')
    plt.ylabel('Frequência')
    plt.title(title)

    plt.savefig(output_file)
    plt.clf()

data = [
    #('r1000.p1000.quick.stack', 'r1000.p1000.quick.hist.png', 'Histograma da Distância de Pilha (Quick Sort)'),
    #('r1000.p1000.merge.stack', 'r1000.p1000.merge.hist.png', 'Histograma da Distância de Pilha (Merge Sort)'),
    ('r1000.p1000.shell.stack', 'r1000.p1000.shell.hist.png', 'Histograma da Distância de Pilha (Shell Sort)')
]

for file_path, output_file, title in data:
    plot_histogram(file_path, output_file, title)