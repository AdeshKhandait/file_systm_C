// Meta Information about the File System
// Number of inodes
// number of disk blocks
// size of the disk blocks

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

// Operation on File System

// Initialize the Files system
void create_fs();

// Load the File system
void mount_fs();

//Write the file system
void sync_fs();