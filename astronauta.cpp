#include "Astronauta.hpp"

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
