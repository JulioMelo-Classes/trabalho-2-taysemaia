#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP
using namespace std;
#include <vector>
#include "CanalTexto.hpp"

class Servidor
{
	private: 
		int usuarioDonoID;
		std::string nome, codigoConvite, descricao;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs; 
};



#endif