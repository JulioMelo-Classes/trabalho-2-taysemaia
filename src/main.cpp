#include <iostream>
using namespace std;


void mostrarComandos(){
	cout << "-------------------------------------------- * * * -------------------------------------------------" << endl;
	cout << "                               Os comandos disponíveis são:" << endl;
	cout << "-------------------------------------------- * * * -------------------------------------------------" << endl;

	cout << "1 - quit" << endl; 
	cout << "2 - login" << endl;
	cout << "3 - create-user" << endl; 
	cout << "4 - disconnect" << endl;
	cout << "5 - create-server" << endl;
	cout << "6 - set-server-invite-code" << endl;
	cout << "7 - list-servers" << endl;
	cout << "8 - remove-server" << endl;
	cout << "9 - enter-server" << endl;
	cout << "10 - leave-server" << endl;
	cout << "11 - list-participants" << endl;


}




int main(int argc, char const *argv[]){
	int option;
	std::string comando;


	cout << "-------------------------------------------- * * * -------------------------------------------------" << endl;
	cout << "Bem vindo(a) ao Concord, digite o comando desejado, ou \"list\"  pra conhecer os comandos disponíveis." << endl;
	cout << "-------------------------------------------- * * * -------------------------------------------------" << endl << endl;
 
	while(1){

		std::cin >> comando;

		if(comando == "list"){
			mostrarComandos();
		}
		else if(comando == "quit"){
			cout << "Saindo do Concord ..." << endl;
			return 1;
		}














	}

	/*cout << "Bem vindo ao discordo, escolha a opção desejada: " << endl;
	cout << "1- Fazer login." << endl;
	cout << "2- Cadastrar-se" << endl;
	cout << "3- Sair" << endl;

	cin >> option;

	switch(option){
		case 1:	
			cout << "Digite: \"login seu@email suasenha\"" << endl;
			break;
		case 2:	
			cout << "Digite: \"create-user seu@email suasenha Seu Nome\"" << endl;
			break;
		case 3: 
			return 1;
		default: 
			cout << "Opção Inválida" << endl;
	}*/ 


























	return 0;
}