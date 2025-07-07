cmake_minimum_required(VERSION 3.10)
project(AED)

# Definir o padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adicionar flags de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Incluir diretórios de headers
include_directories(include)

# Encontrar todos os arquivos fonte
file(GLOB SOURCES "src/*.cpp")

# Criar o executável
add_executable(main ${SOURCES})

# Definir diretório de saída
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
