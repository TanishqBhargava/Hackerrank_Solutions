package main

import "fmt"

// takes input from stdio
func input() []int {
    a := []int{}
    for i:=0; i<26; i++ {
        var elem int
        if _, err := fmt.Scan(&elem); err != nil {
            panic(err)
        }
        a = append(a, elem)
    }
    return a
}

// builds lexicographically smallest string from given frequencies
func lexMin(a []int) []byte {
    s := []byte{}
    for i:=0; i<len(a); i++ {
        for j:=0; j<a[i]; j++ {
            s = append(s, 'a'+byte(i))
        }
        a[i] = 0
    }
    return s
}

// finds index of minimum frequency
func findMinFreq(a []int) int {
    min := 1000001
    midx := -1
    
    for i:=0; i<len(a); i++ {
        if a[i] > 0 {
            if a[i] < min {
                min = a[i]
                midx = i
            }
        }
    }
    
    return midx
}

// finds index of
//  1) "left": the first character index before min-freq character
//  2) "right": the first character index before min-freq character
func findFirstLeftRight(a []int, midx int) (int, int) {
    left := -1
    right := -1
    
    for i:=0; i<len(a); i++ {
        if a[i] > 0 {
            if left < 0 && i < midx{
                left = i
            } else if right < 0 && i > midx {
                right = i
            }
        }
    }
    
    return left, right
}

// takes and returns a character from frequency data
func take(a []int, idx int) byte {
    a[idx] -= 1 // decrement the frequency
    return 'a' + byte(idx)
}

func main() {    
    a := input()
    output := []byte{}

    // decides the first character: minimum frequency
    minfreq := findMinFreq(a)
    if minfreq < 0 {
        panic("empty") // this cannot happen b/c constraint
    }
    output = append(output, take(a, minfreq))

    // finds the first first character index of
    // before (left) and after (right) the min-freq character
    left, right := findFirstLeftRight(a, minfreq)

    // use the rest as-is if:
    if a[minfreq] < 2 || // 1) freq. of first character was 1,
        left >= 0 ||     // 2) first character was earliest character(s),
        (left < 0 && right < 0) { // 3) or, first character was only character
        output = append(output, lexMin(a)...)
    } else { // otherwise...
        // mix (interleave) min-freq characters with the "right" character
        cnt := a[minfreq]
        for i:=0; i<cnt; i++ {
            output = append(output, take(a, minfreq))
            output = append(output, take(a, right))
        }
        // append the rest
        output = append(output, lexMin(a)...)
    }

    // output
    fmt.Println(string(output))
}
