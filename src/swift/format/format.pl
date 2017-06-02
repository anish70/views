#!/usr/bin/env perl
#
# Confirm that user wants to wipe everything on the same hard drive
# as the partition the user selects.

use warnings;
use strict;

use feature 'say';

sub display_partitions {
    # Read the partition information from a file, and display all the partitions
    # that share a major number with the provided name of the partition.

    # If no partition is provided, display all partitions.

    my ($partition_name, $partition_file) = @_;
    $partition_file //= "./partitions";

    # this would probably be a good place to put some code
}

sub format_drive_for_partition {
    # Let's pretend that this actually formats the drive...
    my ($partition_name) = @_;

    say "Formatting the drive with \"$partition_name\" and its friends...";
}

display_partitions();

print "which partition would you like to format? (e.g. sda1) ";
my $partition_name = <STDIN>;
chomp $partition_name;

display_partitions($partition_name);
print "are you sure? [y/N] ";
my $confirm = <STDIN>;
chomp $confirm;

if ($confirm eq 'y') {
    say "your funeral...";
    format_drive_for_partition($partition_name);
} else {
    say "nice save..."
}
