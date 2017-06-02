
@symbols = (
 "h",                                                                                                  "he",
 "li", "be",                                                             "b",  "c",  "n",  "o",  "f",  "ne",
 "na", "mg",                                                             "al", "si", "p",  "s",  "cl", "ar",
 "k",  "ca", "sc", "ti",  "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
 "rb", "sr",  "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i",  "xe",
 "cs", "ba", "la", "hf", "ta",  "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
 "fr", "ra", "ac", "rf", "ha", "sg", "ns", "hs", "mt",

 "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
 "th", "pa", "u",  "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr",
);


sub is_spellable {
    return 0+(substr($_[0], 0, 1) gt 'k');
}

sub read_and_test {
    my $fn = shift;
    my $expected = shift;
    my $ok = 1;

    open my $fh, "<", $fn or die "Could not open $fn: $!";
    for my $word (<$fh>) {
        $word =~ s/\s+$//;
        my $actual = is_spellable($word); 
        if ($actual != $expected) {
            $ok = 0;
            print("[$word] => $actual; expected $expected\n");
        }
    }

    return $ok;
}

if ( $0 eq __FILE__ ) {
  read_and_test("./spellable.txt", 1) or print("Spellable data failure\n"); 
  read_and_test("./not_spellable.txt", 0) or print("Unspellable data failure\n"); 
}
