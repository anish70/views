class OhaiFiltered(object):

    def __init__(self, app, global_conf, local_conf):
        self.app = app
        self.global_conf = global_conf
        self.local_conf = local_conf

    def __call__(self, env, start_response):
        if env['REQUEST_METHOD'] == 'OHAI':
            ohai = 'Hello, world!\n'
            headers = [('Content-Length', str(len(ohai)))]
            start_response('200 OK', headers)
            return [ohai]
        return self.app(env, start_response)


def filter_factory(global_conf, **local_conf):
    def app_filter(app):
        return OhaiFiltered(app, global_conf, local_conf)
    return app_filter
