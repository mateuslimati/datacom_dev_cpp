# DATACOM - Embedded C/C++ Developer Challenge

![alt text](https://www.datacom.com.br/assets/site/images/main-logo.png)

## Aponte e comente os erros existentes no código 

O tamanho de um pacote não pode ser inteiro dado que inteiros aceitam números negativos, uma sugestão é utilizar o tipo size_t. Se o metódo deve retornar o pacote deve-se mudar a o tipo da variável de retorno para ponteiro para inteiro, ou mesmo retornar códigos de erro (da biblioteca errno.h) já que a referência do pacote já foi passada como atributo.

```c
char *insert_header(int *packet, int *length)
```

Há números mágicos no código, como o tamanho do header (12), que deveriam ser definidos em um arquivo do tipo header e incluido no arquivo .c em que o método é definido. Outro erro é a não inicialização dos outros 6 bytes do pacote, portanto assim lixo (dados aleatórios) que está na memória.

```c
char header[12] = { 0x80, 0x52, 0x66, 0x61, 0x77, 0x52 };
/* os outros 6 são 0 */
```
O laço de iteração sobre o packet para deslocamento dos dados não pode percorrer regiões inválidas como está acontecendo, mas deve parar no tamanho do pacote levando em consideração ao cabeçalho que vai ser acrescentado.

```c
    for (i = 0; i < *length; i++)
        packet[i + 3] = packet[i];
```

O código poderia estar escrito dessa forma

```c
    size_t header_size = (sizeof(header)/sizeof(int));

    for (i = 0; i < (*length - header_size); i++)
        packet[i + header_size] = packet[i];
```

O laço de iteração para inserção do cabeçalho no pacote também estava incorreto, dado que só tinha se deslocado 3 inteiros para a direita

```c
    for (i=0; i < 12; i++)
        packet[i] = header[i];
```

A maneira correta de se incluir o header ocupando todos os 4 bytes de um inteiro (dada a arquitetura de 32 bits) é a seguinte

```c
    for (i = 0; i < header_size; i++)
    {
        packet[i] = header[(i * sizeof(int))] << 24|
                    header[(i * sizeof(int)) + 1] << 16 |
                    header[(i * sizeof(int)) + 2] << 8 |
                    header[(i * sizeof(int)) + 3];
    }
```
O alinhamento dos bytes deve ser definido com base no padrão do protocolo (little ou big-endian)

Por fim, o tamanho do pacote não deve ser incrementado, dado que não se sabe como foi feita a alocação dele anteriormente, ou seja o length deve ser respeitado como alocação posterior.

```c
    *length += 12;
```
portanto eu removeria essa linha.