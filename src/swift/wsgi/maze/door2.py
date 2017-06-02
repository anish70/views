import keys


def ex2(env, start_response):
    headers = []
    if env.get('HTTP_X_WHIZ', '').lower() == 'baz':
        body = keys.get_key(1) + '\n'
    else:
        body = 'Joel says Hi!'
    if not keys.check_key(1, env.get('HTTP_X_FUZZ')):
        headers.append(('Content-Length', str(len(body))))
        start_response('492 Locked', headers)
        return [body]
    return ex2.app(env, start_response)


def app_filter(app):
    ex2.app = app
    return ex2


def filter_factory(global_conf, **local_conf):
    return app_filter
