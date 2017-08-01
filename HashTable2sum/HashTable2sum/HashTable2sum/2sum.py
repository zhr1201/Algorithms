# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 11:35:22 2017

@author: Administrator
"""

lb = -10000
rb = 10000

f = open('2sum.txt', 'r')
lines = f.readlines()
f.close()
lines = [int(line) for line in lines]

hash = {}
for line in lines:
    hash[line] = 1

total = rb - lb
itotal = 1.0 / float(total)

result = {}
for summa in range(lb, rb + 1):
    temp_dict = hash.copy()
    for line in hash:
        if (line in temp_dict) and (summa - line in temp_dict):
            if summa != line * 2:
                result[summa] = 1
                del temp_dict[line]
                del temp_dict[summa - line]
    print str((summa - lb) * 100 * itotal) +\
        "% (" + str(len(result)) + " results)"

print "Finally:"
print len(result)
