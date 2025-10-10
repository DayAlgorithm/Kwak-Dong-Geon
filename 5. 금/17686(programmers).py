def solution(files) :
    ans = []

    for file in files :
        head, number, tail = '', '', ''

        flag = False
        for i in range(len(file)):
            if file[i].isdigit():
                number += file[i]
                flag = True
            elif not flag:
                head += file[i]
            else:
                tail = file[i:]
                break

        ans.append((head, number, tail))

    ans.sort(key = lambda x: (x[0].lower(), int(x[1])))
    ans = [''.join(value) for value in ans]
    return ans