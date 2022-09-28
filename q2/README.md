# DATACOM - Embedded C/C++ Developer Challenge

![alt text](https://www.datacom.com.br/assets/site/images/main-logo.png)

## A função funciona? 

Não, porque o código se propõe a remover a entrada com um determinada chave, mas está removendo a entrada com chave diferente do argumento passado. 

```c
        if (entry->key != key)
```

Segundo erro é utilizar o ponteiro para a entrada após a liberação da memória utilizada.

```c
    free(entry);

    if ((noPrev) && (noNext)) {
        List_head = NULL;
    }
    else if (noPrev) {
        List_head = entry->next;
    }
```

## É reentrante? (Porque?)

Não, pois funções reusantes não podem possuir variáveis globais, no metódo temos a cabeça da lista que deve ser uma variável global

```c
    for (entry = List_head; entry != NULL; entry = entry->next) {
```

## O que a função faz?

Deveria remover uma entrada de uma lista encadeada

## Sugestões

para tornar a função reusante pode-se passar a cabeça da lista como parâmetro da função. Pode-se remover as seguintes variáveis

```c
    int noPrev = 1, noNext = 1;
```
apenas organizando as condicionais
```c

    // Caso a entrada seja a cabeça da lista
    if (entry == List_head)
    {
        List_head = entry->next;
    }
    // Caso a entrada não seja a cabeça da lista
    if (entry->previous != NULL)
    {
        entry->previous->next = entry->next;
    }
    // Caso a entrada não seja a calda da lista
    if (entry->next != NULL)
    {
        entry->next->previous = entry->previous;
    }
```

O código também está fora do code style com variáveis  no padrão camelcase e outras snack case, como

```c
    int noPrev = 1, noNext = 1;
    entry = List_head;
```