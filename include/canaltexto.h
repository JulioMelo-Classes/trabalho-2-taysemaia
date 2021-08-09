#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include "mensagem.h"

class CanalTexto{
	private:
		std::string nome;
		std::vector<Mensagem> mensagem;
	public:

		std::string getNomeCanal();
		void setNomeCanal(std::string nome);

};

#endif
