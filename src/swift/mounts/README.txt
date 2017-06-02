Summary: Given some mount points and their capacities, and some directory
paths and the space they'll consume, return information about how much
remaining space there will be underneath each mount point.

Details:
Your input data will look like this:

requirements:
500M /var/lib/data
300M /srv/www
1000M /var/log/http
100M /var/log/auth
30M /etc/http
30M /etceta/http

available:
600M /
500M /var/log
500M /srv

We've already written code to parse this input.  You need to write a function
(which we've stubbed out and called "solve") which will take input such as
a parsed version of what you see above, and return something like this:

{
  '/': [['/etc/http', '/etceta/http', '/var/lib/data'], 40],
  '/var/log': [['/var/log/http', '/var/log/auth'], -600],
  '/srv': [['/srv/www'], 200]
}
