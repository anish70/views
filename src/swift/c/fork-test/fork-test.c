#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void child() {
    for (int i=4; i<=6; i++) {
        printf("C %2d\n",i);
    }
}

int main(int argc, const char * argv[]) {
    for (int i=1; i<=3; i++) {
        printf("P %2d\n", i);
    }

    int pid = fork();
    if (pid == 0) {
	    child();
    } else {

	for (int i=7; i<=9; i++) {
	    printf("P %2d\n", i);
	}
    }

    return 0;
}
