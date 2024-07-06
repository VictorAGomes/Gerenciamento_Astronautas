#include "Astronauta.hpp"
#include <algorithm>

Astronauta::Astronauta(const std::string &cpf, const std::string &nome, int idade)
    : cpf(cpf), nome(nome), idade(idade), disponivel(true) {}

const std::string &Astronauta::getCPF() const
{
    return cpf;
}

const std::string &Astronauta::getNome() const
{
    return nome;
}

int Astronauta::getIdade() const
{
    return idade;
}

bool Astronauta::isDisponivel() const
{
    return disponivel;
}

void Astronauta::setDisponivel(bool disponivel)
{
    this->disponivel = disponivel;
}

void Astronauta::adicionarVoo(Voo *voo)
{
    voosParticipados.push_back(voo);
}

void Astronauta::removerVoo(Voo *voo)
{
    auto it = std::find(voosParticipados.begin(), voosParticipados.end(), voo);
    if (it != voosParticipados.end())
    {
        voosParticipados.erase(it);
    }
}

void Astronauta::imprimirInfo() const
{
    std::cout << "CPF: " << cpf << ", Nome: " << nome << ", Idade: " << idade << std::endl;
    std::cout << "Voos participados:" << std::endl;
    for (Voo *voo : voosParticipados)
    {
        std::cout << "- Código do voo: " << voo->getCodigo() << std::endl;
    }
}

const std::vector<Voo *> &Astronauta::getVoosParticipados() const
{
    return voosParticipados;
}
