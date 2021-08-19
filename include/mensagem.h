#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>
#include <vector>
using namespace std; //isso aqui é uma má prática! você pode usar no .cpp mas não no .h
/*
cp2 ok
*/
class Mensagem{
	private:
		std::string dataHora; //<! data e hora da mensagem
		int enviadaPor; //<! id de quem foi enviada a mensagem
		std::string conteudo; //<! conteudo da mensagem
	public:
		
		
};

#endif