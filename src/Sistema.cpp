#include "../include/Sistema.hpp"
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>



bool Sistema::buscaEmail(Usuario user){
    bool retorno;

    for (auto & elem : usuarios){
        if (elem.getEmail() == user.getEmail())
        {   

            retorno = false;
        }
        else{
            retorno = true;
        }

    }
    return retorno;
}


void Sistema::setUsuarios(Usuario user){
	usuarios.push_back(user);
}

vector<Usuario> Sistema::getUsuarios() const{
	return usuarios;
}

void Sistema::setServidores(vector<Servidor> servidores_){
	servidores = servidores_;
}

vector<Servidor> Sistema::getServidores()const{
	return servidores;
}

void Sistema::setUsuariosLogados(std::map<int, pair <string, string>> usuariosLogados_){
	usuariosLogados = usuariosLogados_;
}

std::map<int, pair <string, string>> Sistema::getUsuariosLogados()const{
	return usuariosLogados;
}	