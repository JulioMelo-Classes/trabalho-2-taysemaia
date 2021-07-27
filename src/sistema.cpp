#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int id_ = -1;
std::string aux1 = "";
std::string aux2 = "";

std::pair<std::string, std::string> pair1(aux1, aux2);

/* COMANDOS */
/*! Responsavel por procurar se o usuario do ID está logado
				@param id o id do usuario informado
				@return true, se tiver logado, false se não estiver
		*/
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

/*! Recebe um ID, adiciona o ID como chave no map e o valor mapeado como um par de strings vazias
				@param id o id do usuario logado
	*/
void Sistema::adicionarAosLogados(int idLogado)
{
  usuariosLogados.insert({idLogado, (pair1)});
}

/*! Busca o email passado como parametro no vetor de usuarios
				@param email email a ser buscado
				@return false, se achar o email, true se não achar
*/
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

/*! Busca no vetor de usuarios se existe algum email com a senha correspondente
				@param senha a senha informada
				@param email email informado
				@return true, se a senha corresponde ao email, false, se nao
	*/
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

/*! Procurando no vetor de servidores, se o nome do servidor existe
				@param nome nome do servidor a ser procurado
				@return true, se ja existir o servidor, false se não existir
	*/
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

/*! Encerra o funcionamento do Concordo, o programa termina ao executar este comando.
				@return uma string com a mensagem "Saindo.."
		*/
string Sistema::quit()
{
  return "Saindo do Concordo...";
}

/*! Cria um usuário e retorna uma string de erro/sucesso 
				@param email o email do usuário informado no comando create-user
				@param senha a senha passada ao comando create-ser
				@param nome o nome do usuário (com espaços) passado ao comando create user 
				@return uma string contendo uma mensagem de erro ou "Usuário Criado"
		*/
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

/*! Realiza o login do usuário com email e senha, retorna uma string de erro ou uma mensagem 
				login bem sucedido. Quando um usuário loga o sistema deve adicionar o usuário na tabela 
				Sistema::usuariosLogados.
				@param email o email do usuário, passado no comando login
				@param senha a senha correspondente àquele usuário
				@return uma string contendo uma mensagem de erro ou "Logado como <email>!"
		*/
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

/*! Desconecta um usuário específico do sistema, removendo a informação daquele usuário da 
				tabela Sistema::usuariosLogados. A função retorna uma mensagem de sucesso ou de erro 
				caso o usuário não esteja logado.
				@param id um id válido de um usuário logado no sistema.
				@return "Usuário <email> desconectado!" ou uma mensagem de erro em caso de falha.
		*/
string Sistema::disconnect(int id)
{

  if (!UsuarioLogado(id))
  {
    return "Usuário(a) não está logado(a)!";
  }

  usuariosLogados.erase(id);
  return "Usuário desconectado(a)!";
}

/*! Cria um novo servidor no sistema e o adiciona na lista de servidores. A função deve retornar
				uma string "Servidor <nome> criado" ou uma mensagem de erro caso o servidor não possa ser 
				criado por algum motivo.
				@param id um id válido de um usuário logado no sistema.
				@param nome o nome do servidor de acordo com o comando create-server.
				@return "Servidor <nome> criado" quando o servidor for criado ou uma mensagem de erro em
								caso de falha.
		*/
string Sistema::create_server(int id, const string nome)
{
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

/*! Modifica a descrição do servidor passado no comando, para a descrição desejada. A função
				deve retornar "Descrição do servidor <nome> modificada!" ou uma mensagem de erro em caso
				de falha.
				@param id um id válido de um usuário logado no sistema.
				@param nome o nome do servidor que se deseja mudar.
				@param descricao nova descrição desejada.
				@return "Descrição do servidor <nome> modificada!" ou uma mensagem de erro em caso de falha.
		*/
string Sistema::set_server_desc(int id, const string nome, const string descricao)
{

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

/*! Modifica o código de convite do servidor no sistema. Retorna uma mensagem de sucesso ou
				de erro em caso de falha.
				@param id um id válido de um usuário logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@param codigo um código de acordo com o comando set-server-invite-code.
				@return "Código de convite modificado com sucesso" ou uma mensagem de erro em caso de
								falha.
		*/ 
string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{

  for (auto &elem : servidores)
  {
    if (elem.getNomeServer() == nome && elem.getUserID() == id && codigo.length() != 0)
    {
      elem.setInviteCode(codigo);
      return "Código de convite do servidor modificado";
    }
  }

  return "Código de convite do servidor removido";
}

/*! Lista os servidores cadastrados no sistema, retorna uma string contendo uma mensagem de
				erro ou uma string vazia no caso de não haver erros.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia ou a string de erro "Usuário não está logado".
		*/
string Sistema::list_servers(int id)
{

  for (auto &elem : servidores)
  {
    cout << elem.getNomeServer() << endl;
  }

  return "";
}

/*! Remove um servidor da lista de servidores, retornando uma mensagem de sucesso ou de erro
				em caso de falha.
				@param id  um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@return "Servidor <nome> removido com sucesso" ou uma mensagem de erro em caso de falha.
		*/
string Sistema::remove_server(int id, const string nome)
{

  for (auto &itr : servidores)
  {
    if (itr.getNomeServer() == nome && itr.getUserID() == id)
    {
      //servidores.erase(index);
      return "Servidor apagado";
    }
  }
  return "Você não pode apagar este servidor";
}
// -------------------------------------------*************** ----------------------------------------

/*! Faz com que o usuário logado com o id dado entre no servidor de nome com a senha fornecida
				(se necessário). Retorna uma mensagem de erro em caso de falha ou uma mensagem de sucesso
				caso contrário. Esse método atualiza a tabela Sistema::usuariosLogados com a informação do
				servidor que o usuário com o id está conectado.
				@param id  um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@param codigo um código de convite para o servidor se necessário ou uma string vazia, caso
							 o comando tenha vindo sem código. Veja o comando enter-server para mais detalhes.
				@return "Entrou no servidor <nome>" em caso de sucesso ou uma mensagem de erro caso contrário.
		*/
string Sistema::enter_server(int id, const string nome, const string codigo)
{
  return "enter_server NÃO IMPLEMENTADO";
}

/*! Faz com oque o usuário conectado em algum servidor saia do mesmo. Deve retornar uma string
				com uma mensagem de sucesso ou uma mensagem de erro caso contrário. No caso que o servidor
				passado como agumento para este método é o mesmo que o servidor em que o usuário está 
				visualizando atualmente (usando o valor guardado em Sistema::usuariosLogados) este método
				deve atualizar a tabela Sistema::usuariosLogados, sinalizando que o usuário não está mais
				visualizando aquele servidor.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@return "Saiu do servidor <nome>" ou uma mensagem de erro em caso de falha.
		*/
string Sistema::leave_server(int id, const string nome)
{
  return "leave_server NÃO IMPLEMENTADO";
}

/*! Lista os participantes presentes no servidor que o usuário com o id passado está visualizando.
				Retorna uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return Uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_participants(int id)
{
  return "list_participants NÃO IMPLEMENTADO";
}

/*!	Lista os canais do servidor que o usuário com o id passado está vizualizando. Retorna uma
				string vazia em caso de sucesso o uma mensagem de erro no caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_channels(int id)
{
  return "list_channels NÃO IMPLEMENTADO";
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
