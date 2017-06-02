#!/bin/sh

PERL="/usr/local/Cellar/perl/5.20.1/bin/perl"
LOCALENV="interview-psgi"

set -e

eval $($PERL "-Mlocal::lib=$LOCALENV")

$PERL psgi-app.pl
