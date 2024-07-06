#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Voo.hpp" // Inclui a declaração antecipada da classe Voo

class Voo; // Declaração antecipada da classe Voo

class Astronauta
{
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool disponivel;
    std::vector<Voo *> voosParticipados;

public:
    Astronauta(const std::string &cpf, const std::string &nome, int idade);

    const std::string &getCPF() const;
    const std::string &getNome() const;
    int getIdade() const;
    bool isDisponivel() const;
    void setDisponivel(bool disponivel);
    void adicionarVoo(Voo *voo);
    void removerVoo(Voo *voo);
    void imprimirInfo() const;
    const std::vector<Voo *> &getVoosParticipados() const;
};

#endif // ASTRONAUTA_HPP
