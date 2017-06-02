
#include <err.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSED_MESSAGE  "Test file '%s' passed.\n"
#define FAILED_MESSAGE  "TEST FILE '%s' FAILED.\n"

#define NUM_SYMBOLS  109 

const char * const symbols[] = {
 "h",                                                                                                  "he",
 "li", "be",                                                             "b",  "c",  "n",  "o",  "f",  "ne",
 "na", "mg",                                                             "al", "si", "p",  "s",  "cl", "ar",
 "k",  "ca", "sc", "ti",  "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
 "rb", "sr",  "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i",  "xe",
 "cs", "ba", "la", "hf", "ta",  "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
 "fr", "ra", "ac", "rf", "ha", "sg", "ns", "hs", "mt",

 "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
 "th", "pa", "u",  "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr",
};


bool is_spellable(const char *word) {
    return *word > 'k';
}

int _read_and_test(const char *fn, FILE *fp, bool expected_result) {
  bool passed = true;
  char buf[512];

  while (fgets (buf, sizeof(buf), fp)) {
    buf[strcspn(buf, "\n")] = 0;
    bool result = is_spellable(buf);
    if (result != expected_result) {
        fprintf(stderr, "unexpected %s: %s\n", expected_result ? "pass" : "fail", buf);
        passed = false;
    }
  }

  char * message = passed ? PASSED_MESSAGE : FAILED_MESSAGE;
  fprintf(stderr, message, fn);
  
  return passed ? 0 : -1;
}

int read_and_test(const char *fn, bool expected_result) {
  int result;

  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    err(1, fn);
  }

  result = _read_and_test(fn, fp, expected_result);
  fclose(fp);
  return result;
}

int main(void) {
  int result = 0;
  
  result += read_and_test("./spellable.txt", true); 
  result += read_and_test("./not_spellable.txt", false); 

  return result;
}
