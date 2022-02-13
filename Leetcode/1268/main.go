//https://leetcode.com/problems/search-suggestions-system/
func suggestedProducts(products []string, searchWord string) [][]string {
    // 단어 길이
    leng := len(searchWord)
    result := make([][]string, leng)
    // for문에서 갱신되는 단어
    // m mo mou mous mouse
    var last string

    sort.Strings(products)

    for i, c := range searchWord{
        // last ++ 문자
        last += fmt.Sprintf("%c", c)

        temp := make([]string, 0)

        // products 들 순회
        for _, p := range products{
            // 추가할 문자
            var s string
            pleng := len(p)
            lastleng := len(last)

            // pleng 보다 아직 찾는 단어 가 더 길다면
            if lastleng >= pleng{
                //현재 상품 문자열
                s = p[0:pleng]
            }else{
                s = p[0:lastleng]
            }

            // 비교
            if last == s && len(temp) < 3{
                temp = append(temp, p)
            }
        }
        result[i] = temp
    }

    return result
}
