#ifndef SISTEMA_HPP
#define SISTEMA_HPP 
using namespace std;
#include <vector>
#include <map>
#include "Servidor.hpp"
#include "Usuario.hpp"
#include <string>





class Sistema{

	private:
		std::vector<Usuario> usuarios;
		std::vector<Servidor> servidores;
		std::map<int, pair <string, string>> usuariosLogados;

	public:
	bool buscaEmail(Usuario user);

	void setUsuarios(Usuario usuario);

	vector<Usuario> getUsuarios() const;

	void setServidores(vector<Servidor> servidores_);

	vector<Servidor> getServidores()const;

	void setUsuariosLogados(std::map<int, pair <string, string>> usuariosLogados_);

	std::map<int, pair <string, string>> getUsuariosLogados()const;	

	bool buscaEmail(std::vector<Usuario> usuarios);

};



#endif