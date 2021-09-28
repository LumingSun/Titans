#include <unistd.h>

int main(){
    // output eqip, content, size
    char content[] = "Luming\n";
    write(1,content,9);
    return 0;
}