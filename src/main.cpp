#include <iostream>
#include <fstream>
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
    void definirEstado(bool novoVivo, bool novoDisponivel) {
        vivo = novoVivo;
        disponivel = novoDisponivel;
    }
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
    void definirEstado(string novoEstado) { estado = novoEstado; }
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

    void embarcarAstronautasDoVoo(int posV) {
        for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posV].getCpf(i);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].embarcar();
        }
    }

    void desembarcarAstronautasDoVoo(int posV) {
        for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posV].getCpf(i);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].desembarcar();
        }
    }

    void matarAstronautasDoVoo(int posV) {
        for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posV].getCpf(i);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].morrer();
        }
    }

    int buscarVooEmCursoDoAstronauta(string cpf) {
        for (size_t i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() == "em curso" && voos[i].temAstronauta(cpf)) {
                return (int)i;
            }
        }
        return -1;
    }

    int contarVoosLancadosDoAstronauta(string cpf) {
        int quantidade = 0;

        for (size_t i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() != "planejado" && voos[i].temAstronauta(cpf)) {
                quantidade++;
            }
        }

        return quantidade;
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
    void removerAstronauta(string cpf, int codigo) {
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

    if (!voos[posV].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
        return;
    }

    voos[posV].removerAstronauta(cpf);
    cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
}
    void lancarVoo(int codigo) {
    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (voos[posV].getQuantidadeAstronautas() == 0) {
        cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
        return;
    }

    for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {
        string cpf = voos[posV].getCpf(i);
        int posA = buscarAstronauta(cpf);

        if (!astronautas[posA].estaVivo()) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }

        if (!astronautas[posA].estaDisponivel()) {
            cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
            return;
        }
    }

    embarcarAstronautasDoVoo(posV);
    
    voos[posV].lancar();
    cout << "OK: voo " << codigo << " lancado" << endl;
}
    void finalizarVoo(int codigo) {
    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    desembarcarAstronautasDoVoo(posV);

    voos[posV].finalizar();
    cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
}
    void explodirVoo(int codigo) {
    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    matarAstronautasDoVoo(posV);

    voos[posV].explodir();
    cout << "OK: voo " << codigo << " explodiu" << endl;
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

    void listarAstronautas() {
        cout << "LISTA DE ASTRONAUTAS" << endl;

        cout << "== disponiveis ==" << endl;
        bool encontrouDisponivel = false;
        for (size_t i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].estaVivo() && buscarVooEmCursoDoAstronauta(astronautas[i].getCpf()) == -1) {
                encontrouDisponivel = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)" << endl;
            }
        }
        if (!encontrouDisponivel) {
            cout << "(nenhum)" << endl;
        }

        cout << "== em voo ==" << endl;
        bool encontrouEmVoo = false;
        for (size_t i = 0; i < astronautas.size(); i++) {
            int posV = buscarVooEmCursoDoAstronauta(astronautas[i].getCpf());
            if (astronautas[i].estaVivo() && posV != -1) {
                encontrouEmVoo = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos) - voo "
                     << voos[posV].getCodigo() << endl;
            }
        }
        if (!encontrouEmVoo) {
            cout << "(nenhum)" << endl;
        }

        cout << "== mortos ==" << endl;
        bool encontrouMorto = false;
        for (size_t i = 0; i < astronautas.size(); i++) {
            if (!astronautas[i].estaVivo()) {
                encontrouMorto = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)" << endl;
            }
        }
        if (!encontrouMorto) {
            cout << "(nenhum)" << endl;
        }
    }

    void buscarAstronautaPorCpf(string cpf) {
        int posA = buscarAstronauta(cpf);

        if (posA == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        cout << "BUSCA DE ASTRONAUTA" << endl;
        cout << astronautas[posA].getCpf() << " " << astronautas[posA].getNome()
             << " (" << astronautas[posA].getIdade() << " anos) - ";

        if (!astronautas[posA].estaVivo()) {
            cout << "morto" << endl;
        } else if (buscarVooEmCursoDoAstronauta(cpf) != -1) {
            cout << "vivo, em voo" << endl;
        } else {
            cout << "vivo, disponivel" << endl;
        }
    }

    void historico(string cpf) {
        int posA = buscarAstronauta(cpf);

        if (posA == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        cout << "HISTORICO DE " << cpf << " " << astronautas[posA].getNome() << endl;
        bool encontrouVoo = false;

        for (size_t i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() != "planejado" && voos[i].temAstronauta(cpf)) {
                encontrouVoo = true;
                cout << "voo " << voos[i].getCodigo() << ": " << voos[i].getEstado() << endl;
            }
        }

        if (!encontrouVoo) {
            cout << "(nenhum voo)" << endl;
        }
    }

    void salvar(string nomeArquivo) {
        ofstream arquivo(nomeArquivo.c_str());

        if (!arquivo) {
            cout << "ERRO: nao foi possivel salvar em " << nomeArquivo << endl;
            return;
        }

        arquivo << "ASTRONAUTAS " << astronautas.size() << endl;
        for (size_t i = 0; i < astronautas.size(); i++) {
            arquivo << astronautas[i].getCpf() << endl;
            arquivo << astronautas[i].getIdade() << endl;
            arquivo << astronautas[i].estaVivo() << endl;
            arquivo << astronautas[i].estaDisponivel() << endl;
            arquivo << astronautas[i].getNome() << endl;
        }

        arquivo << "VOOS " << voos.size() << endl;
        for (size_t i = 0; i < voos.size(); i++) {
            arquivo << voos[i].getCodigo() << endl;
            arquivo << voos[i].getEstado() << endl;
            arquivo << voos[i].getQuantidadeAstronautas() << endl;
            for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
                arquivo << voos[i].getCpf(j) << endl;
            }
        }

        cout << "OK: dados salvos em " << nomeArquivo << endl;
    }

    void carregar(string nomeArquivo) {
        ifstream arquivo(nomeArquivo.c_str());

        if (!arquivo) {
            cout << "ERRO: nao foi possivel carregar de " << nomeArquivo << endl;
            return;
        }

        vector<Astronauta> novosAstronautas;
        vector<Voo> novosVoos;

        string palavra;
        int quantidadeAstronautas;
        arquivo >> palavra >> quantidadeAstronautas;

        for (int i = 0; i < quantidadeAstronautas; i++) {
            string cpf, nome;
            int idade;
            int vivo;
            int disponivel;

            arquivo >> cpf;
            arquivo >> idade;
            arquivo >> vivo;
            arquivo >> disponivel;
            getline(arquivo >> ws, nome);

            Astronauta astronauta(cpf, nome, idade);
            astronauta.definirEstado(vivo == 1, disponivel == 1);
            novosAstronautas.push_back(astronauta);
        }

        int quantidadeVoos;
        arquivo >> palavra >> quantidadeVoos;

        for (int i = 0; i < quantidadeVoos; i++) {
            int codigo;
            string estado;
            int quantidadeCpfs;

            arquivo >> codigo;
            getline(arquivo >> ws, estado);
            arquivo >> quantidadeCpfs;

            Voo voo(codigo);
            voo.definirEstado(estado);

            for (int j = 0; j < quantidadeCpfs; j++) {
                string cpf;
                arquivo >> cpf;
                voo.adicionarAstronauta(cpf);
            }

            novosVoos.push_back(voo);
        }

        astronautas = novosAstronautas;
        voos = novosVoos;

        cout << "OK: dados carregados de " << nomeArquivo << endl;
    }

    void relatorio() {
        int planejados = 0;
        int emCurso = 0;
        int finalizadosComSucesso = 0;
        int finalizadosComExplosao = 0;

        for (size_t i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() == "planejado") {
                planejados++;
            } else if (voos[i].getEstado() == "em curso") {
                emCurso++;
            } else if (voos[i].getEstado() == "finalizado com sucesso") {
                finalizadosComSucesso++;
            } else if (voos[i].getEstado() == "finalizado com explosao") {
                finalizadosComExplosao++;
            }
        }

        int vivos = 0;
        int mortos = 0;

        for (size_t i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].estaVivo()) {
                vivos++;
            } else {
                mortos++;
            }
        }

        int posMaisExperiente = -1;
        int maiorExperiencia = 0;

        for (size_t i = 0; i < astronautas.size(); i++) {
            int experiencia = contarVoosLancadosDoAstronauta(astronautas[i].getCpf());

            if (experiencia > maiorExperiencia) {
                maiorExperiencia = experiencia;
                posMaisExperiente = (int)i;
            }
        }

        int finalizados = finalizadosComSucesso + finalizadosComExplosao;

        cout << "RELATORIO" << endl;
        cout << "voos planejados: " << planejados << endl;
        cout << "voos em curso: " << emCurso << endl;
        cout << "voos finalizados com sucesso: " << finalizadosComSucesso << endl;
        cout << "voos finalizados com explosao: " << finalizadosComExplosao << endl;
        cout << "astronautas cadastrados: " << astronautas.size() << endl;
        cout << "astronautas vivos: " << vivos << endl;
        cout << "astronautas mortos: " << mortos << endl;

        if (posMaisExperiente == -1) {
            cout << "astronauta mais experiente: (nenhum)" << endl;
        } else {
            cout << "astronauta mais experiente: "
                 << astronautas[posMaisExperiente].getCpf() << " "
                 << astronautas[posMaisExperiente].getNome()
                 << " (voos lancados: " << maiorExperiencia << ")" << endl;
        }

        if (finalizados == 0) {
            cout << "taxa de sucesso: (nenhum voo finalizado)" << endl;
        } else {
            cout << "taxa de sucesso: " << finalizadosComSucesso * 100 / finalizados << "%" << endl;
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
            agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else if (comando == "LISTAR_ASTRONAUTAS") {
            agencia.listarAstronautas();
        } else if (comando == "BUSCAR_ASTRONAUTA") {
            string cpf;
            cin >> cpf;
            agencia.buscarAstronautaPorCpf(cpf);
        } else if (comando == "HISTORICO") {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        } else if (comando == "SALVAR") {
            string nomeArquivo;
            cin >> nomeArquivo;
            agencia.salvar(nomeArquivo);
        } else if (comando == "CARREGAR") {
            string nomeArquivo;
            cin >> nomeArquivo;
            agencia.carregar(nomeArquivo);
        } else if (comando == "RELATORIO") {
            agencia.relatorio();
        }
         else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
