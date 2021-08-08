#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int id_ = -1;
std::string servidorVisualizado = "";
std::string canalVisualizado = "";

std::pair<std::string, std::string> pair1(servidorVisualizado, canalVisualizado);
std::pair<std::string, std::string> pair2(servidorVisualizado, canalVisualizado);

/* COMANDOS */
/*! Responsavel por procurar se o usuario do ID está logado
				@param id o id do usuario informado
				@return true, se tiver logado, false se não estiver
		*/

std::vector<Usuario> Sistema::getUsuarios() const{

  return usuarios;
}

bool Sistema::UsuarioLogado(int id)
{
  std::map<int, std::pair<std::string, std::string>>::iterator it;
  it = usuariosLogados.find(id);

  if (it == usuariosLogados.end())
  {
    return false;
  }
  return true;
}


void Sistema::adicionarAosLogados(int idLogado)
{
  usuariosLogados.insert({idLogado, (pair1)});
}


bool Sistema::buscaEmail(std::string email)
{

  for (auto &elem : usuarios)
  {
    if (elem.getEmail() == email)
    {

      return false;
    }
  }

  return true;
}


bool Sistema::buscaSenhaEmail(std::string senha, std::string email)
{

  for (auto &elem : usuarios)
  {
    if (elem.getEmail() == email && elem.getSenha() == senha)
    {
      adicionarAosLogados(elem.getID());
      return true;
    }
  }

  return false;
}


bool Sistema::buscaNomeServidor(std::string nome)
{

  for (auto &elem : servidores)
  {
    if (elem.getNomeServer() == nome)
    {
      return true;
    }
  }

  return false;
}


string Sistema::quit()
{
  return "Saindo do Concordo...";
}


string Sistema::create_user(const string email, const string senha, const string nome)
{

  if (!buscaEmail(email))
  {

    return "Usuário já existe!";
  }
  else
  {

    Usuario usuario;
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setNome(nome);
    id_++;
    usuario.setID(id_);
    usuarios.push_back(usuario);

    return "Usuário criado com sucesso!";
  }
}


string Sistema::login(const string email, const string senha)
{
  if (buscaSenhaEmail(senha, email))
  {
    return email + " logado(a) com sucesso!";
  }
  else
  {
    return "Senha ou usuário inválidos!";
  }
}


string Sistema::disconnect(int id)
{

  if (!UsuarioLogado(id))
  {
    return "Usuário(a) não está logado(a)!";
  }

  usuariosLogados.erase(id);
  return "Usuário desconectado(a)!";
}

string Sistema::create_server(int id, const string nome)
{
  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  if (buscaNomeServidor(nome))
  {
    return "Servidor com esse nome já existente!";
  }

  Servidor servidor;
  servidor.setUserID(id);
  servidor.setNomeServer(nome);
  servidores.push_back(servidor);

  return "Servidor criado!";
}


string Sistema::set_server_desc(int id, const string nome, const string descricao)
{
	if(!UsuarioLogado(id)){
		return "Usuário não está logado.";
	}

  for (auto &itr : servidores)
  {
    if (itr.getNomeServer() == nome && itr.getUserID() == id)
    {
      itr.setServerDescricao(descricao);
      return "Descrição do servidor alterada!";
    }
    else if (!buscaNomeServidor(nome))
    {
      return "Servidor não existe!";
    }
  }
  return "Você não pode alterar a descrição de um servidor que não foi criado por você";
}


string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{
	if(!UsuarioLogado(id)){
		return "Usuário não está logado.";
	}

  for (auto &elem : servidores)
  {
    if (elem.getNomeServer() == nome && elem.getUserID() == id && codigo.length() != 0)
    {
      elem.setInviteCode(codigo);
      return "Código de convite do servidor modificado";
    }
  }
  //alguma coisa ficou faltando aqui
  return "Código de convite do servidor removido";
}


string Sistema::list_servers(int id){ 
  int i = 0;
  cout << "Listando Servidores:" << endl;
  cout << "--------------------" << endl; 
  for (auto &elem : servidores){
    i++;
    cout <<"Servidor" << i << " : " << elem.getNomeServer() << endl;
  }

  return "--------------------";
}


string Sistema::remove_server(int id, const string nome)
{
 
  for (auto itr = servidores.begin(); itr != servidores.end(); itr++)
  {
    if (itr->getNomeServer() == nome && itr->getUserID() == id)
    {
      cout<<"Apagando servidor "<<itr->getNomeServer()<< endl;
      servidores.erase(itr);
      return "Servidor apagado!";
    }
  }

  return "Você não pode apagar este servidor";
}
// -------------------------------------------*************** ----------------------------------------

