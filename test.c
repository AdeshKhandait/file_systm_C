#include<stdio.h>
#include "fs.h"

void main() {

    // Create fs    
    create_fs();
    // write fs
    sync_fs();
    printf("Done!\n"); 

}