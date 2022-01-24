/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
	T�tulo: Exerc�cios sobre aritm�tica de ponteiros aplicada em vetores

	Autor: Edgar Hideo Tamasiro
	Data: janeiro de 2022
	Vers�o: 1.0
	
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Constantes */
/*const*/
#define LEVELS 8

/* Macros */
/*#define*/

/* Declara��o de vari�veis globais */
int *ptr1, *ptr2,			/*dois ponteiros*/
	stack[LEVELS],			/*vetor que faz o papel da pilha*/
	stackData,				/*n�mero que ser� lido e inserido*/
	stackTop;				/*var. p/ informar o topo da pilha*/

/* Prot�tipo de fun��es */
void displayStack();
void push();
int pop();
void displayStackAddresses();

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* In�cio da fun��o principal */
main(int argc, char *argv[])
{
	int option;				/*p/ o menu de op��es c/ switch-case*/
	stackTop = 0;	
	ptr1 = stack;			/*ambos os ponteiros recebem o endere�o inicial do vetor*/
	ptr2 = stack;			/*ptr2 ser� fixo, ter� valor do index0 e servir� como refer�ncia p/ efetuar a compara��o de endere�o c/ ptr1 que ser� vari�vel*/
	printf("Demonstracao pratica de aplicacao de aritmetica de ponteiros\n");
	printf("Pilha de dados (Last In First Out)\n\n");
	system("PAUSE");
	system("CLS");
	for( ; ; )				/*loop*/
		{
			printf("- - - M E N U - - -\n");
			printf("1 - mostrar pilha\n");
			printf("2 - inserir um dado\n");
			printf("3 - remover dado atual\n");
			printf("4 - sair\n\n");
			printf("---> ");
			scanf("%d", &option);
			switch(option)
				{
					case 1:
						displayStack();
						break;
					case 2:
						push();
						break;
					case 3:
						pop();
						break;
					case 4:
						exit(0);

				}
			system("CLS");
		}
	system("PAUSE");					/*pausa execu��o*/
	return 0;						/*retorna 0, se main() for executada*/
} /* Fim da fun��o principal */

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Desenvolvimento das fun��es */

/* --- Fun��o para mostrar todo conte�do da pilha --- */
void displayStack()
{
	register int i;
	if (ptr1 == ptr2)							/*compara��o de endere�os, se ptr1 estiver no endere�o do index0 a pilha estar� vazia*/
			printf("STACK_NULL\n");
	else										/*se n�o, ir� mostrar os valores*/
		for(i=0; i<stackTop; i++)
				printf("Stack level %2d:  %d\n", i, stack[i]);
	/*printf("ptr1--: %X\n", ptr1);*/				/*DEBUG*/
	/*printf("stackTop: %d\n", stackTop);*/			/*DEBUG*/
	system("PAUSE");
}

/* --- Fun��o para inserir dados na pilha --- */
void push()
{
	register long timer;						/*vari�vel para delay p/ ser poss�vel visualizar a msg*/
	if (ptr1 == (ptr2 + LEVELS))				/*compara��o de endere�os, se ultrapassar o limite da pilha, indica o estouro e sai do programa*/
		{
			printf("STACK_OVERFLOW\n");
			system("PAUSE");
			exit(0);
		}
	else										/*se n�o, solicita um valor p/ add na pilha e imprime msg de adicionado*/
		{
			printf("Digite um dado: ");
			scanf("%d", &stackData);
			printf("Added\n");
		}

	for(timer = 0; timer < 1E8; timer++);		/*delay*/
	
	*ptr1 = stackData;							/*neste ponto, guarda o valor digitado no endere�o atual da pilha*/
	ptr1++;										/*incrementa ptr1, p/ apontar p/ o pr�ximo endere�o*/
	stackTop++;									/*incrementa o topo*/
}

/* --- Fun��o para remover dados da pilha --- */
int pop()
{
	register long timer;						/*vari�vel de delay p/ ser poss�vel visualizar a msg*/
	if (ptr1 == ptr2)							/*compara��o de endere�os, se ptr1 estiver no endere�o do index0 a pilha estar� vazia*/
		{
			printf("STACK_EMPTY\n");
			ptr1 = stack;						/*no caso de querer apagar logo que inicia o programa, volta ptr1 para o index0*/
		}
	else
		{
			printf("Removed\n");				/*se n�o, imprime msg de remo��o*/
			ptr1--;								/*decrementa ptr1, retrocede um endere�o da pilha*/
			stackTop--;							/*decrementa o topo*/
		}

	for(timer = 0; timer < 1E8; timer++);		/*delay*/

	/*printf("ptr1--: %X\n", ptr1);*/				/*DEBUG*/
	/*printf("stackTop: %d\n", stackTop);*/			/*DEBUG*/
	/*system("PAUSE");*/							/*DEBUG*/
	return *(ptr1 + 1);							/*retorna o conte�do do endere�o atual*/
}

/* --- Fun��o para mostrar os endere�os da pilha --- */
void displayStackAddresses()
{
	register int i;
	for(i = 0; i < LEVELS; i++)
		printf("Stack level%2d    Address(Hex): %X    Value: %d\n", i, &stack[i], stack[i]);
	putchar('\n');
	system("PAUSE");
}


/*-------------------------------------------------------------------------------

                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                                                                                           
-------------------------------------------------------------------------------*/
/* final do programa  */