string Sistema::enter_server(int id, const string nome, const string codigo){

  if (!UsuarioLogado(id)){
    return "Usuário não está logado";
  }

  if(!buscaNomeServidor(nome)){
    return "Servidor não existente";
  }

  for(auto &elem : servidores){ 

    if(elem.getNomeServer() == nome && elem.getUserID() == id){ // se o usuario for dono do servidor
      std::pair<std::string, std::string> pair2(nome, "");
      usuariosLogados.at(id) = (pair2);
      elem.adicionaID(id);
      return "Entrou no servidor com sucesso!";
    }

    else if(elem.getNomeServer() == nome && elem.getInviteCode() == codigo){  // se o codigo for vazio ou tiver um codigo certo
      usuariosLogados.at(id).first = nome; // adiciona a tabela de usuarios logados o noem do servidor sendo visualizado
      elem.adicionaID(id);
      return "Entrou no servidor com sucesso!";
    }
  }

  return "Código não correspondente ao Servidor que deseja entrar!";

}


string Sistema::leave_server(int id, const string nome){

  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == nome){

      if (!elem.usuarioParticipante(id)){
        return "Usuário não participa deste servidor!";
      }
      usuariosLogados.at(id).first = "";
      elem.removeParticipante(id);
      return "Saindo do servidor " + nome + "!";
    } 
  }

  return "Servidor Inexistente!"; 
}

/*! Lista os participantes presentes no servidor que o usuário com o id passado está visualizando.
				Retorna uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return Uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_participants(int id){

  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  std::string servidor_ = usuariosLogados.at(id).first;
  if(servidor_ == ""){

    return "O usuário não está visualizando nenhum servidor!";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){
    

    } 
  }

  return "incompleto";
}

/*!	Lista os canais do servidor que o usuário com o id passado está vizualizando. Retorna uma
				string vazia em caso de sucesso o uma mensagem de erro no caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_channels(int id)
{
  if (!UsuarioLogado(id)){
    return "O usuário não está logado!";
  }

  std::string servidor_ = usuariosLogados.at(id).first;

  if(servidor_ == ""){

    return "O usuário não está visualizando nenhum servidor!";
  }
  cout << "#Canais de texto: " << endl;
  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){
      elem.listarCanais(); //listar canais do servidor elem
      return "------------------";
    } 
  }
  return "";
}

/*! Cria um canal em um servidor com o nome passado. O canal criado é do tipo dado (voz ou texto)
				de acordo com o comando create-channel. Retorna uma mensa
				@param id um id válido de algum usuário cadastrado e logado no sistema. 
				@param o nome do novo canal, de acordo com o comando create-channel
				@return "Canal <nome> criado!" ou uma mensagem de erro em caso de falha.
		*/
string Sistema::create_channel(int id, const string nome)
{
  return "create_channel NÃO IMPLEMENTADO";
}

/*! Faz com que o usuário com id dado entre em um canal específico(com seu nome e tipo) ao entrar
				em um canal o sistema deve atualizar a tabela Sistema::usuariosLogados com a informação de
				que o usuário está vizualizando o canal em que entrou. Retorna uma mensagem de sucesso ou de
				erro em caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param o nome do canal que deseja entrar,
				@return "Usuário <email.do.usuario> entrou no canal <nome>" ou uma mensagem de
								erro em caso de falha.
		*/
string Sistema::enter_channel(int id, const string nome)
{
  return "enter_channel NÃO IMPLEMENTADO";
}

/*! Faz com que o usuário com id dado saia do canal que está visualizando atualmente. 
				Ao sair de um canal o sistema deve atualizar o attributo Sistema::usuariosLogados de 
				forma que o usuário não esteja mais vizualizando qualquer canal. A função deve retornar 
				mensagem de sucesso ou de erro em caso de falha
				@param id um id válido de algum usuário cadastrado e logado no sistema.
							 que o usuário está visualizando, de acordo com o atributo Sistema::usuariosLogados.
				@return "Usuário <email.do.usuario> saiu no canal <nome>" ou uma mensagem de erro em caso de
								falha.
		*/
string Sistema::leave_channel(int id)
{
  return "leave_channel NÃO IMPLEMENTADO";
}

/*! Envia uma mensagem no canal em que o usuáiro com id passado está visualizando.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param mensagem a mensagem que deve ser enviada.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::send_message(int id, const string mensagem)
{
  return "send_message NÃO IMPLEMENTADO";
}

/*! Lista as mensagem no canal que o usuário com id passado está visualizando.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_messages(int id)
{
  return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
