/*

C dilinde Stackleri kullanarak parantezlerin e�le�tirme kontrol�
                       Hasan Berat S�ke
            Bili�im Sistemleri M�hendisli�i 2.s�n�f
          
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#define boyut 10
char dizi[boyut];
char stack[boyut];
int tepe;

void push(char data){
	if(tepe +1 == boyut){
		puts("stack doludur");
		
	}else{
		/*ilk ba�ta tepe de�erini artt�rs�n, sonra data de�erini atas�n*/
		stack[++tepe] = data; 
	}
}

char peek (){
	return stack[tepe];
}

char pop(){
	return stack[--tepe];
}

bool bosmu(){
	if(tepe == 0){
		return true;
	}else{
		return false;
	}
}

void yazdir(){
	int j;
	for(j = 0 ; j <tepe ; j++){
		printf("stack: %c", stack[j]);
	}
}

bool dogruMu(){
	int i ; 
	/*dizi bitene kadar while d�ng�s� d�n�yor.*/
	while(dizi[i] != '\0'){
		char d = dizi[i];
		printf("\ndata: %c", d);
		
		if(d=='(' || d=='{' || d== '['){
			push(d);
			printf("\npush edildi: %c", d);
		}
		else if (d==')' || d=='}' || d== ']'){
				char peekd = peek();
			printf("\npeed edildi: %c", peekd);
			if(bosmu() == true){
				puts("stack bo�tur ...");
				return false;
			}
		
			/* parantezler birbirinin k�yasl�yormu ? */
			if(d ==')' && peekd=='('){
				pop();
			}
				if(d =='}' && peekd=='{'){
				pop();
			}
				if(d ==']' && peekd=='['){
				pop();
			}else{
				return false;
			}
			
			
		}
		
		
		
		
		i+=1;
	}
	/*while d�ng�s� bitti�inde stack kontrol�*/
	yazdir();
	return bosmu();
}





int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Turkish");
	
	/* kullan�c�nda input alma (dizi)*/
	puts("de�erleri giriniz");
	fgets(dizi, sizeof(dizi), stdin);


if(dogruMu () == true){
	puts("\ndo�ru");
}else{
	puts("\nyanl��");
	yazdir(); // hata c�kratan eleman bast�r�ld�.
}
	
	return 0;
}
