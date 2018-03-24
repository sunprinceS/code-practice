#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
s = input()
ret=""
i = 0
bomb = False;

while(i<n):
    if s[i] not in 'aeiouy':
        bomb = False
        ret += s[i]
    elif not bomb:
        bomb = True
        ret+= s[i]
    i+=1
print(ret)
