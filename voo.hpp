#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>
#include <memory>
#include "Astronauta.hpp"

class Voo : public std::enable_shared_from_this<Voo> {
private:
    int codigo;
    std::vector<std::shared_ptr<Astronauta>> passageiros;
    bool emCurso;
    bool finalizado;
    bool sucesso;

public:
    Voo(int codigo);

    int getCodigo() const;
    void adicionarPassageiro(std::shared_ptr<Astronauta> astronauta);
    bool removerPassageiroPorCpf(const std::string& cpf);

    void lancar();
    void finalizar(bool sucesso);
    void explodir();
    void imprimirInfo() const;

    static void cadastrarVoo(std::vector<std::shared_ptr<Voo>>& voos, int codigo);
    static void adicionarAstronautaAoVoo(std::vector<std::shared_ptr<Voo>>& voos, std::vector<std::shared_ptr<Astronauta>>& astronautas, const std::string& cpf, int codigo);
    static bool removerAstronautaDeVoo(std::vector<std::shared_ptr<Voo>>& voos, int codigo, const std::string& cpf);
    static void listarVoos(const std::vector<std::shared_ptr<Voo>>& voos);
};

#endif // VOO_HPP
