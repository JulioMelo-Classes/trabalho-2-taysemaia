 
TARGET=concord
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic

BIN=./bin
OBJS= $(BIN)/main.o $(BIN)/Usuario.o $(BIN)/Mensagem.o $(BIN)/Sistema.o $(BIN)/CanalTexto.o $(BIN)/Servidor.o
all: $(OBJS)
	$(LD) -o $(BIN)/$(TARGET) $(OBJS) $(LDFLAGS)
 
$(BIN)/main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o $(BIN)/main.o
 
$(BIN)/Usuario.o: src/Usuario.cpp
	$(CC) -c $(CCFLAGS) src/Usuario.cpp  -o $(BIN)/Usuario.o
$(BIN)/Mensagem.o: src/Mensagem.cpp
	$(CC) -c $(CCFLAGS) src/Mensagem.cpp  -o $(BIN)/Mensagem.o
$(BIN)/Sistema.o: src/Sistema.cpp
	$(CC) -c $(CCFLAGS) src/Sistema.cpp  -o $(BIN)/Sistema.o
$(BIN)/CanalTexto.o: src/CanalTexto.cpp
	$(CC) -c $(CCFLAGS) src/CanalTexto.cpp  -o $(BIN)/CanalTexto.o
$(BIN)/Servidor.o: src/Servidor.cpp
	$(CC) -c $(CCFLAGS) src/Servidor.cpp  -o $(BIN)/Servidor.o
 
clean:
	rm -f $(BIN)/*.o $(BIN)/concord
