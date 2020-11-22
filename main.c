/*

C dilinde Stackleri kullanarak parantezlerin eþleþtirme kontrolü
                       Hasan Berat Söke
            Biliþim Sistemleri Mühendisliði 2.sýnýf
          
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
		/*ilk baþta tepe deðerini arttýrsýn, sonra data deðerini atasýn*/
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
	/*dizi bitene kadar while döngüsü dönüyor.*/
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
				puts("stack boþtur ...");
				return false;
			}
		
			/* parantezler birbirinin kýyaslýyormu ? */
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
	/*while döngüsü bittiðinde stack kontrolü*/
	yazdir();
	return bosmu();
}





int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Turkish");
	
	/* kullanýcýnda input alma (dizi)*/
	puts("deðerleri giriniz");
	fgets(dizi, sizeof(dizi), stdin);


if(dogruMu () == true){
	puts("\ndoðru");
}else{
	puts("\nyanlýþ");
	yazdir(); // hata cýkratan eleman bastýrýldý.
}
	
	return 0;
}
