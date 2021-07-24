#include "../include/Sistema.hpp"
using namespace std;
#include <iostream>
#include <vector>


void setUsuarios(vector<Usuario> usuarios_){
	usuarios = usuarios_;
}

vector<Usuario> getUsuarios() const{
	return usuarios;
}

void setServidores(vector<Servidor> servidores_){
	servidores = servidores_;
}

vector<Servidor> getServidores()const{
	return servidores;
}

void setUsuariosLogados(std::map<int, pair <string, string>> usuariosLogados_){
	usuariosLogados = usuariosLogados_;
}

std::map<int, pair <string, string>> getUsuariosLogados()const{
	return usuariosLogados;
}	