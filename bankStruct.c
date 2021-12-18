#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct users {
	char number[25];
	int type;
	char name[30];
	char adress[100];
	char phone[15];
	float balance;
	int identity;
} account[777];

struct transactions {
	char code[30];
	char date;
	char number2[25];
	float bss;
} data[777];

int main() {
	int pass;
	int i;
	int tSelect;
	char transfer[25];
	int qBalance;
	int qTransfer;
	int quantity;
	int attemps;
	int comp;
	int qFirst;
	int identityComp;
	int qSecond;
	int showD;


	for (i = 0; i < 777; i++) {
		printf("\nDesea crear cuenta bancaria? Si(1) / No(0)\n");
		scanf("%d", &qFirst);
		if (qFirst == 1) {
			printf("\nDesea ingresar al banco?(cuenta nueva) Si(1) / No(0) \n");
			scanf("%d", &pass);
		} else if (qFirst == 0) {
			pass = 0;
			for (int se = 0; se <= 777; se++) {
				printf("\nIngrese su cedula\n");
				scanf("%d", &identityComp);
				for (int se2 = 0; se2 <= 777; se2++) {
					if (identityComp == account[se2].identity) {
						i = se2;
						se = se2;
						break;
					}
				}
				if(identityComp != account[se].identity) {
					printf("\nHa escrito mal la cedula, vuelva a intentar(1) o cree una nueva cuenta(0)\n");
					scanf("%d", &qSecond);
					if (qSecond == 1) se = 0;
					else if (qSecond == 0) main();
				} else break;

			}

		}

		if (pass == 1) {
			account[i].balance = rand() % 1200;
			fflush(stdin);
			printf("Escriba su numero de cuenta: ");
			gets(account[i].number);

			fflush(stdin);
			printf("\nAhorro 		 / 1\nCorriente 	 / 2\nActivos Liquidos / 3\nOtros 		 / 4\nSeleccione tipo de cuenta: ");
			scanf("%d", &tSelect);

			fflush(stdin);
			printf("Escriba su nombre: ");
			gets(account[i].name);

			fflush(stdin);
			printf("Escriba su direccion: ");
			gets(account[i].adress);

			fflush(stdin);
			printf("Escriba su numero de telefono: ");
			gets(account[i].phone);

			fflush(stdin);
			printf("Escriba su Cedula de Identidad: ");
			scanf("%d", &account[i].identity);

			printf("Desea verificar su saldo? Si(1) / No(0)");
			scanf("%d", &qBalance);
			if (qBalance == 1) {
				printf("Su saldo es de: %.2f Bss\n", account[i].balance);
			}
		}
		if (pass == 0) {
			do {
				printf("Desea realizar una transaccion bancaria? Si(1) / No(0)");
				scanf("%d", &qTransfer);
				if (qTransfer == 1) {
					fflush(stdin);
					printf("A que cuenta deseas transferir?\n");
					gets(transfer);
					for (int x = 0; x <= 777; x++) {
						int comp = strcmp(transfer, account[x].number);
						if (comp == 0) {
							printf("Cuanto desea transferir?\n");
							scanf("%d", &quantity);
							if(quantity > account[i].balance) {
								printf("\nSaldo insuficiente\n");
							} else if (quantity <= account[i].balance) {
								account[i].balance -= quantity;
								account[x].balance += quantity;
								data[i].number2[0] = account[x].number;
								data[i].bss = quantity;
								x = 777;
							}
						} else if (comp != 0){
							printf("\nCuenta no registrada\n Desea volver a intentar? Si(1) / No(0)");
							scanf("%d", &attemps);
							break;
						}
					}
				}
			} while (attemps == 1);
			printf("Desea ver los datos? Si(1) / No(0)");
			scanf("%d", &showD);
			if (showD = 1) show(i, tSelect);
		} else {
			printf("\nHa elegido salir del banco \n\n");
			show(i, tSelect);
			i = 776;
		}
		
	}
	printf("Escriba 1 para mostrar clientes con cuentas Corriente");
	system("pause");
}

void show(index, n) {
	int j = index;
	int ite = index;

	for (j = 0; j < ite; j++) {
		printf("\n\n%s sus datos son:\n", account[j].name);
		printf("\nSu numero de cuenta es: %s\n", account[j].number);
		printf("Su direccion es: %s\n", account[j].adress);
		printf("Su numero de telefono es: %s\n", account[j].phone);
		printf("Su cedula de identidad es de: %d\n", account[j].identity);
		printf("Su saldo es de: %.2f Bss\n", account[j].balance);
	}
	if (n == 1) printf("Su tipo de cuenta es: Ahorro");
	else if (n == 2) printf("Su tipo de cuenta es: Corriente");
	else if (n == 3) printf("Su tipo de cuenta es: Activos Liquidos");
	else if (n == 4) printf("Su tipo de cuenta es: Otros");
	else printf("Tipo de cuenta incorrecto");

	printf("\nClientes con cuenta corriente:\n");
	for(int j2 = 0; j2 <= 777; j2++) {
		if (account[j2].type == 2) {
			printf("%s\n",account[j2].name);
		} else {
			printf("No hay clientes con cuenta corriente\n");
			break;
		}
	}
	printf("Transacciones hechas por clientes con cuenta de ahorros\n");
	for(int j3 = 0; j3 <= 777; j3++) {
		if (account[j3].type == 1 && data[j3].bss > 1) {
			printf("%s\n",account[j3].name);
		} else {
			printf("No hay transacciones hechas por clientes con cuenta de ahorros\n");
			break;
		}
	}
}
