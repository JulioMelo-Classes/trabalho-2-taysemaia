#ifndef USUARIO_HPP
#define USUARIO_HPP
using namespace std;

class Usuario{

	private:

		int id;
		std::string nome, email, senha;

	public:

		int getID() const;
		void setID(int id_);

		string getNome() const;
		void setNome(string nome_);

		string getEmail() const;
		void setEmail(string email_);

		string getSenha() const;
		void setSenha(string senha_);



};

#endif