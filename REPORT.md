# Identificação

* Página do repositório do trabalho ([link GitHub](https://github.com/marcio-henrique/cpu-memory-intense-usage)) 

* Discente 1
	* Nome: Márcio Henrique Vieira de Oliveira
	* Matrícula: 19111163
	* Distribuição da nota (%): 33.33%
* Discente 2
	* Nome: Michael Miller Rodrigues Cardoso
	* Matrícula: 19111327
	* Distribuição da nota (%): 33.33%
* Discente 3
	* Nome: Michel Thomas Gomes Lins
	* Matrícula: 19111328
	* Distribuição da nota (%): 33.33%
	
# Resultados

## Utilização intensa da UCP

* Em ambos os testes utilizamos o seguinte comando para utilização intensa da UCP:

```
while(1){}
```

* Resultado da primeira execução do algoritmo:

![Teste 1 - Uso UCP](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-T2.jpg)

* Resultado das seguintes execuções:

![Teste 2 - Uso UCP](https://github.com/marcio-henrique/cpu-memory-intense-usage/blob/master/img/CPU-T1.jpg)

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

Ambos os resultados das execuções foram esperados, pois mantiveram o consumo da UCP em alta porcentagem durante todos os dez segundos. O primeiro resultado que obtivemos foi a partir da primeira execução do programa, em que tivemos um pico de grande porcentagem de consumo que teve uma pequena redução com o tempo e após isso aumentou um pouco. Nas execuções seguintes(entre três e quatro execuções), o índice de consumo manteve-se praticamente constante em um nível muito elevado. Apesar de não ter sido abordado nos gráficos, vale ressaltar que o índice de consumo de memória e kilobytes manteve-se constante em todas as execuções.

## Utilização intensa da UCP e memória

Inicialmente utilizando o código sem uma restrição de consumo de memória, o resultado não foi o esperado, já que a utilização de memória foi tamanha que o computador utilizado para o teste perdeu muito desempenho e começou a travar. Nesse estado crítico, o consumo da UCP sofreu uma drástica redução durante os instantes quatro e 5 segundos, sendo que em nenhum momento chegou a mais de de 85% de uso até o fim da execução do programa. Com relação ao consumo de memória em kilobytes, o gráfico manteve-se linear até chegar ao limite de memória disponível, onde manteve-se constante até o final da execução do programa.
Utilizando o algoritmo de restrição do uso da memória, o consumo da UCP manteve-se muito alto e praticamente constante durante a execução, já o consumo da memória principal seguiu linear. Quanto ao computador utilizados nos testes, não apresentou nenhum travamento na execução do programa, o que leva à conclusão de que o programa de execução intensa não consumiu memória a ponto de deixar o computador em estado crítico do recurso da memória.
