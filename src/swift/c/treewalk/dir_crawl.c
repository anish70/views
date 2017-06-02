#include <iostream>
#include <stdio.h>
#include <queue>
#include "dir_crawl_helper.h"

using namespace std;

static int dir_crawl(char *root)
{
	int file_count = 0;
	char *file = NULL;
	// 1. declare a Queue 
	// 2. find all subdirs of root
	// 3. enqueue each subdir to queu
	// 4. for each subdir that is dequeued from the queue
	// 5. start a dir_crawl(dequeued entry)

	DIR *dir = opendir(root);

	if (dir == NULL) {
		free(root);
		return 0;
	}


	while ((file = next_file(root, dir)) != NULL) {
		if (file_type(file) == FILE_TYPE_DIR) {
			// 3. 
			file_count += dir_crawl(file);
		} else {
			free(file);
			file_count++; // Anything other than DIR, treat it as regular file.
		}
	}

	closedir(dir);

	free(root);

	return file_count;
}

int main(int argc, char const *argv[])
{

	if (argc != 2) {
		printf("Usage: %s <directory name>\n", argv[0]);
		return -1;
	}

	char *root_dir = (char *)argv[1];

	char *root = (char *)malloc(strlen(argv[1] + 1));
	strcpy(root, root_dir);

	int file_count = dir_crawl(root);

	if (file_count < 0) {
		printf("Failed to read the directory - %s\n", root_dir);
		return -1;
	}

	printf("Total File count in directory %s = %d\n", root_dir, file_count);

	return 0;
}
