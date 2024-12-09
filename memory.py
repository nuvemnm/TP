import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'DejaVu Serif'
plt.rcParams['mathtext.fontset'] = 'cm'

def plot_scatter(file_path, output_file, title):
    plt.figure(figsize=(14, 8))
    df = pd.read_csv(file_path, header=None)
    values = df[0]

    plt.scatter(range(len(values)), values, marker='x', s=4)

    ticks = np.arange(0, 1100, 200)
    labels = [f"{t}" for t in ticks]
    plt.yticks(ticks=ticks, labels=labels)

    plt.title(title, fontsize=16)
    plt.xlabel('Acesso', fontsize=12)
    plt.ylabel('Endereço', fontsize=12)

    plt.tight_layout()
    plt.savefig(output_file)
    plt.clf()

data = [
    #('r1000.p1000.quick.access', 'r1000.p1000.quick.scatter.png', 'Gráfico de Acesso de Memoria (Quick Sort)'),
    #('r1000.p1000.merge.access', 'r1000.p1000.merge.scatter.png', 'Gráfico de Acesso de Memoria (Merge Sort)'),
    ('r1000.p1000.shell.access', 'r1000.p1000.shell.scatter.png', 'Gráfico de Acesso de Memoria (Shell Sort)')
]

for file_path, output_file, title in data:
    plot_scatter(file_path, output_file, title)