Assignment:
  The provided hash table ("HT") code contains the following:
    Command Processor (main pthread)
    Load Generator (child pthread)
  Command Processor performs:
    Asks operator for # HT entries & (initial) number of HT buckets
    Provisions (initial) number of HT "buckets"
    Populates HT with entries having:
      key  == HT entry "number" (from 1 to requested #)
      hits == 0 (updated by Load Generator)
      Hash function to determine which HT bucket is key % # HT buckets
    Launches this Load Generator
    Asks operator for the okay to terminate the test
    Terminates the test and exits the program
  Load Generator performs:
    Picks a random key (from 1 to requested # of HT entries)
    Finds the entry in the HT
    Increments the entry's "hits"
    Loops back until killed
  Modify Command Processor to, in addition to running the Load Generator, also:
    Ask operator for number of Load Generators to run and launch them all
    Ask operator for new number of HT buckets
    Performs a migration from the initial HT buckets to the new HT buckets
    Discussion: How would you re-order HT buckets based upon LRU or MFU
