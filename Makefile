# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# Arquivo saída
EXEC = $(BIN_DIR)/tp3.out

# Compilador e flags
CC = g++
CFLAGS = -Wall -I$(INC_DIR)

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Gera os arquivos objeto a partir dos arquivos .cpp (substitui .cpp por .o e muda para o diretório obj)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal: compilar tudo e gerar o executável
$(EXEC): $(OBJS) | $(BIN_DIR)
	@echo "Compilando e criando o executável..."
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regra para compilar cada arquivo .cpp em um .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Criação do diretório obj
$(OBJ_DIR):
	@echo "Criando diretório $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)

# Criação do diretório bin
$(BIN_DIR):
	@echo "Criando diretório $(BIN_DIR)..."
	@mkdir -p $(BIN_DIR)

# Limpa os arquivos gerados (.o e o executável)
clean:
	@echo "Limpando arquivos gerados..."
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

# Regra 'all' para compilar e executar os comandos especificados
all: $(EXEC)

run: all
	./$(EXEC)
