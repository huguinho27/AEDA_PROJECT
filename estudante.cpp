#include "estudante.h"
#include <iostream>


Estudante::Estudante(double nota)
{
	if (nota > 20 || nota < 0)
		return;
	notaTrabalho = nota;
}

double Estudante::getNota() const
{
	return this->notaTrabalho;
}
