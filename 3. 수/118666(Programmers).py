def solution(survey, choices):
    ans = ''
    n = len(survey)
    point = {'R':0, 'T':0, 'C':0, 'F':0, 'J':0, 'M':0, 'A':0, 'N':0}
    
    for i in range(n):
        first, second = survey[i][0], survey[i][1]
        if choices[i] <= 3:
            point[first] += 4 - choices[i]
        elif choices[i] > 4:
            point[second] += choices[i] - 4
    
    if point['R'] >= point['T']:
        ans += 'R'
    else:
        ans += 'T'
    
    
    if point['C'] >= point['F']:
        ans += 'C'
    else:
        ans += 'F'
        
    
    if point['J'] >= point['M']:
        ans += 'J'
    else:
        ans += 'M'
        
    
    if point['A'] >= point['N']:
        ans += 'A'
    else:
        ans += 'N'
        
    return ans