#include "Voo.hpp"
#include <iostream>

// Construtor
Voo::Voo(int codigo)
    : codigo(codigo), emCurso(false), finalizado(false), sucesso(false), explodido(false) {}

// Métodos getter
int Voo::getCodigo() const {
    return codigo;
}

const std::vector<Astronauta*>& Voo::getPassageiros() const {
    return passageiros;
}

bool Voo::isEmCurso() const {
    return emCurso;
}

bool Voo::isFinalizado() const {
    return finalizado;
}

bool Voo::isSucesso() const {
    return sucesso;
}

bool Voo::isExplodido() const {
    return explodido;
}

// Adiciona um passageiro ao voo
void Voo::adicionarPassageiro(Astronauta* astronauta) {
    passageiros.push_back(astronauta);
}

// Remove um passageiro do voo
void Voo::removerPassageiro(const std::string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if ((*it)->getCpf() == cpf) {
            passageiros.erase(it);
            return;
        }
    }
}

// Lança o voo
void Voo::lancar() {
    if (passageiros.empty()) {
        std::cout << "O voo não pode ser lançado sem passageiros." << std::endl;
        return;
    }
    emCurso = true;
    for (auto& passageiro : passageiros) {
        passageiro->setDisponivel(false);
    }
    std::cout << "Voo lançado!" << std::endl;
}

// Finaliza o voo
void Voo::finalizar(bool sucesso) {
    if (!emCurso) {
        std::cout << "O voo não está em curso." << std::endl;
        return;
    }
    emCurso = false;
    finalizado = true;
    this->sucesso = sucesso;
    for (auto& passageiro : passageiros) {
        passageiro->setDisponivel(true);
    }
    std::cout << (sucesso ? "Voo finalizado com sucesso!" : "Voo finalizado sem sucesso!") << std::endl;
}

// Explode o voo
void Voo::explodir() {
    if (!emCurso) {
        std::cout << "O voo não está em curso." << std::endl;
        return;
    }
    emCurso = false;
    finalizado = true;
    sucesso = false;
    explodido = true;
    for (auto& passageiro : passageiros) {
        passageiro->setMorto(true);
    }
    std::cout << "O voo explodiu!" << std::endl;
}

// Cadastra um novo voo
void Voo::cadastrarVoo(std::vector<Voo>& voos) {
    int codigo;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;
    voos.emplace_back(codigo);
    std::cout << "Voo cadastrado com sucesso!" << std::endl;
}

// Lista todos os voos
void Voo::listarVoos(const std::vector<Voo>& voos) {
    std::cout << "------ Lista de Voos ------" << std::endl;
    for (const auto& voo : voos) {
        std::cout << "Código: " << voo.getCodigo()
                  << ", Status: " << (voo.isEmCurso() ? "Em curso" : (voo.isFinalizado() ? (voo.isSucesso() ? "Finalizado com sucesso" : (voo.isExplodido() ? "Explodido" : "Finalizado sem sucesso")) : "Planejado")) 
                  << std::endl;
        if (voo.isFinalizado() && voo.isExplodido()) {
            std::cout << "Passageiros (mortos): ";
            for (const auto& passageiro : voo.getPassageiros()) {
                std::cout << passageiro->getNome() << " ";
            }
            std::cout << std::endl;
        } else if (!voo.isFinalizado() || voo.isSucesso()) {
            std::cout << "Passageiros: ";
            for (const auto& passageiro : voo.getPassageiros()) {
                std::cout << passageiro->getNome() << " ";
            }
            std::cout << std::endl;
        }
    }
}

// Adiciona um astronauta ao voo
void Voo::adicionarAstronautaAoVoo(std::vector<Voo>& voos, std::vector<Astronauta>& astronautas) {
    int codigo;
    std::string cpf;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;
    std::cout << "CPF do Astronauta: ";
    std::cin >> cpf;

    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            for (auto& astronauta : astronautas) {
                if (astronauta.getCpf() == cpf && astronauta.isDisponivel()) {
                    voo.adicionarPassageiro(&astronauta);
                    std::cout << "Astronauta adicionado ao voo com sucesso!" << std::endl;
                    return;
                }
            }
            std::cout << "Astronauta não encontrado ou indisponível." << std::endl;
            return;
        }
    }
    std::cout << "Voo não encontrado." << std::endl;
}

// Remove um astronauta do voo
void Voo::removerAstronautaDoVoo(std::vector<Voo>& voos) {
    int codigo;
    std::string cpf;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;
    std::cout << "CPF do Astronauta: ";
    std::cin >> cpf;

    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            voo.removerPassageiro(cpf);
            std::cout << "Astronauta removido do voo com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Voo não encontrado." << std::endl;
}

// Lança um voo
void Voo::lancarVoo(std::vector<Voo>& voos) {
    int codigo;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;

    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            voo.lancar();
            return;
        }
    }
    std::cout << "Voo não encontrado." << std::endl;
}

// Finaliza um voo
void Voo::finalizarVoo(std::vector<Voo>& voos) {
    int codigo;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;

    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            bool sucesso;
            std::cout << "O voo foi bem sucedido? (1 para sim, 0 para não): ";
            std::cin >> sucesso;
            voo.finalizar(sucesso);
            return;
        }
    }
    std::cout << "Voo não encontrado." << std::endl;
}

// Explode um voo
void Voo::explodirVoo(std::vector<Voo>& voos) {
    int codigo;
    std::cout << "Código do Voo: ";
    std::cin >> codigo;

    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            voo.explodir();
            return;
        }
    }
    std::cout << "Voo não encontrado." << std::endl;
}
