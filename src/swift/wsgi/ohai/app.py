import time

def main(env, start_response):
    resp_headers = [('X-Timestamp', time.time())]
    if 'HTTP_X_ENVIRON_DEBUG' in env:
        start_response('200 OK', resp_headers)
        def body():
            yield 'The WSGI environment:\n'
            for k, v in env.items():
                yield '%30s: %s\n' % (k, v)
        return body()
    start_response('401 Unauthorized', resp_headers)
    return ['None for you!\n']


def app_factory(global_conf, **local_conf):
    return main
