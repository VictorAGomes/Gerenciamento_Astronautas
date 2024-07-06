#include <iostream>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"
#include <algorithm>

int main()
{
    std::vector<Astronauta *> astronautas;
    std::vector<Voo *> voos;

    int escolha;

    std::cout << "Bem-vindo ao Gerenciador de Voos Espaciais" << std::endl;
    std::cout << "-------- Menu --------" << std::endl;
    std::cout << "1 - Cadastrar Astronauta" << std::endl;
    std::cout << "2 - Cadastrar Voo" << std::endl;
    std::cout << "3 - Adicionar Astronauta em Voo" << std::endl;
    std::cout << "4 - Remover Astronauta de Voo" << std::endl;
    std::cout << "5 - Lançar Voo" << std::endl;
    std::cout << "6 - Finalizar Voo" << std::endl;
    std::cout << "7 - Explodir Voo" << std::endl;
    std::cout << "8 - Listar Astronautas Mortos" << std::endl;
    std::cout << "9 - Listar Voos" << std::endl;
    std::cout << "10 - Sair" << std::endl;

    while (true)
    {
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            std::string cpf, nome;
            int idade;
            std::cout << "CPF do astronauta: ";
            std::cin >> cpf;
            std::cout << "Nome do astronauta: ";
            std::cin >> nome;
            std::cout << "Idade do astronauta: ";
            std::cin >> idade;
            astronautas.push_back(new Astronauta(cpf, nome, idade));
            std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
            break;
        }
        case 2:
        {
            int codigo;
            std::cout << "Código do voo: ";
            std::cin >> codigo;
            voos.push_back(new Voo(codigo));
            std::cout << "Voo cadastrado com sucesso!" << std::endl;
            break;
        }
        case 3:
        {
            std::string cpf;
            int codigo;
            std::cout << "CPF do astronauta: ";
            std::cin >> cpf;
            std::cout << "Código do voo: ";
            std::cin >> codigo;

            Astronauta *astronauta = nullptr;
            for (Astronauta *ast : astronautas)
            {
                if (ast->getCPF() == cpf)
                {
                    astronauta = ast;
                    break;
                }
            }

            if (astronauta == nullptr)
            {
                std::cout << "Astronauta não encontrado." << std::endl;
            }
            else
            {
                for (Voo *voo : voos)
                {
                    if (voo->getCodigo() == codigo)
                    {
                        voo->adicionarPassageiro(astronauta);
                        std::cout << "Astronauta adicionado ao voo." << std::endl;
                        break;
                    }
                }
            }
            break;
        }
        case 4:
        {
            std::string cpf;
            int codigo;
            std::cout << "CPF do astronauta: ";
            std::cin >> cpf;
            std::cout << "Código do voo: ";
            std::cin >> codigo;

            bool removido = false;
            for (Voo *voo : voos)
            {
                if (voo->getCodigo() == codigo)
                {
                    removido = voo->removerPassageiro(cpf);
                    if (removido)
                    {
                        std::cout << "Astronauta removido do voo." << std::endl;
                    }
                    else
                    {
                        std::cout << "Astronauta não encontrado no voo." << std::endl;
                    }
                    break;
                }
            }

            if (!removido)
            {
                std::cout << "Voo não encontrado." << std::endl;
            }
            break;
        }
        case 5:
        {
            int codigo;
            std::cout << "Código do voo: ";
            std::cin >> codigo;

            for (Voo *voo : voos)
            {
                if (voo->getCodigo() == codigo)
                {
                    voo->lancar();
                    std::cout << "Voo lançado com sucesso!" << std::endl;
                    break;
                }
            }
            break;
        }
        case 6:
        {
            int codigo;
            std::cout << "Código do voo: ";
            std::cin >> codigo;

            for (Voo *voo : voos)
            {
                if (voo->getCodigo() == codigo)
                {
                    voo->finalizar(true);
                    std::cout << "Voo finalizado com sucesso!" << std::endl;
                    break;
                }
            }
            break;
        }
        case 7:
        {
            int codigo;
            std::cout << "Código do voo: ";
            std::cin >> codigo;

            for (Voo *voo : voos)
            {
                if (voo->getCodigo() == codigo)
                {
                    voo->explodir();
                    std::cout << "Voo explodiu!" << std::endl;
                    break;
                }
            }
            break;
        }
        case 8:
        {
            std::cout << "------ Astronautas Mortos ------" << std::endl;
            for (Astronauta *astronauta : astronautas)
            {
                if (!astronauta->isDisponivel())
                {
                    std::cout << "CPF: " << astronauta->getCPF() << ", Nome: " << astronauta->getNome() << std::endl;
                    std::cout << "Voos que participou:" << std::endl;
                    for (Voo *voo : astronauta->getVoosParticipados())
                    {
                        std::cout << "- Código do voo: " << voo->getCodigo() << std::endl;
                    }
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 9:
        {
            std::cout << "------ Lista de Voos ------" << std::endl;
            for (Voo *voo : voos)
            {
                voo->imprimirInfo();
                std::cout << std::endl;
            }
            break;
        }
        case 10:
        {
            std::cout << "Encerrando o programa..." << std::endl;
            for (Astronauta *astronauta : astronautas)
            {
                delete astronauta;
            }
            for (Voo *voo : voos)
            {
                delete voo;
            }
            return 0;
        }
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
        }
    }

    return 0;
}
