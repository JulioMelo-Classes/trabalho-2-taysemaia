#include "../include/canaltexto.h"
using namespace std;
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>


std::string CanalTexto::getNomeCanal(){
	return nome;
}

void CanalTexto::setNomeCanal(std::string nome){
	this->nome = nome;
}