def multiset(str):
    if not str: return False
    return [str[i-1:i+1].upper() for i in range(1, len(str)) if str[i-1].isalpha() and str[i].isalpha()]

def solution(str1, str2):
    a = multiset(str1)
    b = multiset(str2)

    intersection = set(a) & set(b)
    union = set(a) | set(b)

    if not union: return 65536

    inter_val = union_val = 0
    for alpha in intersection:
        inter_val += min(a.count(alpha), b.count(alpha))
    for alpha in union:
        union_val += max(a.count(alpha), b.count(alpha))

    return int(inter_val/union_val * 65536)