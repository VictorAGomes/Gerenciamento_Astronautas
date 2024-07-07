#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>

class Astronauta {
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool disponivel;
    bool morto;

public:
    Astronauta(const std::string& cpf, const std::string& nome, int idade);

    std::string getCpf() const;
    std::string getNome() const;
    int getIdade() const;
    bool isDisponivel() const;
    bool isMorto() const;

    void setDisponivel(bool disponivel);
    void setMorto(bool morto);

    static bool isValidCpf(const std::string& cpf);
    static void addAstronauta(std::vector<Astronauta>& astronautas);
    static void listarAstronautasMortos(const std::vector<Astronauta>& astronautas);
};

#endif // ASTRONAUTA_HPP
