(Setup for interviewer: draw a single-indirect and double-indirect FS
tree on the whiteboard.)

Given an N-level indirect FS, 4K blocks, and 500 entries/level, write
a function or macro to compute the index in the block to use in order
to find the given offset.

The file is dense, i.e. an N-byte file has N bytes allocated for it,
numbered 0 to N-1.

An indirect block is an array of device block numbers.

Example:

#define ENTRIES 500
#define BLOCK_SIZE 4096


In that case, we'd have

next_block_index(0, 1) = 0
next_block_index(0, 4095) = 0
next_block_index(0, 4096) = 1
next_block_index(5000, 1) = 1
next_block_index(409600, 1) = 100

next_block_index(2048000, 2) = 1   /* that's 500 * 4096 */