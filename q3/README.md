# DATACOM - Embedded C/C++ Developer Challenge

[![N|Solid](./images/datacom.png)](https://www.datacom.com.br/)

## Desafio

Implemente, usando sua linguagem de preferência, a seguinte máquina de estados, ela representa um protocolo de conexão entre 2 equipamentos (mestre/escravo): 

| Estado/Evento/Proximo estado     | Interface nok | Interface ok | Pacote ok recebido | Pacote nok recebido | Não recebeu resposta |
| :---      | :---:       | :---:       | :---:       | :---:       | :---:       |
| 1- Link Down | 1         | 2         | 1         | 1         | 1         |
| 2 - Enviando Start     | 1        | -        | 3        | 2        | 2        |
| 3 - Start recebido envia Configuração     | 1        | -        | 4        | 3        | 2        |
| 4 - Link OK – manda keepalive     | 1        | -        | 4        | 2        | 2        |


Deve ser implementada uma função que recebe o estado atual e o evento associado. Deverá
retornar o próximo estado e realizar as chamadas a funções que realizam as ações referentes a cada
estado

## Como compilar o projeto

Só precisa fazer um make.

```sh
make
```

## Como executar o projeto

Execute o arquivo criado na pasta build.

```sh
./build/protocol-state-machine
```