#include <stdio.h>
#include <string.h>

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}

int main(){
        const char st[100] = "45524247303031303A5769746864726177616C206F766572206D6178696D756D20706572207472616E73";
        int length = strlen(st);
        char uio[99];
        int i;
        char buf = 0;
        char buf1=0;
        memset(uio,0x00,sizeof(uio));
        for(i = 0; i < length; i++){
                if(i % 2 != 0){
                	buf1 =hex_to_ascii(buf, st[i]);
                    strncat(uio,&buf1,1);
                        
                }else{
                        buf = st[i];
                }
        }
        printf("\n%s",uio);
}
