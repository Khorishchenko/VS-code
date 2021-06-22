#include <stdio.h>

int main()
{ 
    int i;
    char c;
    FILE *f,*f2; 

    f = fopen("mytext.txt","r");
    f2 = fopen("s2.txt","w"); 
    
    for(i=0;!feof(f);i++){ 
        fscanf(f,"%c",&c); if(c=='0') c='1'; 
        fprintf(f2,"%c",c); 
    }
    
    fclose(f);
    fclose(f2); 
    return 0;
}