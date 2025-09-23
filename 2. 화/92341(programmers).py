import math
from collections import defaultdict

def to_min(time):
    hour, minutes = map(int,time.split(":"))
    return hour * 60 + minutes

def solution(fees, records):
    ans = []

    dict = {}
    rec = defaultdict(int)
    
    for record in records :
        time, number, state = record.split()
        time = to_min(time)
        if number in dict :
            rec[number] += time - dict[number]
            del dict[number]
        else :
            dict[number] = time

    max_time = (23 * 60) + 59
    for num, t in dict.items():
        rec[num] += max_time - t

    for num, t in rec.items() :
        cost = fees[1]
        if t > fees[0] :
            cost += math.ceil((t - fees[0]) / fees[2]) * fees[3]
        ans.append((num, cost))

    ans.sort()
    return [value[1] for value in ans]