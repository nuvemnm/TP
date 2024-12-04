# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# Arquivo saída
EXEC = $(BIN_DIR)/tp.out

# Compilador e flags
CC = g++
CFLAGS = -Wall -I$(INC_DIR)

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Gera os arquivos objeto a partir dos arquivos .c (substitui .c por .o e muda para o diretório obj)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))



# Regra principal: compilar tudo e gerar o exxecutável
$(EXEC): $(OBJS)
	@echo "Compilando e criando o executável..."
	$(CC) $(CFLAGS) -o $@ $(OBJS) -o $(EXEC)

# Regra para compilar cada arquivo .c em um .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos gerados (.o e o executável)
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

#Regra 'all' para compilar e executar os comandos especificados
all: $(EXEC)

run: all 
	./$(EXEC)