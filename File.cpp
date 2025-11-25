#include <stdio.h>
#include <string.h>

struct kata{
    char singkat[51];
    char asli[51];
};

int main (){
    FILE *wle;
    wle = fopen("testdata.in", "r");
    
    if(wle == NULL) return 1;

    int t, T, idx;
    char kalimat[101];
    
    fscanf(wle, "%d", &t);
    struct kata wih[t];
    
    for (int i = 0 ; i < t; i++){
        fscanf(wle, "%[^#]#%[^\n]", wih[i].singkat, wih[i].asli); 
        fgetc(wle);
    }
    
    fscanf(wle, "%d", &T); 
    fgetc(wle);
    
    for (int tc = 1; tc <= T; tc++){
        fscanf(wle, "%[^\n]", kalimat); 
        fgetc(wle);
        
        int length = strlen(kalimat);
        printf("Case #%d:\n", tc);
        
        idx = 0;
        char buffer[101];
        
        for (int i = 0; i <= length; i++){
            
            if (kalimat[i] == ' ' || kalimat[i] == '\0'){
                buffer[idx] = '\0'; // Tutup buffer
                
                int found = 0;
                for (int j = 0 ; j < t; j++){
                    if (strcmp(wih[j].singkat, buffer) == 0){
                        printf("%s", wih[j].asli);
                        found = 1;
                        break;
                    }
                }
                if (found == 0){
                    printf("%s", buffer);
                }
                
                if (kalimat[i] == ' '){
                    printf(" "); 
                } else {
                    printf("\n"); 
                }
                
                idx = 0;
            } 
            else {
                buffer[idx] = kalimat[i];
                idx++;
            }
        }
    }
    
    fclose(wle);
    return 0;
}
