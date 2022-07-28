#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5000
#define Nlinhas 11
#define Ncolunas 10

//Função LerDados

char *lerDados(){
    printf("Insira sua string: ");
	char *str = (char *)malloc(TAM * sizeof(char));
	gets(str);
	
	return str;
}

//Descripto/Criptografia Força de Massoud

int trechoIgual(char *str, char *sub){
    int i;
    int qt_str=strlen(str);
    int qt_sub=strlen(sub);
    int qt;

    if(qt_str >= qt_sub)
        qt = qt_sub;
    else
        return 0;
        
    for(i=0;i<qt;i++){
        if(str[i] != sub[i]){
            return 0;
        }
    }
    return 1;
}

int ehSubstring(char *sub, char *str){
    int i,j=0;
    int qt = strlen(str);
    char *nstr = (char *)malloc(TAM * sizeof(char));

    for(i=1;i < qt;i++){
        if(str[i] == sub[0]){
            if(trechoIgual(&str[i], sub))
                 return 1;
        }
    }
    return 0;
}

char *cripForcaMassoud(char *str){
	int i = 0;
	
	char *nstr = (char *)malloc(TAM * sizeof(char));
	strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0
	
	char letra;
    int posIn, posFim;
	
	while(str[i] != '\0'){
		letra = str[i];
		
		switch(str[i]){
			
			case 'a':
				strcat(nstr, "M@ssoud1");
			break;
			
			case 'e':
				strcat(nstr, "M@ssoud2");
			break;
			
			case 'i':
				strcat(nstr, "M@ssoud3");
			break;
			
			case 'o':
				strcat(nstr, "M@ssoud4");
			break;
			
			case 'u':
				strcat(nstr, "M@ssoud5");
			break;
			
			case 'P':
				strcat(nstr, "M@ssoud");
			break;
			
			case 'A':
				strcat(nstr, "M@ssoud1P");
			break;
			
			case 'E':
				strcat(nstr, "M@ssoud2P");
			break;
			
			case 'I':
				strcat(nstr, "M@ssoud3P");
			break;
			
			case 'O':
				strcat(nstr, "M@ssoud4P");
			break;
			
			case 'U':
				strcat(nstr, "M@ssoud5P");
			break;
			
			default:
				strncat(nstr,&letra,1);
		}
		i++;
	}
	
	return nstr;
}

char *descripForcaMassoud(char *strcrip){
    int i,j=0;
    int qt = strlen(strcrip);

    char mtz[Nlinhas][Ncolunas]={"M@ssoud","M@ssoud1","M@ssoud2","M@ssoud3","M@ssoud4","M@ssoud5","M@ssoud1P","M@ssoud2P","M@ssoud3P","M@ssoud4P","M@ssoud5P"};

    char *nstr = (char *)malloc(TAM * sizeof(char));
	strcpy(nstr, "M@ssoud"); //aloco vazio por conta do malloc não alocar \0
    
    char *nstrdescrip = (char *)malloc(TAM * sizeof(char));
	strcpy(nstrdescrip, ""); //aloco vazio por conta do malloc não alocar \0

    for(i=0;i < qt;i++){
        if(strcrip[i] == 'M'){

            if((trechoIgual(&strcrip[i], mtz[10])) == 1){

                strncat(nstrdescrip,"U",1);
                i+=(strlen(mtz[10])-1);

            }else if((trechoIgual(&strcrip[i], mtz[9])) == 1){

                strncat(nstrdescrip,"O",1);
                i+=(strlen(mtz[9])-1);

            }else if((trechoIgual(&strcrip[i], mtz[8])) == 1){

                strncat(nstrdescrip,"I",1);
                i+=(strlen(mtz[8])-1);

            }else if((trechoIgual(&strcrip[i], mtz[7])) == 1){

                strncat(nstrdescrip,"E",1);
                i+=(strlen(mtz[7])-1);

            }else if((trechoIgual(&strcrip[i], mtz[6])) == 1){

                strncat(nstrdescrip,"A",1);
                i+=(strlen(mtz[6])-1);

            }else if((trechoIgual(&strcrip[i], mtz[5])) == 1){

                strncat(nstrdescrip,"u",1);
                i+=(strlen(mtz[5])-1);

            }else if((trechoIgual(&strcrip[i], mtz[4])) == 1){

                strncat(nstrdescrip,"o",1);
                i+=(strlen(mtz[4])-1);

            }else if((trechoIgual(&strcrip[i], mtz[3])) == 1){

                strncat(nstrdescrip,"i",1);
                i+=(strlen(mtz[3])-1);

            }else if((trechoIgual(&strcrip[i], mtz[2])) == 1){

                strncat(nstrdescrip,"e",1);
                i+=(strlen(mtz[2])-1);

            }else if((trechoIgual(&strcrip[i], mtz[1])) == 1){

                strncat(nstrdescrip,"a",1);
                i+=(strlen(mtz[1])-1);

            }else if((trechoIgual(&strcrip[i], mtz[0])) == 1){

                strncat(nstrdescrip,"P",1);
                i+=(strlen(mtz[0])-1);

            }else{

                strncat(nstrdescrip,&strcrip[i],1);

            }
        }else
            strncat(nstrdescrip,&strcrip[i],1);
    }
    
    return nstrdescrip;
}

