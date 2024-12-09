import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'DejaVu Serif'
plt.rcParams['mathtext.fontset'] = 'cm'

def plot_and_save(file_path, output_file, title):
    df = pd.read_csv(file_path, header=None)
    values = df[0]

    plt.bar(range(len(values)), values, width=1.0)
    plt.xlabel('Progressão de Acessos')
    plt.ylabel('Distância de Pilha')
    plt.title(title)

    plt.tight_layout()
    plt.savefig(output_file)
    plt.clf()

data = [
    #('r1000.p1000.quick.stack', 'r1000.p1000.quick.stack.png', 'Evolução da Distância de Pilha (Quick Sort)'),
    #('r1000.p1000.merge.stack', 'r1000.p1000.merge.stack.png', 'Evolução da Distância de Pilha (Merge Sort)'),
    ('r1000.p1000.shell.stack', 'r1000.p1000.shell.stack.png', 'Evolução da Distância de Pilha (Shell Sort)')
]

for file_path, output_file, title in data:
    plot_and_save(file_path, output_file, title)