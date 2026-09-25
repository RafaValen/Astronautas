#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Astronauta {
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:
    Astronauta(string cpf, string nome, int idade) 
        : cpf(cpf), nome(nome), idade(idade), vivo(true), disponivel(true) {}

    string getCpf() { return cpf; }
    string getNome() { return nome; }
    int getIdade() { return idade; }
    bool estaVivo() { return vivo; }
    bool estaDisponivel() { return disponivel; }

    void embarcar() { if (vivo) disponivel = false; }
    void desembarcar() { if (vivo) disponivel = true; }
    void morrer() { vivo = false; disponivel = false; }
};

class Voo {
private:
     int codigo;
     string estado;
     vector<string> cpfs;

public:
     Voo(int codigo) : codigo(codigo), estado("planejado"){}

     int getCodigo() { return codigo; }
     string getEstado() { return estado; }
     int getQuantidadeAstronautas() { return (int)cpfs.size(); }

     string getCpf(int posicao) {
        if (posicao >=0 && posicao < (int)cpfs.size()) return cpfs[posicao];
        return "";
     }

     bool temAstronauta(string cpf) {
        for (size_t i = 0; i < cpfs.size(); i++) {
            if (cpfs[i] == cpf) return true;
        }
        return false;
    }

    void adicionarAstronauta(string cpf) { cpfs.push_back(cpf); }
    bool removerAstronauta(string cpf) {
        for (size_t i = 0; i < cpfs.size(); i++) {
            if (cpfs[i] == cpf) {
                cpfs.erase(cpfs.begin() + i);
                return true;
            }
        }
        return false;
    }

    void lancar() { estado = "em curso"; }
    void explodir() { estado = "finalizado com explosao"; }
    void finalizar() { estado = "finalizado com sucesso"; }
};

class Agencia {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf) {
        for (size_t i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].getCpf() == cpf) return (int)i;
        }
        return -1;
    }

    int buscarVoo(int codigo) {
        for (size_t i = 0; i < voos.size(); i++) {
            if (voos[i].getCodigo() == codigo) return (int)i;
        }
        return -1;
    }

public:
    void cadastrarAstronauta(string cpf, string nome, int idade) {
        if (buscarAstronauta(cpf) != -1) {
            cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
            return;
        }
        astronautas.push_back(Astronauta(cpf, nome, idade));
        cout << "OK: astronauta " << cpf << " cadastrado" << endl;
    }

    void cadastrarVoo(int codigo) {
        if (buscarVoo(codigo) != -1) {
            cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            return;
        }
        voos.push_back(Voo(codigo));
        cout << "OK: voo " << codigo << " cadastrado" << endl;
    }

    void adicionarAstronauta(string cpf, int codigo) {
        int posA = buscarAstronauta(cpf);

    if (posA == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (!astronautas[posA].estaVivo()) {
        cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
        return;
    }

    if (voos[posV].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
        return;
    }

    voos[posV].adicionarAstronauta(cpf);
    cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
}
    

    void listarVoos() {
        cout << "LISTA DE VOOS" << endl;
        string estados[] = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

        for (int e = 0; e < 4; e++) {
            cout << "== " << estados[e] << " ==" << endl;
            bool encontrouVoo = false;

            for (size_t i = 0; i < voos.size(); i++) {
                if (voos[i].getEstado() == estados[e]) {
                    encontrouVoo = true;
                    cout << "Voo " << voos[i].getCodigo() << ": ";

                    if (voos[i].getQuantidadeAstronautas() == 0) {
                        cout << "sem astronautas" << endl;
                    } else {
                        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
                            string cpf = voos[i].getCpf(j);
                            int idxA = buscarAstronauta(cpf);
                            cout << cpf << " " << astronautas[idxA].getNome();
                            if (j < voos[i].getQuantidadeAstronautas() - 1) {
                                cout << ", ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
            if (!encontrouVoo) {

             cout << "(nenhum)" << endl;
            }
        }
    }

    void listarMortos() {
        cout << "ASTRONAUTAS MORTOS" << endl;
        bool encontrouMorto = false;

        for (size_t i = 0; i < astronautas.size(); i++) {
            if (!astronautas[i].estaVivo()) {
                encontrouMorto = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos:";

                vector<int> voosParticipou;
                for (size_t j = 0; j < voos.size(); j++) {
                    if (voos[j].getEstado() != "planejado" && voos[j].temAstronauta(astronautas[i].getCpf())) {
                        voosParticipou.push_back(voos[j].getCodigo());
                    }
                }

                if (voosParticipou.empty()) {
                    cout << " nenhum" << endl;
                } else {
                    for (size_t k = 0; k < voosParticipou.size(); k++){

                     cout << " " << voosParticipou[k];
                    }
                    cout << endl;
                }
            }
        }
        if (!encontrouMorto) {

         cout << "(nenhum)" << endl;
        }
    }
};

int main() {
    Agencia agencia;
    string comando;

    while (cin >> comando && comando != "FIM") { 
        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") { 
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