//Descripto/Criptografia FRN

char *cripPrefixoFRN(char *str, int *c){
	
	int i = 0, cont = 0;
	
	char *nstr1 = (char *)malloc(TAM * sizeof(char));
	strcpy(nstr1, ""); //aloco vazio por conta do malloc não alocar \0
	
	while(str[i] != '\0'){
		
		switch(str[i]){
			
			case 'a':
				cont++;
			break;
			
			case 'm':
				cont++;
			break;
			
			case 'A':
				cont++;
			break;
			
			case 'M':
				cont++;
			break;
		}	
		i++;
	}
	
	for(i=0;i<cont;i++)
		strcat(nstr1, "FRN");

	strcat(nstr1, str);
	
	*c = cont;
	
	return nstr1;
}

char *descripPrefixoFRN(char *strcrip, int *c){
    int i;
    char *nstr = (char *)malloc(TAM * sizeof(char));
	strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0

    i = *c * 3;

    for(i=i; strcrip[i]!='\0';i++){
        strncat(nstr,&strcrip[i],1);
    } 

    return nstr;
}

//Descripto/Criptografia Quase Total

char *cripQuaseTotal(char *str, int *posIn, int *posFim){
	
	int i;
	int tam = strlen(str);

	char *novastr = (char *)malloc(TAM * sizeof(char));
	strcpy(novastr, ""); //aloco vazio por conta do malloc não alocar \0
	
	if((tam % 2) != 0){
		
		for(i=tam; i>=0;i--){
			strncat(novastr, &str[i],1);
		}
        *posIn = -1;
        *posFim = -1;
	}else{

        int tamPar = tam / 2;
        for(i=tam; i>=0;i--){
			strncat(novastr, &str[i],1);
            if(i == tamPar){
                strcat(novastr, "LDP");
                *posIn = i+1;
                *posFim = *posIn+2;
            }
		}
  }
	
	return novastr;
}

char *descripQuaseTotal(char *strcrip, int *posIn, int *posFim){
    int i;
    int tam = strlen(strcrip);
    char *nstr = (char *)malloc(TAM * sizeof(char));
	strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0
    
    if(*posIn > -1 ){
        for(i=tam;i>=*posFim;i--){
            strncat(nstr, &strcrip[i],1);
        }

        for(i=*posIn-2;strcrip[i] != '\0';i--){
            strncat(nstr, &strcrip[i],1);
        }
    }else{
        for(i=tam; i>=0;i--){
			strncat(nstr, &strcrip[i],1);
		}
    }

  return nstr;
}

//Descripto/Criptografia do Leão

char *cripConversao(char *s){
    int i, tam, result;

    char *aux_s = (char *) malloc( TAM * sizeof( char ));
    strcpy(aux_s, ""); //aloco vazio por conta do malloc não alocar \0

    char *aux_s1 = (char *) malloc( TAM * sizeof( char ));
    strcpy(aux_s1, ""); //aloco vazio por conta do malloc não alocar \0

    char letraMenor = s[0];
    char letraMaior = s[0];

    tam = strlen(s);

    //Definindo Maior letra

    for(i = 1; i < tam ;i++){
        if(s[i] > letraMaior){
            letraMaior = s[i];
        }else if(s[i] < letraMenor){
            letraMenor = s[i];
        }
    }

    result = (letraMaior - letraMenor);
    strcat(aux_s1, s);
    sprintf(aux_s, "%d", result);//operador diferente a ser estudado
    strcat(aux_s1, aux_s);

    return aux_s1;
}

char *descripConversao(char *strcrip){

    int qt = strlen(strcrip);
    int i;
    int cont=0;
    char *aux_s = (char *) malloc( TAM * sizeof( char ));
    strcpy(aux_s, ""); //aloco vazio por conta do malloc não alocar \0

    for(i=0;i < qt;i++){

        switch(strcrip[i]){
            
            case '1':
                cont++;
            break;

            case '2':
                cont++;
            break;

            case '3':
                cont++;
            break;

            case '4':
                cont++;
            break;

            case '5':
                cont++;
            break;

            case '6':
                cont++;
            break;

            case '7':
                cont++;
            break;

            case '8':
                cont++;
            break;

            case '9':
                cont++;
            break;

            case '0':
                cont++;
            break;
        }
    }

    for(i=0;i < (qt - cont);i++)
        strncat(aux_s,&strcrip[i],1);

    return aux_s;
}

