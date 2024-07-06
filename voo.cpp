#include "Voo.hpp"
#include "Astronauta.hpp"

Voo::Voo(int codigo) : codigo(codigo), emCurso(false), finalizado(false), sucesso(false) {}

int Voo::getCodigo() const
{
    return codigo;
}

bool Voo::isEmCurso() const
{
    return emCurso;
}

bool Voo::isFinalizado() const
{
    return finalizado;
}

bool Voo::foiSucesso() const
{
    return sucesso;
}

void Voo::adicionarPassageiro(Astronauta *astronauta)
{
    passageiros.push_back(astronauta);
    astronauta->adicionarVoo(this);
}

bool Voo::removerPassageiro(const std::string &cpf)
{
    auto it = passageiros.begin();
    while (it != passageiros.end())
    {
        if ((*it)->getCPF() == cpf)
        {
            (*it)->removerVoo(this);
            it = passageiros.erase(it);
            return true;
        }
        else
        {
            ++it;
        }
    }
    return false;
}

void Voo::lancar()
{
    if (!emCurso && !finalizado && !passageiros.empty())
    {
        emCurso = true;
    }
}

void Voo::finalizar(bool sucesso)
{
    if (emCurso && !finalizado)
    {
        finalizado = true;
        emCurso = false;
        this->sucesso = sucesso;
        for (Astronauta *astronauta : passageiros)
        {
            astronauta->setDisponivel(sucesso); // Astronautas voltam a ficar disponíveis se o voo foi sucesso
        }
    }
}

void Voo::explodir()
{
    if (emCurso && !finalizado)
    {
        finalizado = true;
        emCurso = false;
        sucesso = false;
        for (Astronauta *astronauta : passageiros)
        {
            astronauta->setDisponivel(false); // Astronautas indisponíveis (mortos)
        }
    }
}

void Voo::imprimirInfo() const
{
    std::cout << "Código do voo: " << codigo << std::endl;
    std::cout << "Status: ";
    if (emCurso)
    {
        std::cout << "Em curso" << std::endl;
    }
    else if (finalizado)
    {
        std::cout << "Finalizado";
        if (sucesso)
        {
            std::cout << " (Sucesso)" << std::endl;
        }
        else
        {
            std::cout << " (Falha)" << std::endl;
        }
    }
    else
    {
        std::cout << "Planejado" << std::endl;
    }
    std::cout << "Passageiros:" << std::endl;
    for (Astronauta *astronauta : passageiros)
    {
        std::cout << "- CPF: " << astronauta->getCPF() << ", Nome: " << astronauta->getNome() << std::endl;
    }
}
