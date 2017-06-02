import keys


def ex1_factory(global_conf, **local_conf):
    def filter(app):
        def ohai(env, start_response):
            if keys.check_key(0, env.get('bananaphone', '')):
                return app(env, start_response)
            elif env['REQUEST_METHOD'] == 'YOLO':
                env['bananaphone'] = keys.get_key(0)
            start_response('491 LOCKED', [])
            return []
        return ohai
    return filter
