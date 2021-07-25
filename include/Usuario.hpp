#ifndef USUARIO_HPP
#define USUARIO_HPP
using namespace std;
#include <string>

class Usuario{

	private:

		int id;
		std::string nome, email, senha;

	public:

		int getID() const;
		void setID(int id_);

		std::string getNome() const;
		void setNome(std::string nome_);

		std::string getEmail() const;
		void setEmail(std::string email_);

		std::string getSenha() const;
		void setSenha(std::string senha_);



};

#endif