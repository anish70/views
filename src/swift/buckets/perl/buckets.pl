use strict;
use warnings;
use Data::Dumper qw(Dumper);

package NumericalSum;

sub build {
    return bless { 'op', $_[1] }, $_[0];   
}

sub process {
    my $self = shift;
    my $fn = shift;
    my @array;
    my @newarray = (0) x 11;

    open my $fh, "<", $fn or die "Could not open $fn: $!";
    for my $l (<$fh>) {
        $l =~ s/\s+$//;
        push @array, $l;
    }

    for (my $n=0; $n<10; $n++) { 
        my @temp;
        for (my $i=0; $i<scalar(@array); $i++) { 
            if ($array[$i] < 100) {
                my $dest = ((split(//, "$array[$i]"))[-1])+0;
                if ($dest == $n) {
                    push @temp, $array[$i];
                }
            }
        }
        $newarray[$n] = $self->{'op'}(\@temp);
    }

    my @temp;
    for (my $i=0; $i<scalar(@array); $i++) { 
        if ($array[$i] >= 100) {
            push @temp, $array[$i];
        }
    }
    $newarray[10] = $self->{'op'}(\@temp);
    return \@newarray;
}

my $sum = sub { 
    my $a = shift;
    my $s = 0;
    for (my $i=0; $i<scalar(@$a); $i++) { 
        $s+=${$a}[$i];
    }
    return $s;
};

if ( $0 eq __FILE__ ) {
    $ARGV[0] or die "Supply data file on command line!";
    my $out = NumericalSum->build($sum)->process($ARGV[0]);
    print "[" . join(', ', @$out) . "]\n"
}
