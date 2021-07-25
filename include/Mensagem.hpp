#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP
using namespace std;
#include <string>


class Mensagem{

	private:

		std::string dataHora, conteudo;
		int enviadaPor;
		

	public:

		string getDataHora() const;
		void setDataHora(string dataHora_);

		string getConteudo() const;
		void setConteudo(string conteudo_);

		int getEnviadaPor() const;
		void setEnviadaPor(int enviadaPor_);

};	

#endif