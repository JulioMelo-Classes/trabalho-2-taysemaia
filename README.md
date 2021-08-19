# Base para a atividade 02 de LP1
<!--da forma como eu baixei não estava compilando!, vocês provavelmente esqueceram de dar commit no CMakeLists.txt, vou considerar 50% do critério relacionado com "organização" uma vez que essa é uma falha grave.-->
<!--como voces não criaram casos de teste ou mesmo documentaram algum caso de teste aqui vou considerar 0 neste quesito-->
Use esse esqueleto de classes para iniciar a terceira atividade.

Existe um executor que faz a interpretação dos comandos e executa o método correto do sistema.

## Para compilar

Com makefiles:
```console
mkdir build
make
```

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

Escolha uma das duas formas de build e ignore a outra.

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
./build/concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < script_comandos.txt
```
