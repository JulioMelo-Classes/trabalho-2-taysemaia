#include "../include/Mensagem.hpp"
using namespace std;
#include <iostream>
#include <vector>



string Mensagem::getDataHora() const{
	return dataHora;
}

void Mensagem::setDataHora(string dataHora_){
	dataHora = dataHora_;
}

string Mensagem::getConteudo() const{
	return conteudo;
}
void Mensagem::setConteudo(string conteudo_){
	conteudo = conteudo_;
}

int Mensagem::getEnviadaPor() const{
	return enviadaPor;
}
void Mensagem::setEnviadaPor(int enviadaPor_){
	enviadaPor = enviadaPor_;
}