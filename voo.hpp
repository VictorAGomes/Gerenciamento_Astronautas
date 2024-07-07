#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>
#include "Astronauta.hpp"

class Voo {
private:
    int codigo;
    std::vector<Astronauta*> passageiros;
    bool emCurso;
    bool finalizado;
    bool sucesso;

public:
    Voo(int codigo);

    int getCodigo() const;
    void adicionarPassageiro(Astronauta* astronauta);
    bool removerPassageiroPorCpf(const std::string& cpf);

    void lancar();
    void finalizar(bool sucesso);
    void explodir();
    void imprimirInfo() const;

    static void cadastrarVoo(std::vector<Voo>& voos, int codigo);
    static void adicionarAstronautaAoVoo(std::vector<Voo>& voos, std::vector<Astronauta>& astronautas, const std::string& cpf, int codigo);
    static bool removerAstronautaDeVoo(std::vector<Voo>& voos, int codigo, const std::string& cpf);
    static void listarVoos(const std::vector<Voo>& voos);
};

#endif 
