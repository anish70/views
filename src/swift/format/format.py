#!/usr/bin/python

# Confirm that user wants to wipe everything on the same hard drive
# as the partition the user selects.


def display_partitions(partition_name=None, partition_file="./partitions"):
    """
    Read the partition information from a file, and display all the partitions
    that share a major number with the provided name of the partition.

    If no partition is provided, display all partitions.
    """
    pass


def format_drive_for_partition(partition_name):
  """
  Let's pretend that this actually formats the drive...
  """
  print 'Formatting the drive with "%s" and its friends...' % partition_name

def main():
    display_partitions()
    partition_name = raw_input('which partition would you like '
                               'to format? (e.g. sda1) ')
    display_partitions(partition_name)
    confirm = raw_input('are you sure? [y/n] ')
    if confirm == 'y':
        print 'your funeral...'
        format_drive_for_partition(partition_name)
    else:
        print 'nice save...'


if __name__ == "__main__":
    main()
