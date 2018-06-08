// atpun - quatrieme travail de programmation.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"

long int primo(int p); // PROTÓTIPO
long int repeat(); // PROTÓTIPO
int happyn(int h); // PROTÓTIPO
long int mersene(int n); // PROTÓTIPO
long double fatst(double n); // PROTÓTIPO

int main() {
	setlocale(LC_ALL, "Portuguese"); // PERMITIR CARACTERES DA LÍNGUA PORTUGUESA
	int fs = 2;
	do {
		int op; // OPÇÃO INTEIRA DECLARADA
		do {
			printf(PROBLEMA01); // OPÇÃO 1
			printf(PROBLEMA02); // OPÇÃO 2
			printf(PROBLEMA03); // OPÇÃO 3
			printf(PROBLEMA04); // OPÇÃO 4
			printf(PROBLEMA05); // OPÇÃO 5
			printf(PROBLEMA06); // OPÇÃO 6
			printf("\n\nDIGITE O NÚMERO DA QUESTÃO: "); // AQUI PEDE A QUESTÃO POR OPÇÃO
			scanf("%d", &op); // RECEBER OPÇÃO
			if ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5) && (op != 6)) { // CONDIÇÃO PARA DIZER QUE ESTÁ ERRADO
				printf(ERRO); // MENSAGEM DE ERRO
				_getch(); // AGUARDA ALGUMA TECLA
				system("cls"); // LIMPA A TELA DO CMD
			}
		} while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5) && (op != 6)); // LOOP CONDICIONAL CASO OS VALORES INSERIDOS NÃO FOREM O QUE FOI PEDIDO
		switch (op) { // SWITCH DA OPÇÃO
		case (1): { // OPÇÃO 1
			int i = 4;
			while (i <= 1000) { // LOOP
				int moyen = (i / 2), p = 2, n; // MOYEN É A METADE DO NÚMERO COM UMA SEGURANÇA, P É O PRIMEIRO NÚMERO PRIMO E N, O SEGUNDO
				while (p <= moyen) {
					n = i - p;
					if ((primo(p)) && (primo(i - p))) {
						printf("%d: (%d,%d)\n", i, p, n);
					}
					p++;
				}
				i++; // PRÓXIMO NÚMERO
			}
			_getch();
			_getch(); // AGUARDA ALGUMA TECLA
			break;
		} // FIM DA OPÇÃO 1
		case 2: { // OPÇÃO 2
			int a, b; // INICIO E FIM DO INTERVALO, NÃO RESPECTIVAMENTE
			do {
				printf("DIGITE O VALOR DE A: ");
				scanf("%d", &a);
				if (a < 0) {
					printf(ERRO);
					_getch();
					system("cls");
				}
			} while (a < 0);
			do {
				printf("DIGITE O VALOR DE B: ");
				scanf("%d", &b);
				if (b < 0) {
					printf(ERRO);
					_getch();
					system("cls");
				}
			} while (b < 0);
			if (a >= b) {
				int i = b;
				while (i <= a) {
					if (primo(i)) {
						printf("%d\n", i);
					}
					i++;
				}
			}
			if (b > a) {
				int i = a;
				while (i <= b) {
					if (primo(i)) {
						printf("%d\n", i);
					}
					i++;
				}
			}
			_getch();
			_getch();
			break;
		} // FIM DA OPÇÃO 2
		case 3: { // OPÇÃO 3
			int a, b, i, o; // INICIO E FIM DO INTERVALO, NÃO RESPECTIVAMENTE
			do {
				printf("DIGITE O VALOR DE A: ");
				scanf("%d", &a);
				if (a < 0) {
					printf(ERRO);
					_getch();
					_getch();
					system("cls");
				}
				else {
					do {
						printf("DIGITE O VALOR DE B: ");
						scanf("%d", &b);
						if (b < 0) {
							printf(ERRO);
							_getch();
							_getch();
							system("cls");
						}
					} while (b < 0);
				}
			} while (a < 0);
			if (a <= b) {
				i = a;
				while (i <= b) {
					o = i + 1;
					if (primo(i)) {
						printf("(%d,", i);
						while (o <= b + 10) {
							if (primo(o)) {
								printf("%d)\n", o);
								break;
							}
							o++;
						}
					}
					i++;
				}
			}
			else {
				i = b;
				while (i <= a) {
					o = i + 1;
					if (primo(i)) {
						printf("(%d,", i);
						while (o <= a + 10) {
							if (primo(o)) {
								printf("%d)\n", o);
								break;
							}
							o++;
						}
					}
					i++;
				}
			}
			_getch();
			_getch();
			break;
		} // FIM DA OPÇÃO 3
		case 4: { // OPÇÃO 4
			int i = 1, lim = 30, m;
			printf("TODOS OS NÚMEROS PRIMOS DE MERSENE PARA (1 <= N <= 30):\n");
			while (i <= lim) {
				m = mersene(i);
				if (primo(m)) printf("%d*\n", m);
				else printf("%d\n", m);
				i++;
			}
			printf("\nCOM ASTERISCO É PRIMO\n");
			_getch();
			_getch();
			break;
		} // FIM DA OPÇÃO 4
		case 5: { // OPÇÃO 5
			int i = 4;
			printf("\nNÚMEROS FELIZES:\n");
			while (i <= 1000) {
				if (happyn(i)) printf("%d ", i);
				// else printf("%d\n", i);
				i++;
			}
			i = 4;
			/*printf("\n\nNÚMEROS TRISTES:\n");
			while (i <= 1000) {
			if (happyn(i));
			else printf("[%d]", i);
			i++;
			}*/
			// printf("\nCOM ASTERISCO É FELIZ\n");
			printf("\n");
			_getch();
			_getch();
			break;
		} // FIM DA OPÇÃO 5
		case 6: { // OPÇÃO 6
			int i = 1;
			// printf("DIGITE UM NÚMERO INTEIRO (0 <= N <= 30): ");
			// scanf("%d", &n);
			printf("FATORIAL DE 0 A 30:\n");
			while (i <= 30) {
				printf("%.0lf\n", fatst(i));
				i++;
				// printf("FATORIAL A PARTIR DA FÓRMULA DE STIRLING DO NÚMERO %d É APROXIMADAMENTE %.0lf", i, fatst(i));
			}
			_getch();
			_getch();
			break;
		} // FIM DA OPÇÃO 6
		} // FIM DO SWITCH
		printf("\nDESEJA REPETIR O CÓDIGO (S/N): ");
	} while (repeat()); // SE A OPÇÃO 'REPETIR' FOR SIM, ENTÃO, REPETIRÁ O CÓDIGO
	return 0;
}

