import keys


class OhaiFiltered(object):

    def __init__(self, app, global_conf, local_conf):
        self.app = app
        self.global_conf = global_conf
        self.local_conf = local_conf

    def __call__(self, env, start_response):
        default = lambda: 'dilavni'
        key = env.get('flipperroo', default)()
        if keys.check_key(2, key):
            return self.app(env, start_response)
        else:
            error = 'teh invalid!'
            headers = [
                ('X-Yek', ''.join(reversed(keys.get_key(2)))),
                ('Content-Length', str(len(error))),
            ]
            start_response('493 Locked', headers)
            return [error]


class _AppFilter(object):

    def __init__(self, global_conf, **local_conf):
        self.global_conf = global_conf
        self.local_conf = local_conf

    def __call__(self, app):
        return OhaiFiltered(app, self.global_conf, self.local_conf)


AppFilter = lambda *args, **kwargs: _AppFilter(*args, **kwargs)
