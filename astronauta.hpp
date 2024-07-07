#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>
#include <memory>

class Voo;

class Astronauta : public std::enable_shared_from_this<Astronauta> {
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool disponivel;
    std::vector<std::shared_ptr<Voo>> voosParticipados;

public:
    Astronauta(const std::string& cpf, const std::string& nome, int idade);

    std::string getCpf() const;
    std::string getNome() const;
    int getIdade() const;
    bool isDisponivel() const;

    void setDisponivel(bool disponivel);
    void adicionarVoo(std::shared_ptr<Voo> voo);
    void removerVoo(std::shared_ptr<Voo> voo);
    void morrer();
};

#endif // ASTRONAUTA_HPP
