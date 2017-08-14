import numpy as np


f = open('data.txt', 'r')
lines = f.readlines()
f.close()
N = int(lines[0].replace('/n', ''))

loc = []
dict={}
for i in range(N):
    dict[i] = 1

for i in range(1, N + 1):
    cord = lines[i].replace('\n', '').split(' ')
    tmp = [float(cord[1]), float(cord[2])]
    loc.append(tmp)

del dict[0]
current_pos = 0
tot_dist = 0
count = 0
while(dict):
    count += 1
    if(count % 100 == 0):
        print float(count)  / N
    min_dist = 1e20
    min_ind = 0
    for x in dict:
        current_dist = np.sqrt(
            (loc[current_pos][0] - loc[x][0]) ** 2 +
            (loc[current_pos][1] - loc[x][1]) ** 2)
        if(current_dist < min_dist):
            min_id = x
            min_dist = current_dist
        
    del dict[min_id]
    tot_dist += min_dist
    current_pos = min_id

tot_dist += np.sqrt(
            (loc[current_pos][0] - loc[0][0]) ** 2 +
            (loc[current_pos][1] - loc[0][1]) ** 2)
print tot_dist