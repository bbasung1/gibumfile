import os
import hashlib
import numpy
test = os.listdir("./")
k = []
for a in test:
    if(os.path.isdir(a)):
        test.remove(a)
        continue
    f = open(a, "rb")
    data = f.read()
    k.append(hashlib.md5(data).hexdigest())
print(test)
print(k)
for b in k:
    alpha = numpy.array(k)
    print(numpy.where(alpha == b))
