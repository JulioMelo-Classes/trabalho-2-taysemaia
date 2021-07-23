#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP
using namespace std;

class Servidor
{
	private: 
		int usuarioDonoID;
		std::string nome, codigoConvite, descricao;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs; 
};



#endif