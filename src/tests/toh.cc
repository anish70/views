#include <iostream>
 
using namespace std;
 

void
hanoi(int diskSize, int source, int dest, int spare)
{
	//This is our standard termination case. We get to here when we are operating on the 
	//smallest possible disk.
	if(diskSize == 0) {
		cout << "Move disk " << diskSize << " from peg " << source << " to peg " << dest << endl;
	} else {
		//Move all disks smaller than this one over to the spare.
		//So if diskSize is 5, we move 4 disks to the spare. This leaves us with 1 disk
		//on the source peg.
		//Note the placement of the params.
		//We are now using the dest peg as the spare peg. This causes each recursion to ping-pong
		//the spare and dest pegs.
		hanoi(diskSize - 1, source, spare, dest);

		//Move the remaining disk to the destination peg.
		cout << "Move disk "  << diskSize << " from peg " << source << " to peg " << dest << endl;

		//Move the disks we just moved to the spare back over to the dest peg.
		hanoi(diskSize - 1, spare, dest, source);
	}
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
	cout << "usage: " << argv[0] << " <num-pegs>" << endl;
	exit(0);
  }

  //Move all 3 disks from peg 0 to peg 1 using peg 2 as a temporary.
  hanoi(atoi(argv[1]) -1, 0, 1, 2);
}
