import os;
os.system("g++ data.cpp -o data -O2")
for i in range(110, 111):
    os.system("data.exe > data%d.in" % i)
    os.system("std.exe < data%d.in > data%d.ans" % (i, i))