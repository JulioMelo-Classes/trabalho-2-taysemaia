#include <iostream>
#include <cstring>
using namespace std;
#include "../include/Usuario.hpp"
#include "../include/Mensagem.hpp"
#include "../include/Servidor.hpp"
#include "../include/CanalTexto.hpp"
#include "../include/Sistema.hpp"
#include <vector>
#include <map>


void mostrarComandos(){
	cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;
	cout << "                                          Os comandos disponíveis são:" << endl;
	cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;

	cout << "1 - quit" << endl; 
	cout << "2 - login" << endl;
	cout << "3 - create-user" << endl; 


}




int main(int argc, char const *argv[]){
	int option;
	std::string comando, nome, email, senha;
	Sistema sistema;
	Mensagem mensagem;
	Usuario usuario;
	CanalTexto canaltexto;
	Servidor servidor;


	cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;
	cout << "Bem vindo(a) ao Concord, digite o comando desejado, ou \"list\" a qualquer momento para conhecer os comandos disponíveis." << endl;
	cout << "------------------------------------------------------ * * * -----------------------------------------------------------" << endl;

	while(1){

		cout << " >>>> ";
		std::cin >> comando;

		if(comando == "list"){
			mostrarComandos();
		}

		else if(comando == "quit"){
			cout << "Saindo do Concord ..." << endl;
			return 1;
		}

		else if(comando == "login"){

			cin >> email;
			cin >> senha;
			cin.ignore(); 
			getline(cin, nome);
			cout << nome << endl; 
			cout << email << endl;
			cout << senha << endl;
			//buscaEMail();
			cout << "dados pegos" << endl;

	
		}


		else if(comando == "create-user"){
			

			//validaEMail();
			
		}
		else{
			cout << "Desculpe, comando inválido, tente novamente. " << endl; 
		}






	}




	return 0;
}