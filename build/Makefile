SRC_DIR := ../src/source
HEAD_DIR := ../src/include
BIN_DIR := ../bin

# Compiler
CXX := g++

# Executable
TARGET := $(BIN_DIR)/prog.exe

$(TARGET): main.o layer.o comp_algo.o benchmark.o
	$(CXX) main.o layer.o comp_algo.o benchmark.o -o $(BIN_DIR)/prog.exe

main.o: $(SRC_DIR)/main.cpp
	$(CXX) -c $(SRC_DIR)/main.cpp -I $(HEAD_DIR)

layer.o: $(SRC_DIR)/layer.cpp $(HEAD_DIR)/layer.h
	$(CXX) -c $(SRC_DIR)/layer.cpp -I $(HEAD_DIR)

comp_algo.o: $(SRC_DIR)/comp_algo.cpp $(HEAD_DIR)/comp_algo.h $(HEAD_DIR)/layer.h
	$(CXX) -c $(SRC_DIR)/comp_algo.cpp -I $(HEAD_DIR)

benchmark.o : $(SRC_DIR)/benchmark.cpp $(HEAD_DIR)/benchmark.h $(HEAD_DIR)/comp_algo.h
	$(CXX) -c $(SRC_DIR)/benchmark.cpp -I $(HEAD_DIR)

clean:
	del *.o

cleanall:
	del *.o, ..\bin\*.exe

run:
	./$(TARGET)