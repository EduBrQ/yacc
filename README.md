
# Utilizando LEX e YACC para reconhecer comandos SQL

Este é um analisador sintático utilizando LEX e YACC para o reconhecimento de comandos para SQL através do terminal do sistema operacional.

## Configuração inicial
+ Para executar o compilador você deve estar em uma máquina UNIX, pode ser Mac ou Linux;
+ No <b>Linux</b>, para instalar os pacotes necessários, deve executar os seguintes comandos no terminal:
```
	sudo apt-get install flex
	sudo apt-get install byaac
```
+ No <b>Windows</b>, siga as instruções do tutorial no final destas anotações.
+ Após a instalação dos pacotes, 
+ Baixe os arquivos <b>lex.l</b> e <b>yacc.y</b>;
+ Com o terminal, você deve ir até a pasta onde está os arquivos baixados;
+ Lá deve ser executado os seguintes comandos:
```
	lex lex.l
	yacc -d yacc.y
```
+ Serão criados os arquivos:
```
	lex.yy.c
	y.tab.c
	y.tab.h
```

+ Depois, deve ser executado o seguinte comando no terminal:
```
	gcc lex.yy.c y.tab.c -o ly
```
+ Veja que foi criado um arquivo "ly". No terminal execute o comando:
```
	./ly
```

## Testando o analisador léxico:
+ Ele ficará aguardando sua sentença.
+ Tente, por exemplo digitar estas linhas de comando:
```
	select * from table1 where name=uepb
	select name from table2 where name=uepb and surname=compilad
```
+ Dessa forma, se tudo ocorrer bem, ele irá retornar:
```
	Sintaxe Correta
```
+ Tente agora digitar alguma sentença incorreta, como por exemplo:
```
	select * from where name=uepb
	select name from table
```
+ Dessa forma, ele irá retornar a mensagem de erro e o analisador encerrará.

## Observações
+ Para executar o Lex-Yacc no Windows, instale os pacotes necessários através deste tutorial
https://www.youtube.com/watch?v=0MUULWzswQE&t=11s
