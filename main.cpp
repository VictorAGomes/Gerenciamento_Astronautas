#include <iostream>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"

int main() {
    std::vector<Astronauta> astronautas;
    std::vector<Voo> voos;

    int choose;

    std::cout << "Bem-vindo ao Gerenciador de Voo" << '\n';
    std::cout << "--------Menu---------" << '\n';
    std::cout << "1- Cadastrar Astronauta" << '\n';
    std::cout << "2- Cadastrar Voo" << '\n';
    std::cout << "3- Adicionar Astronauta em um voo" << '\n';
    std::cout << "4- Remover Astronauta de um voo" << '\n';
    std::cout << "5- Lançar um voo" << '\n';
    std::cout << "6- Finalizar um voo" << '\n';
    std::cout << "7- Explodir um voo" << '\n';
    std::cout << "8- Listar todos os Astronautas mortos" << '\n';
    std::cout << "9- Listar todos os voos" << '\n';
    std::cout << "10- Fechar menu" << '\n';

    while (true) {
        std::cout << "Escolha uma opção: ";
        std::cin >> choose;

        switch (choose) {
            case 1: {
                std::string cpf, nome;
                int idade;
                std::cout << "CPF: ";
                std::cin >> cpf;
                std::cout << "Nome: ";
                std::cin >> nome;
                std::cout << "Idade: ";
                std::cin >> idade;
                astronautas.emplace_back(cpf, nome, idade);
                std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
                break;
            }
            case 2: {
                int codigo;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                Voo::cadastrarVoo(voos, codigo);
                break;
            }
            case 3: {
                std::string cpf;
                int codigo;
                std::cout << "CPF do astronauta: ";
                std::cin >> cpf;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                Voo::adicionarAstronautaAoVoo(voos, astronautas, cpf, codigo);
                break;
            }
            case 4: {
                std::string cpf;
                int codigo;
                std::cout << "CPF do astronauta: ";
                std::cin >> cpf;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                if (Voo::removerAstronautaDeVoo(voos, codigo, cpf)) {
                    std::cout << "Astronauta removido do voo." << std::endl;
                } else {
                    std::cout << "Astronauta não encontrado no voo." << std::endl;
                }
                break;
            }
            case 5: {
                int codigo;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == codigo) {
                        voo.lancar();
                        std::cout << "Voo lançado com sucesso!" << std::endl;
                        break;
                    }
                }
                break;
            }
            case 6: {
                int codigo;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == codigo) {
                        voo.finalizar(true); // Supondo sucesso por padrão
                        std::cout << "Voo finalizado com sucesso!" << std::endl;
                        break;
                    }
                }
                break;
            }
            case 7: {
                int codigo;
                std::cout << "Código do voo: ";
                std::cin >> codigo;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == codigo) {
                        voo.explodir();
                        std::cout << "Voo explodiu!" << std::endl;
                        break;
                    }
                }
                break;
            }
            case 8: {
                std::cout << "------ Astronautas Mortos ------" << std::endl;
                for (const auto& astronauta : astronautas) {
                    if (!astronauta.isDisponivel()) {
                        std::cout << astronauta.getNome() << " (" << astronauta.getCpf() << ")" << std::endl;
                    }
                }
                break;
            }
            case 9: {
                Voo::listarVoos(voos);
                break;
            }
            case 10:
                std::cout << "Menu finalizado" << '\n';
                return 0;
            default:
                std::cout << "Opção inválida" << '\n';
                break;
        }
    }
}