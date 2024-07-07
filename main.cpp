#include <iostream>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"

int main() {
    std::vector<Astronauta> astronautas;
    std::vector<Voo> voos;

    int escolha;

    std::cout << "Bem-vindo ao Gerenciador de Voo" << '\n';
    std::cout << "--------Menu---------" << '\n';
    std::cout << "1- Cadastrar Astronauta" << '\n';
    std::cout << "2- Cadastrar Voo" << '\n';
    std::cout << "3- Adicionar Astronauta em um voo" << '\n';
    std::cout << "4- Remover Astronauta de um voo" << '\n';
    std::cout << "5- Lançar um voo" << '\n';
    std::cout << "6- Finalizar um voo" << '\n';
    std::cout << "7- Explodir um voo" << '\n';
    std::cout << "8- Listar todos os voos" << '\n';
    std::cout << "9- Listar todos os Astronautas mortos" << '\n';
    std::cout << "10- Fechar menu" << '\n';

    while (true) {
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        switch (escolha) {
            case 1:
                Astronauta::addAstronauta(astronautas);
                break;
            case 2:
                Voo::cadastrarVoo(voos);
                break;
            case 3:
                Voo::adicionarAstronautaAoVoo(voos, astronautas);
                break;
            case 4:
                Voo::removerAstronautaDoVoo(voos);
                break;
            case 5:
                Voo::lancarVoo(voos);
                break;
            case 6:
                Voo::finalizarVoo(voos);
                break;
            case 7:
                Voo::explodirVoo(voos);
                break;
            case 8:
                Voo::listarVoos(voos);
                break;
            case 9:
                Astronauta::listarAstronautasMortos(astronautas);
                break;
            case 10:
                std::cout << "Menu finalizado" << '\n';
                return 0;
            default:
                std::cout << "Opção inválida" << '\n';
                break;
        }
    }

    return 0;
}
