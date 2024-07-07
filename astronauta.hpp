#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>

class Voo;

class Astronauta {
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool disponivel;

public:
    Astronauta(const std::string& cpf, const std::string& nome, int idade);

    std::string getCpf() const;
    std::string getNome() const;
    int getIdade() const;
    bool isDisponivel() const;

    void setDisponivel(bool disponivel);
};

#endif
