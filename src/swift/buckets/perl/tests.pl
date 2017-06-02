use strict;

use Test::More tests => 3;
use Data::Dumper qw(Dumper);

sub invoke {
    my $fn = shift @_;
    my $s = `perl buckets.pl $fn`; 
    $s =~ s/\s+$//;
    return $s
}

my $output = invoke('input1.dat');
my $expected = "[450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 6225]";
ok($output eq $expected);

$output = invoke('input2.dat');
$expected = "[910, 839, 1120, 1014, 1126, 900, 974, 866, 1698, 1384, 10944]";
ok($output eq $expected);

$output = invoke('input3.dat');
$expected = "[0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0]";
ok($output eq $expected);
