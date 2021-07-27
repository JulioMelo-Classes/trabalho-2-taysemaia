#include "../include/usuario.h"
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
int Usuario::getID() const
{
	return id;
}

/*! Seta o ID do usuario como o id passado pelo parametro
			@param id_ a ser armazenado
		*/
void Usuario::setID(int id_)
{
	id = id_;
}

/*! Retorna o nome do usuario
				@return retorna uma string com nome do usuario
		*/
std::string Usuario::getNome() const
{
	return nome;
}

/*! Seta o nome do usuario como o nome passado pelo parametro
			@param nome_ a ser armazenado
		*/
void Usuario::setNome(string nome_)
{
	nome = nome_;
}

/*! Retorna o email do usuario
				@return retorna uma string com email do usuario
		*/
std::string Usuario::getEmail() const
{
	return email;
}

/*! Seta o email do usuario como o email passado pelo parametro
			@param email_ a ser armazenado
	*/
void Usuario::setEmail(std::string email_)
{
	email = email_;
}

/*! Retorna a senha do usuario
				@return retorna uma string com a senha do usuario
	*/
std::string Usuario::getSenha() const
{
	return senha;
}

/*! Seta a senha do usuario como a senha passado pelo parametro
			@param senha_ a ser armazenado
	*/
void Usuario::setSenha(std::string senha_)
{
	senha = senha_;
}
