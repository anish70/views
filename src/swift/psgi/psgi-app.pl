#!/usr/bin/env perl
#
# See https://github.com/plack/psgi-specs/blob/master/PSGI.pod for
# details on the PSGI specification.

use strict;
use warnings;


# This is a very simple PSGI application
package Spinach::App;
use Moose;

use overload '&{}' => sub { my $self = shift;
                            return sub { $self->handle_request(@_) } };
no Moose;

sub handle_request {
    my ($self, $env) = @_;

    if ($env->{"REQUEST_METHOD"} eq "FISH") {
        return [200,
                ['Content-Type', 'text/goldfish'],
                ["here fishy fishy fishy\n"]];
    }
    else {
        my $body = "PSGI environment has: \n";
        while (my ($key, $value) = each %$env) {
            $value //= "<undef>";
            $body .= "\t $key = $value\n";
        }
        return [200, [], [$body]];
    }
}

# This is a very simple PSGI middleware
package Spinach::Middleware;
use Moose;

has 'app' => (is => 'ro');

use overload '&{}' => sub { my $self = shift;
                            return sub { $self->handle_request(@_) } };

sub handle_request {
    my ($self, $env) = @_;

    my $response = $self->app->($env);
    return $response;
}


package Spinach::Server;
use base qw(HTTP::Server::Simple::PSGI);

# This exists mainly so we can lose the HTTP verb filtering that's
# imposed on us by default. It's normally good, but not here.

sub valid_http_method {
    my ($self, $method) = @_;
    return 1;
}


package main;

my $app = Spinach::Middleware->new({app => Spinach::App->new});
my $server = Spinach::Server->new(5678);
$server->host("localhost");
$server->app($app);
$server->run;
