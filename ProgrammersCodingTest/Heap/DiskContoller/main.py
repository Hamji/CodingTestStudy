import heapq
def solution(jobs):
    count = 0
    last = -1
    answer = 0
    disk = []
    jobs.sort(key=lambda x:x[0])    
    time = jobs[0][0]
    
    while count < len(jobs):
        for i in jobs:
            if last < i[0] <= time:
                heapq.heappush(disk, (i[1], i[0]))
        if disk:
            count += 1
            last = time
            term, start = heapq.heappop(disk)
            time += term
            answer += time - start
        else:
            time += 1
    
    return answer//len(jobs)