char *JuntarCrips(char *str, int *c, int *posInJun, int *posFimJun){

    char * nstr = (char *) malloc( TAM * sizeof( char ));
    strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0
    nstr = cripForcaMassoud(str);
    nstr = cripPrefixoFRN(nstr, c);
    nstr = cripQuaseTotal(nstr, posInJun, posFimJun);
    nstr = cripConversao(nstr);

    return nstr;
}

char *descripJuntar(char *strcrip, int *c, int *posInJun, int *posFimJun){

    char * nstr = (char *) malloc( TAM * sizeof( char ));
    strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0
    
    nstr = descripConversao(strcrip);
    nstr = descripQuaseTotal(nstr, posInJun, posFimJun);
    nstr = descripPrefixoFRN(nstr, c);
    nstr = descripForcaMassoud(nstr);

    return nstr;
}

char **alocarMatriz(int qtLinha, int qtColuna){
    int i=0;
    char **mtz;
    mtz = (char **)calloc(qtLinha , sizeof(char *));
    
    for(i = 0; i < qtLinha; i++)
        mtz[i] = (char *)calloc(qtColuna , sizeof(char));
    return mtz;
}

int contarSubs(char *s){
    int i,cont=0;
    int tam = strlen(s);

    for(i=0;i < tam;i++)
        if(s[i] == ' ')
            cont++;
    cont++;
    return cont;
}

char **mystrtok( char * s){
    
    int i,j=0,cont=0;
    cont = contarSubs(s);
    int tam = strlen(s);
    char **mtz = alocarMatriz(cont,tam);

    int k = 0;
    for(i=0;i < tam;i++){

        if(s[i] == ' '){
            j++;
            k=0;
        }else{
            mtz[j][k] = s[i];
            k++;
        }
        
    }

    return mtz;
}

char *criptografaDados(char *str,int *contFun, int *posIn, int *posFim, int *posInJun,int *posFimJun){

    int i=0,j=0,cont=0,cont2=1;
    cont = contarSubs(str);
    int contFunJun = *contFun;
    int tam = strlen(str);
    char **aux;
    char * nstr = (char *) malloc( TAM * sizeof( char ));
    strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0

    aux = mystrtok(str);

    /*for (i = 0;i < cont;++i)
        printf("\na %d-ésima é:%s\n", i, aux[i]);*/
    
    while(cont > 0){

        switch(cont2){
                
            case 1:
                aux[j] = cripForcaMassoud(aux[j]);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;    
            break;

            case 2:
                aux[j] = cripPrefixoFRN(aux[j], contFun);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;
            break;
                    
            case 3:
                aux[j] = cripQuaseTotal(aux[j], posIn, posFim);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;    
            break;

            case 4:
                aux[j] = cripConversao(aux[j]);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;
            break;

            default:
                aux[j] = JuntarCrips(aux[j], &contFunJun, posInJun, posFimJun);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2 = 1;
                j++;
            break;
        }
        cont--;
    }
    
    return nstr;
}

char *descriptografaDados(char *str, int *contFun, int *posIn, int *posFim,int *posInJun, int *posFimJun){

    int i=0,j=0,cont=0,cont2=1;
    cont = contarSubs(str);
    int contFunJun = *contFun;
    int tam = strlen(str);
    char **aux;
    char * nstr = (char *) malloc( TAM * sizeof( char ));
    strcpy(nstr, ""); //aloco vazio por conta do malloc não alocar \0

    aux = mystrtok(str);

    //for (i = 0;i < (cont-1);++i)
        //printf("\na %d-ésima é:%s\n", i, aux[i]);
    
    while(cont > 0){

        switch(cont2){
                
            case 1:
                aux[j] = descripForcaMassoud(aux[j]);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;    
            break;

            case 2:
                aux[j] = descripPrefixoFRN(aux[j], contFun);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;
            break;
                    
            case 3:
                aux[j] = descripQuaseTotal(aux[j], posIn, posFim);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;    
            break;

            case 4:
                aux[j] = descripConversao(aux[j]);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2++;
                j++;
            break;

            default:
                aux[j] = descripJuntar(aux[j], &contFunJun, posInJun, posFimJun);
                strcat(nstr, aux[j]);
                strncat(nstr, " ",1);
                cont2 = 1;
                j++;
            break;
        }
        cont--;
    }
    
    return nstr;
}
//char *descriptografaDados(char *str){}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	//Declaração de Variáveis
	
	char *string, *chamarCrips, *chamarCrip,*chamarCrip2,*chamarCrip3,*chamarCrip4,*chamarDescrips;
	int cont,InPosIn,InPosFim, InPosInJun, InPosFimJun;

	//Chamada da função LerDados
	
	string = lerDados();
	printf("\nA string antes da Criptografia é: %s", string);

    chamarCrips = criptografaDados(string,&cont,&InPosIn,&InPosFim,&InPosInJun,&InPosFimJun);
    printf("\n\n%s", chamarCrips);

    chamarDescrips = descriptografaDados(chamarCrips,&cont,&InPosIn,&InPosFim,&InPosInJun,&InPosFimJun);
    printf("\n\n%s", chamarDescrips);
}	