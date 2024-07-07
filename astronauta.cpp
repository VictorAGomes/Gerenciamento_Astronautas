#include "Astronauta.hpp"
#include <iostream>
#include <regex>

// Construtor
Astronauta::Astronauta(const std::string& cpf, const std::string& nome, int idade)
    : cpf(cpf), nome(nome), idade(idade), disponivel(true), morto(false) {}

// Métodos getter
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

bool Astronauta::isMorto() const {
    return morto;
}

// Métodos setter
void Astronauta::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

void Astronauta::setMorto(bool morto) {
    this->morto = morto;
}

// Valida CPF (deve ter 11 dígitos e ser numérico)
bool Astronauta::isValidCpf(const std::string& cpf) {
    std::regex cpfPattern("^[0-9]{11}$");
    return std::regex_match(cpf, cpfPattern);
}

// Adiciona um novo astronauta
void Astronauta::addAstronauta(std::vector<Astronauta>& astronautas) {
    std::string cpf, nome;
    int idade;
    std::cout << "CPF: ";
    std::cin >> cpf;
    if (!Astronauta::isValidCpf(cpf)) {
        std::cout << "CPF inválido. Deve conter 11 dígitos numéricos." << std::endl;
        return;
    }
    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Idade: ";
    std::cin >> idade;
    astronautas.emplace_back(cpf, nome, idade);
    std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
}

// Lista todos os astronautas mortos
void Astronauta::listarAstronautasMortos(const std::vector<Astronauta>& astronautas) {
    std::cout << "------ Lista de Astronautas Mortos ------" << std::endl;
    for (const auto& astronauta : astronautas) {
        if (astronauta.isMorto()) {
            std::cout << "Nome: " << astronauta.getNome() << ", CPF: " << astronauta.getCpf() << ", Idade: " << astronauta.getIdade() << std::endl;
        }
    }
}
