//https://leetcode.com/problems/course-schedule-ii/


func findOrder(numCourses int, prerequisites [][]int) []int {

    var result = make([]int, 0, numCourses)

    if numCourses == 1{
        return append(result, 0)
    }

    // 해당 과목 들으면 들을 수 있는 과목들 저장
    var first = make([][]int, numCourses)
    // 수강할 수 있는 과목 // 길이 0, max 용량 numCourses
    var sugang = make([]int , 0 ,numCourses)
    // 해당 과목 수강에 필요한 강의 개수
    var condition = make([]int, numCourses)

    for _, i := range prerequisites{
        // 해당 과목 들으면 들을 수있는 과목들 추가
        first[i[1]] = append(first[i[1]], i[0])
        // 해당 과목 들으려면 필요한 과목개수 추가
        condition[i[0]]++
    }


    for i := 0; i < numCourses; i++{
        // 수강할 필요가 없으면 현재 들을 수 있는 과목에 추가해준다.
        if condition[i] == 0{
            sugang = append(sugang, i)
            result = append(result, i)
        }
    }

    for i := 0; i != len(sugang); i++{
        // 현재 수강하는 과목
        now := sugang[i]
        // 이 과목을 선수하면 들을 수 있는 과목들 조건 개수를 줄여준다.
        k := first[now]
        for _, v := range k{
            condition[v] --
            if condition[v] == 0{
                sugang = append(sugang, v)
                result = append(result, v)
            }
        }
    }

    if len(sugang) != numCourses{
        return make([]int, 0)
    }

    return result
}
