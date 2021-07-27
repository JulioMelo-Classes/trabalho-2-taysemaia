#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "canaltexto.h"
#include <string>
#include <vector>

class Servidor
{
	private: 
		int usuarioDonoID; //<! id do usuario 
		std::string nome, codigoConvite, descricao; //<! nome do servidor, codigo de convite e descrição 
		std::vector<CanalTexto> canaisTexto; //<! vetor de canais de texto 
		std::vector<int> participantesIDs; //<! vetor com id dos participantes
		
	public:
		/*! Retorna o ID do usuario
					@return retorna um int com id
			*/
		int getUserID() const;

		/*! Seta o ID do usuario como o id passado pelo parametro
			@param id_ a ser armazenado
		*/
		void setUserID(int id_);

		/*! Retorna o nome do servidor
				@return retorna uma string com nome do servidor
		*/
		std::string getNomeServer() const;

		/*! Seta o nome do servidor como o nome do servidor passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setNomeServer(std::string nome_);

		/*! Retorna a descrição do servidor
				@return retorna uma string com a descrição do servidor
		*/
		std::string getServerDescricao() const;

		/*! Seta a descrição servidor como a descrição servidor passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setServerDescricao(std::string desc);

		/*! Retorna o codigo de convite do servidor
				@return retorna uma string com o codigo de convite para o servidor
		*/
		std::string getInviteCode() const;

		/*! Seta o codigo de convite do servidor como o codigo de convite passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setInviteCode(std::string code);

};


#endif
