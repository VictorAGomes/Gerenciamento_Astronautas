#ifndef VOO_HPP
#define VOO_HPP

#include <vector>
#include "Astronauta.hpp"

class Voo {
private:
    int codigo;
    std::vector<Astronauta*> passageiros;
    bool emCurso;
    bool finalizado;
    bool sucesso;
    bool explodido;

public:
    Voo(int codigo);

    int getCodigo() const;
    const std::vector<Astronauta*>& getPassageiros() const;
    bool isEmCurso() const;
    bool isFinalizado() const;
    bool isSucesso() const;
    bool isExplodido() const;

    void adicionarPassageiro(Astronauta* astronauta);
    void removerPassageiro(const std::string& cpf);
    void lancar();
    void finalizar(bool sucesso);
    void explodir();

    static void cadastrarVoo(std::vector<Voo>& voos);
    static void listarVoos(const std::vector<Voo>& voos);
    static void adicionarAstronautaAoVoo(std::vector<Voo>& voos, std::vector<Astronauta>& astronautas);
    static void removerAstronautaDoVoo(std::vector<Voo>& voos);
    static void lancarVoo(std::vector<Voo>& voos);
    static void finalizarVoo(std::vector<Voo>& voos);
    static void explodirVoo(std::vector<Voo>& voos);
};

#endif // VOO_HPP
