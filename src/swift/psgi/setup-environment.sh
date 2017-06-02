#!/bin/sh
#
# Set up the environment to be able to run the PSGI process with our
# little application in it.
#
# You should only need to run this once.

PERL="/usr/local/Cellar/perl/5.20.1/bin/perl"
LOCALENV="interview-psgi"

set -e

eval $($PERL "-Mlocal::lib=$LOCALENV")

$PERL -MCPAN -e "install CGI"
$PERL -MCPAN -e "install HTTP::Server::Simple::PSGI"
$PERL -MCPAN -e "install Moose"
