#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fs.h"

/*
struct superblock
{
    int num_inodes;
    int num_blocks;
    int size_blocks;
};

// Inode stores Name and size of the block
struct inode
{
    int size;
    char name[8];
};

// data block
struct disk_block
{
    int next_block_num;
    char data[512]; 
};
*/

// Declaring the structs
struct superblock sb;
struct inode *inodes;
struct disk_block *dbs; 


// Initialize the Files system
void create_fs() {
    // Information about the Super Blocks
    sb.num_inodes = 10;
    sb.num_blocks = 100;
    sb.size_blocks = sizeof(struct disk_block);

    // init inodes
    inodes = malloc(sizeof(struct inode)* sb.num_inodes);
    for (int i = 0; i < sb.num_inodes; i++)
    {
        inodes[i].size = -1;
        strcpy(inodes[i].name,"empfle");
        
    }

    // init blocks
    dbs = malloc(sizeof(struct disk_block) * sb.num_blocks);    
    for (int i = 0; i < sb.num_blocks ; i++)
    {
        dbs[i].next_block_num = -1;
    }
    
}

// Load the File system
void mount_fs();

//Write the file system
void sync_fs() {
    
    FILE *file;
    file = fopen("fs_data","w+");

// Writing the File System

    // Write SuperBlock
    fwrite(&sb, sizeof(struct superblock),1,file);

    // Write Inodes
    for (int i = 0; i < sb.num_inodes; i++)
    {   
        fwrite(&(inodes[i]),sizeof(struct inode),1,file);
    }

    // Write Blocks
    for (int i = 0; i < sb.num_inodes; i++)
    {   
        fwrite(&(dbs[i]),sizeof(struct disk_block),1,file);
    }
    
    fclose(file);
}
