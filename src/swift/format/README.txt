Summary: Given a bunch of partition data and the name of a device, return
the other devices that share a "major device number".

Details:
Swift eats whole entire raw disks, by the dozens, for breakfast.
Our customers like their tiny little disks carved up until teeny tiny little
bits of blocks that each have their own unique purpose and the special
individualism of a snowflake.

Until we get ahold of them - then we eat the whole thing.

But as soon you delete *one* customer's mp3 collection, you have
to add a bunch of confirmation prompts and spoil the party for EVERYONE.

Now every time we see a drive with "partitions" on it where there should be a
bunch of unused blocks ready for us to devour, we have to stop and ask the
customer the name the partition they want to feed to Swift, and then make sure
they *really* understand all of the *other* partitions that are on the same
disk.

We can pull the interesting information out of /proc/partitions on a Linux
system - since you may not be using a Linux system, an example is provided
as the data file called "partitions".

Write a method to parse this file and identify partitions that share a "major
device number" and are therefore on the same physical drive.
