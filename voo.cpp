#include "Voo.hpp"
#include <iostream>
#include <algorithm>

Voo::Voo(int codigo) : codigo(codigo), emCurso(false), finalizado(false), sucesso(false) {}

int Voo::getCodigo() const {
    return codigo;
}

void Voo::adicionarPassageiro(Astronauta* astronauta) {
    passageiros.push_back(astronauta);
}

bool Voo::removerPassageiroPorCpf(const std::string& cpf) {
    auto it = std::find_if(passageiros.begin(), passageiros.end(), [&](Astronauta* a) { return a->getCpf() == cpf; });
    if (it != passageiros.end()) {
        passageiros.erase(it);
        return true;
    }
    return false;
}

void Voo::lancar() {
    if (passageiros.empty()) {
        std::cout << "O voo não pode ser lançado sem astronautas." << std::endl;
        return;
    }
    emCurso = true;
    for (auto& astronauta : passageiros) {
        astronauta->setDisponivel(false);
    }
}

void Voo::finalizar(bool sucesso) {
    this->sucesso = sucesso;
    finalizado = true;
    emCurso = false;
    for (auto& astronauta : passageiros) {
        astronauta->setDisponivel(true);
        if (!sucesso) {
            astronauta->setDisponivel(false); // Marca como morto
        }
    }
}

void Voo::explodir() {
    finalizar(false);
}

void Voo::imprimirInfo() const {
    std::cout << "Voo " << codigo << (finalizado ? (sucesso ? " [Finalizado com sucesso]" : " [Explodiu]") : (emCurso ? " [Em curso]" : " [Planejado]")) << std::endl;
    std::cout << "Passageiros:" << std::endl;
    for (const auto& astronauta : passageiros) {
        std::cout << " - " << astronauta->getNome() << " (" << astronauta->getCpf() << ")" << std::endl;
    }
}

void Voo::cadastrarVoo(std::vector<Voo>& voos, int codigo) {
    voos.push_back(Voo(codigo));
    std::cout << "Voo cadastrado com sucesso!" << std::endl;
}

void Voo::adicionarAstronautaAoVoo(std::vector<Voo>& voos, std::vector<Astronauta>& astronautas, const std::string& cpf, int codigo) {
    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo && !voo.emCurso && !voo.finalizado) {
            for (auto& astronauta : astronautas) {
                if (astronauta.getCpf() == cpf && astronauta.isDisponivel()) {
                    voo.adicionarPassageiro(&astronauta);
                    std::cout << "Astronauta adicionado ao voo." << std::endl;
                    return;
                }
            }
            std::cout << "Astronauta não encontrado ou indisponível." << std::endl;
            return;
        }
    }
    std::cout << "Voo não encontrado ou não está em planejamento." << std::endl;
}

bool Voo::removerAstronautaDeVoo(std::vector<Voo>& voos, int codigo, const std::string& cpf) {
    for (auto& voo : voos) {
        if (voo.getCodigo() == codigo) {
            return voo.removerPassageiroPorCpf(cpf);
        }
    }
    return false;
}

void Voo::listarVoos(const std::vector<Voo>& voos) {
    std::cout << "------ Lista de Voos ------" << std::endl;
    for (const auto& voo : voos) {
        voo.imprimirInfo();
        std::cout << std::endl;
    }
}
