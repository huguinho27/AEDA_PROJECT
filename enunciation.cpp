#ifndef ENUNCIADO_H
#define ENUNCIADO_H

using namespace std;

#include <iostream>

class Enunciado
{
protected:
	string titulo, descricao;
	vector<string> anosLetivosProposto;
	vector<Estudante> estudantesEnvolvidos;
public:
	Enunciado(string titulo, string descricao, string anoLetivo, vector<Estudante> estudantes);
	string getTitulo() const;
	string getDescricao() const;
	vector<string> getAnosLetivos() const;
	vector<Estudante> getEstudantes() const;
	void setTitulo(std::string novoTitulo);
	void setDescricao(std::string novaDescricao);
};

#endif /* ENUNCIADO_H */
