# Gerenciador de Voos Espaciais

Este é um sistema simples de gerenciamento de astronautas e voos espaciais, desenvolvido em C++. O sistema permite cadastrar astronautas e voos, adicionar e remover astronautas de voos, lançar, finalizar e explodir voos, e listar voos e astronautas mortos.

## Funcionalidades

- Cadastrar Astronauta
- Cadastrar Voo
- Adicionar Astronauta em um Voo
- Remover Astronauta de um Voo
- Lançar um Voo
- Finalizar um Voo
- Explodir um Voo
- Listar todos os Voos
- Listar todos os Astronautas Mortos

## Estrutura do Projeto

O projeto está dividido em três arquivos principais:

1. `main.cpp`: Contém a função `main` e o menu principal do sistema.
2. `Astronauta.hpp` e `Astronauta.cpp`: Definem a classe `Astronauta` e suas funcionalidades.
3. `Voo.hpp` e `Voo.cpp`: Definem a classe `Voo` e suas funcionalidades.

## Compilação e Execução

Para compilar e executar o projeto, siga os passos abaixo:

1. Certifique-se de que você tem um compilador C++ instalado (por exemplo, `g++`).
2. Navegue até o diretório onde os arquivos estão localizados.
3. Compile o projeto com o seguinte comando:
    ```sh
    g++ main.cpp astronauta.cpp voo.cpp -o gerenciador_voo
    ```
4. Execute o programa:
    ```sh
    ./gerenciador_voo
    ```

## Uso

Ao executar o programa, você verá o menu principal com as seguintes opções:

1. Cadastrar Astronauta
2. Cadastrar Voo
3. Adicionar Astronauta em um Voo
4. Remover Astronauta de um Voo
5. Lançar um Voo
6. Finalizar um Voo
7. Explodir um Voo
8. Listar todos os Voos
9. Listar todos os Astronautas Mortos
10. Fechar menu

Digite o número correspondente à opção desejada e siga as instruções fornecidas pelo sistema.

## Exemplo de Uso

1. Para cadastrar um astronauta, selecione a opção `1`, insira o CPF (11 dígitos), nome e idade.
2. Para cadastrar um voo, selecione a opção `2` e insira o código do voo.
3. Para adicionar um astronauta a um voo, selecione a opção `3`, insira o código do voo e o CPF do astronauta.
4. Para lançar um voo, selecione a opção `5` e insira o código do voo.
5. Para finalizar um voo, selecione a opção `6`, insira o código do voo e informe se o voo foi bem-sucedido.
6. Para explodir um voo, selecione a opção `7` e insira o código do voo.
7. Para listar todos os voos, selecione a opção `8`.
8. Para listar todos os astronautas mortos, selecione a opção `9`.
9. Para fechar o menu e encerrar o programa, selecione a opção `10`.

## Considerações Finais

Este projeto é um exemplo simples de como gerenciar dados e operações relacionadas a voos espaciais e astronautas em C++. Ele pode ser expandido com funcionalidades adicionais, como persistência de dados em um banco de dados ou arquivos, interface gráfica, entre outras melhorias.
