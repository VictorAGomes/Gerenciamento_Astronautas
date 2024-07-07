#include "Astronauta.hpp"
#include "Voo.hpp"
#include <algorithm>

Astronauta::Astronauta(const std::string& cpf, const std::string& nome, int idade) 
    : cpf(cpf), nome(nome), idade(idade), disponivel(true) {}

std::string Astronauta::getCpf() const {
    return cpf;
}

std::string Astronauta::getNome() const {
    return nome;
}

int Astronauta::getIdade() const {
    return idade;
}

bool Astronauta::isDisponivel() const {
    return disponivel;
}

void Astronauta::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

void Astronauta::adicionarVoo(std::shared_ptr<Voo> voo) {
    voosParticipados.push_back(voo);
}

void Astronauta::removerVoo(std::shared_ptr<Voo> voo) {
    auto it = std::find(voosParticipados.begin(), voosParticipados.end(), voo);
    if (it != voosParticipados.end()) {
        voosParticipados.erase(it);
    }
}

void Astronauta::morrer() {
    disponivel = false;
}
