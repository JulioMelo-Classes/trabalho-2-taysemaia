#ifndef SISTEMA_HPP
#define SISTEMA_HPP 
using namespace std;
#include <vector>
#include <map>
#include "Servidor.hpp"
#include "Usuario.hpp"

class Sistema{

	private:
		std::vector<Usuario> usuarios;
		std::vector<Servidor> servidores;
		std::map<int, pair <string, string>> usuariosLogados;

	public:

	void setUsuarios(vector<Usuario> usuarios_);

	vector<Usuario> getUsuarios() const;

	void setServidores(vector<Servidor> servidores_);

	vector<Servidor> getServidores()const;

	void setUsuariosLogados(std::map<int, pair <string, string>> usuariosLogados_);

	std::map<int, pair <string, string>> getUsuariosLogados()const;	

};



#endif