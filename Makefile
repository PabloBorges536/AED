# Makefile para projeto AED
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRCDIR = src
INCDIR = include
BINDIR = bin
BUILDDIR = build
TESTDIR = tests

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
TARGET = $(BINDIR)/main

# Arquivos de teste
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:$(TESTDIR)/%.cpp=$(BUILDDIR)/%.o)
TEST_TARGET = $(BINDIR)/test_runner

# Arquivos utilitários (excluindo main.cpp)
UTIL_SOURCES = $(filter-out $(SRCDIR)/main.cpp, $(SOURCES))
UTIL_OBJECTS = $(UTIL_SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Regra padrão
all: $(TARGET)

# Criar o executável principal
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

# Criar o executável de testes
$(TEST_TARGET): $(TEST_OBJECTS) $(UTIL_OBJECTS) | $(BINDIR)
	$(CXX) $(TEST_OBJECTS) $(UTIL_OBJECTS) -o $@

# Compilar arquivos objeto do src
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar arquivos objeto dos testes
$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(BINDIR):
	mkdir $(BINDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

# Limpar arquivos compilados
clean:
	if exist $(BUILDDIR) rmdir /s /q $(BUILDDIR)
	if exist $(BINDIR) rmdir /s /q $(BINDIR)

# Executar o programa principal
run: $(TARGET)
	$(TARGET)

# Executar os testes
test: $(TEST_TARGET)
	$(TEST_TARGET)

# Compilar e executar programa principal
build-run: all run

# Compilar e executar testes
build-test: test

.PHONY: all clean run test build-run build-test
