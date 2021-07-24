#include "../include/Usuario.hpp"
using namespace std;
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

int Usuario::getID() const{
	return id;
}

void Usuario::setID(int id_){
	id = id_;

}

string Usuario::getNome() const{
	return nome;
}
void Usuario::setNome(string nome_){
	nome = nome_;
}

string Usuario::getEmail() const{
	return email;
}
void Usuario::setEmail(string email_){
	email = email_;
}

string Usuario::getSenha() const{
	return senha;
}
void Usuario::setSenha(string senha_){
	senha = senha_;
}
