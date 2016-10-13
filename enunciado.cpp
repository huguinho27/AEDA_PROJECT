#include <enunciado.h>
using namespace std;

Enunciado::Enunciado(string titulo, string descricao, string anoLetivo, vector<Estudante> estudantes)
{
	this->titulo = titulo;
	this->descricao = descricao;
	this->anosLetivosProposto.push_back(anoLetivo);

	for(unsigned int i = 0; i < estudantes.size();i++)
	{
		this->estudantesEnvolvidos.push_back(estudantes[i]);
	}
}

string Enunciado::getTitulo() const
{
	return titulo;
}

string Enunciado::getDescricao() const
{
	return descricao;
}

vector<string> Enunciado::getAnosLetivos() const
{
	return anosLetivosProposto;
}

vector<Estudante> Enunciado::getEstudantes() const
{
	return estudantesEnvolvidos;
}

void Enunciado::setTitulo(string novoTitulo)
{
	titulo = novoTitulo;
}

void Enunciado::setDescricao(string novaDescricao)
{
	descricao = novaDescricao;
}
