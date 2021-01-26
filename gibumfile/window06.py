import os
test = os.listdir("./")
f=open("test.txt","w")
f.write(" ".join(test))
f.close()