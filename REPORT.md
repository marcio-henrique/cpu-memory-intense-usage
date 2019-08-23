# Identificação

* Página do repositório do trabalho ([link GitHub](https://github.com/marcio-henrique/cpu-memory-intense-usage)) 

* Discente 1
	* Nome: Márcio Henrique Vieira de Oliveira
	* Matrícula: 19111163 
* Discente 2
	* Nome: Michael Miller Rodrigues Cardoso
	* Matrícula: 19111327
* Discente 3
	* Nome: Michel Thomas Gomes Lins
	* Matrícula: 19111328		

* A distribuição da nota será feita de forma igualitária.
	
# Resultados

## Utilização intensa da UCP

* Em ambos os testes utilizamos o seguinte comando para utilização intensa da UCP:

```
while(1){}
```

* Resultado da primeira execução do algoritmo:

![Teste 1 - Uso UCP](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-T1.jpg)

* Resultado das seguintes execuções:

![Teste 2 - Uso UCP](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-T2.jpg)

## Utilização intensa da UCP e Memória

* Primeiro teste UCP-MEM, sem grande restrição do uso de memória, utilizando os seguintes comandos:

```
char *memory = (char *) malloc(sizeof(char));
while(1)
{
	if (memory != NULL)
	{
		memory = (char *) malloc(sizeof(char));
	}
}
```

![Teste 1 - Uso UCP-MEM](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-MEM-T11.jpg)
![Teste 1 - Uso UCP-MEM](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-MEM-T12.jpg)

* Segundo teste UCP-MEM, com maior restrição ao uso de memória, utilizando os seguintes comandos:

```
char *memory = (char *) malloc(sizeof(char));
int i;
for(i = 0; 1; i++)
{
	if (i % 10 == 0 && memory != NULL)
	{
		memory = (char *) malloc(sizeof(char));
	}
}
```

![Teste 2 - Uso UCP-MEM](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-MEM-T21.jpg)
![Teste 2 - Uso UCP-MEM](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-MEM-T22.jpg)

# Discussão

## Utilização intensa da UCP

TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
