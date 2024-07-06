#ifndef VOO_HPP
#define VOO_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Astronauta.hpp" // Inclui a declaração antecipada da classe Astronauta

class Astronauta; // Declaração antecipada da classe Astronauta

class Voo
{
private:
    int codigo;
    bool emCurso;
    bool finalizado;
    bool sucesso;
    std::vector<Astronauta *> passageiros;

public:
    Voo(int codigo);

    int getCodigo() const;
    bool isEmCurso() const;
    bool isFinalizado() const;
    bool foiSucesso() const;
    void adicionarPassageiro(Astronauta *astronauta);
    bool removerPassageiro(const std::string &cpf);
    void lancar();
    void finalizar(bool sucesso);
    void explodir();
    void imprimirInfo() const;
};

#endif // VOO_HPP
