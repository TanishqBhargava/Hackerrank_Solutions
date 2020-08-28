package main
import "bufio"
import "fmt"
import "os"

func morgan(s1, s2 string) string {
    output := make([]byte, 0, len(s1)+len(s2))
    for i, j := 0, 0; i < len(s1) || j < len(s2); {
        if i == len(s1) {
            output = append(output, s2[j:]...)
            break
        } else if j == len(s2) {
            output = append(output, s1[i:]...)
            break
        } else if s1[i] < s2[j] {
            output = append(output, s1[i])
            i++
        } else if s1[i] > s2[j] {
            output = append(output, s2[j])
            j++
        } else if s1[i+1:]+"[" <= s2[j+1:]+"[" {
            for c := s1[i]; i < len(s1) && s1[i] == c; i++ {
                output = append(output, c)
            }
        } else if s1[i+1:]+"[" > s2[j+1:]+"[" {
            for c := s2[j]; j < len(s2) && s2[j] == c; j++ {
                output = append(output, c)
            }
        }
    }
    return string(output)
}

func main() {
        in := bufio.NewReader(os.Stdin)
        N, s1, s2 := 0, "", ""
        fmt.Fscan(in, &N)
        for i := 0; i < N; i++ {
                fmt.Fscan(in, &s1, &s2)
                fmt.Println(morgan(s1, s2))
        }
}
