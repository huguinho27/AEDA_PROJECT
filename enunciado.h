#pragma once
#include <iostream>

class Enunciado
{
protected:
	std::string titulo, descricao;
	std::vector<std::string> anosLetivosProposto;
	std::vector<Estudante> estudantesEnvolvidos;
public:
	Enunciado(std::string titulo, std::string descricao, std::string anoLetivo, std::vector<Estudante> estudantes);
	std::string getTitulo() const;
	std::string getDescricao() const;
	std::vector<std::string> getAnosLetivos() const;
	std::vector<Estudante> getEstudantes() const;
	void setTitulo(std::string novoTitulo);
	void setDescricao(std::string novaDescricao);
};
