#include "../include/servidor.h"
using namespace std;
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>

	/*! Retorna o ID do usuario
				@return retorna um int com id
		*/
int Servidor::getUserID() const{
	return usuarioDonoID;
}

	/*! Seta o ID do usuario como o id passado pelo parametro
				@param id_ a ser armazenado
			*/		
void Servidor::setUserID(int id_){
	usuarioDonoID = id_;
}

	/*! Retorna o nome do servidor
					@return retorna uma string com nome do servidor
			*/
std::string Servidor::getNomeServer() const{
	return nome;
}

	/*! Seta o nome do servidor como o nome do servidor passado pelo parametro
				@param nome_ a ser armazenado
			*/
void Servidor::setNomeServer(std::string nome_){
	nome = nome_;
}

	/*! Retorna a descrição do servidor
					@return retorna uma string com a descrição do servidor
			*/
std::string Servidor::getServerDescricao() const{
	return descricao;
}

	/*! Seta a descrição servidor como a descrição servidor passado pelo parametro
				@param nome_ a ser armazenado
			*/
void Servidor::setServerDescricao(std::string desc){
	descricao = desc;
}

	/*! Retorna o codigo de convite do servidor
					@return retorna uma string com o codigo de convite para o servidor
			*/
std::string Servidor::getInviteCode() const{
	return codigoConvite;
}

	/*! Seta o codigo de convite do servidor como o codigo de convite passado pelo parametro
				@param nome_ a ser armazenado
			*/
void Servidor::setInviteCode(std::string code){
	codigoConvite = code;
}