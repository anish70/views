#!/usr/bin/env ruby

# Confirm that user wants to wipe everything on the same hard drive
# as the partition the user selects.


def display_partitions(partition_name: nil, partition_file: "./partitions")
  # Read the partition information from a file, and display all the partitions
  # that share a major number with the provided name of the partition.
  
  # If no partition is provided, display all partitions.
end


def format_drive_for_partition(partition_name)
  # Let's pretend that this actually formats the drive...
  puts 'Formatting the drive with "%s" and its friends...' % partition_name
end


def ask(question)
  puts question
  return gets.strip
end


def main()
  display_partitions()

  partition_name = ask(
    'which partition would you like to format? (e.g. sda1) ')
  display_partitions(partition_name: partition_name)
  confirm = ask('are you sure? [y/n] ')
  if confirm == 'y' then
    puts 'your funeral...'
    format_drive_for_partition(partition_name)
  else
    puts 'nice save...'
  end
end

main()
