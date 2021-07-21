#include <iostream>

using namespace std;


int main(int argc, char const *argv[]){
	int option;


	cout << "Bem vindo ao discordo, escolha a opção desejada: " << endl;
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
	}


























	return 0;
}