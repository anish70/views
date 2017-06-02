
def r(m):
    return m.__class__.objects.get(id=m.id)

def s(states):
    preds = [Q(p) for p in states]
    return J.objects.filter(reduce(operator.or_, preds))

# This could have a clearer motivation. 
def m(O):
    return O.objects.filter(created__lt=F('updated'))

@register.filter(name='t')
@stringfilter
def t(value, arg):
    try:
        length = int(arg)
    except ValueError: 
        return value 
    if len(value) > length:
        return value[:length-3] + '...'
    return value
truncatechars.is_safe = True

class I(object):
    def process_request(self, request):
        if request.user.is_superuser and "__i" in request.GET:
            request.session['i_id'] = int(request.GET["__i"])
        elif "__noti" in request.GET:
            del request.session['i_id']
        if request.user.is_superuser and 'i_id' in request.session:
            request.user = User.objects.get(id=request.session['i_id'])