long int primo(int p) { // FUNÇÃO PARA VERIFICAR SE UM NÚMERO (>= 2) É PRIMO
	int i = 3, exp = (int)sqrt((double)p) + 1;
	if (p == 2) return 1;
	if (p % 2 == 0) return 0;
	for (; i <= exp; i += 2)
		if (p%i == 0) return 0;
	if (p < 2) return 0;
	return 1;
}

long int repeat() { // FUNÇÃO PARA PERGUNTAR SE QUER REPETIR O CÓDIGO OU NÃO
	int rep;
	do {
		// system("cls");
		// printf("DESEJA REPETIR O CÓDIGO (S/N): ");
		rep = getchar();
		rep = toupper(rep);
	} while ((rep != 'S') && (rep != 'N'));
	if (rep == 'S') {
		system("cls");
		return 1;
	}
	else {
		printf("\nMADE BY GOD DOUG, É NÓIS QUE VOA");
		_getch();
		return 0;
	}
}

int happyn(int h) {
	int i, reposer, s = 0;
	while (s != 1 && s != 4) { // SE FOR UM JÁ É FELIZ E SE FOR QUATRO É INFELIZ, INDO ENTÃO PARA A CONDIÇÃO ABAIXO DESSA INSTRUÇÃO
		s = 0; // INICIO DE UM NOVO NÚMERO SEMPRE COMEÇANDO COMO ZERO
		while (h > 0) { // POR VENTURA O NÚMERO APÓS ALGUM TEMPO, SERÁ 0, DEVIDO A SUA DIVISÃO ABAIXO
			reposer = h % 10; //  RESTO
			s += pow(reposer, 2); // RESTO ELEVADO A DOIS SOMADO A UM NOVO NÚMERO QUE INICIALMENTE É ZERO
			h /= 10; // DIVISÃO DO NÚMERO PARA LOOP
		}
		h = s; // NÚMERO RECEBE NOVO NÚMERO
	}
	if (s == 1) return 1; // AO FINAL DE TUDO, SE O NOVO NÚMERO FOR 1, ENTÃO O NÚMERO É FELIZ
	else return 0;
}

long int mersene(int n) { // MERSENE
	long int ms = pow(2, n) - 1; // DEFINIÇÃO
	return (ms);
}

long double fatst(double n) { // FATORIAL POR STIRLING
	long double dr, neul, fatr;
	dr = sqrt(2 * PI*n);
	neul = pow((n / EUL), n);
	fatr = dr * neul;
	return (fatr);
}