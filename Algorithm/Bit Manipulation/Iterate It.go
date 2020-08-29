package main
import ("bufio"; "fmt"; "io"; "os")
import "sort"

const MAX = 5e4

type Set struct {
    index []int
    list []int
}

func NewSet() Set {
    return Set{ make([]int, MAX + 1), make([]int, 0, MAX) }
}

func (s *Set) contains(n int) bool {
    i := s.index[n]
    return i < len(s.list) && s.list[i] == n
}

func (s *Set) insert(n int) {
    if !s.contains(n) {
        i := len(s.list)
        s.list = append(s.list, n)
        s.index[n] = i
    }
}

func (s *Set) clear() {
    s.list = s.list[:0]
}

func (s *Set) Len() int {
    return len(s.list)
}

func (s *Set) Less(i, j int) bool {
    return s.list[i] < s.list[j]
}

func (s *Set) Swap(i, j int) {
    s.list[i], s.list[j] = s.list[j], s.list[i]
    s.index[s.list[i]] = i
    s.index[s.list[j]] = j
}

func findDiffs(A Set) Set {
    B := NewSet()
    if len(A.list) < 500 {
        for i, a := range A.list {
            for _, b := range A.list[:i] {
                Assert(b < a)
                B.insert(a - b)
            }
        }
    } else {
        maxd := A.list[len(A.list)-1] - A.list[0]
        for i := 1; i <= maxd; i++ {
            u := 0
            v := sort.SearchInts(A.list, A.list[0] + i)
            for v < len(A.list) {
                d := A.list[v] - A.list[u]
                if d < i {
                    v++
                } else if d > i {
                    u++
                } else {
                    B.insert(i)
                    break
                }
            }
        }
    }
    return B
}

func main() {
    N := ScanInt(1, 1e5)
    A := NewSet()
    NewLine()
    for n := 0; n < N; n++ {
        A.insert(ScanInt(1, 5e4))
    }
    rep := 0
    for len(A.list) > 0 {
        sort.Sort(&A)
        small := A.list[0]
        done := true
        for n := 1; n < len(A.list); n++ {
            if A.list[n] != (n + 1) * small {
                done = false
                break
            }
        }
        if done {
            fmt.Println(rep + len(A.list))
            return
        }
        A = findDiffs(A)
        rep++
    }
    fmt.Println(rep)
}

// Boilerplate

func Assert(condition bool, items... interface{}) {
    if !condition {
        panic("assertion failed: " + fmt.Sprint(items...))
    }
}

func Log(items... interface{}) {
    fmt.Println(items...)
}

var Input = bufio.NewReader(os.Stdin)

func ReadByte() byte {
    b, e := Input.ReadByte()
    if e != nil {
        panic(e)
    }
    return b
}

func MaybeReadByte() (byte, bool) {
    b, e := Input.ReadByte()
    if e != nil {
        if e == io.EOF {
            return 0, false
        }
        panic(e)
    }
    return b, true
}

func UnreadByte() {
    e := Input.UnreadByte()
    if e != nil {
        panic(e)
    }
}

func NewLine() {
    for {
        b := ReadByte()
        switch b {
        case ' ', '\t', '\r':
            // keep looking
        case '\n':
            return
        default:
            panic(fmt.Sprintf("expecting newline, but found character <%c>", b))
        }
    }
}

func ScanInt(low, high int) int {
    return int(ScanInt64(int64(low), int64(high)))
}

func ScanUint(low, high uint) uint {
    return uint(ScanUint64(uint64(low), uint64(high)))
}

func ScanInt64(low, high int64) int64 {
    Assert(low <= high)
    for {
        b := ReadByte()
        switch b {
        case ' ', '\t', '\r':
            // keep looking
        case '\n':
            panic(fmt.Sprintf(
                "unexpected newline; expecting range %d..%d", low, high))
        case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
            if high < 0 {
                panic(fmt.Sprintf(
                    "found <%c> but expecting range %d..%d", b, low, high))
            }
            lw := low
            if lw < 0 {
                lw = 0
            }
            UnreadByte()
            x, e := _scanu64(uint64(lw), uint64(high))
            if e != "" {
                panic(fmt.Sprintf("%s %d..%d", e, low, high))
            }
            return int64(x)
        case '-':
            if low > 0 {
                panic(fmt.Sprintf(
                    "found minus sign but expecting range %d..%d", low, high))
            }
            h := high
            if h > 0 {
                h = 0
            }
            x, e := _scanu64(uint64(-h), uint64(-low))
            if e != "" {
                panic(fmt.Sprintf( "-%s %d..%d", e, low, high))
            }
            return -int64(x)
        default:
            panic(fmt.Sprintf(
                "unexpected character <%c>; expecting range %d..%d", b, low, high))
        }
    }
}

func ScanUint64(low, high uint64) uint64 {
    Assert(low <= high)
    for {
        b := ReadByte()
        switch b {
        case ' ', '\t', '\r':
            // keep looking
        case '\n':
            panic(fmt.Sprintf(
                "unexpected newline; expecting range %d..%d", low, high))
        case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
            UnreadByte()
            x, e := _scanu64(low, high)
            if e != "" {
                panic(fmt.Sprintf("%s %d..%d", e, low, high))
            }
            return x
        default:
            panic(fmt.Sprintf(
                "unexpected character <%c>; expecting range %d..%d", b, low, high))
        }
    }
}

func _scanu64(low, high uint64) (result uint64, err string) {
    x := uint64(0)
    buildnumber: for {
        b, ok := MaybeReadByte()
        if !ok {
            break buildnumber
        }
        switch b {
        case ' ', '\t', '\r':
            break buildnumber
        case '\n':
            UnreadByte()
            break buildnumber
        case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
            d := uint64(b - '0')
            if (high - d) / 10 < x {
                return x, fmt.Sprintf("%d%c... not in range", x, b)
            }
            x = x * 10 + d
        default:
            return x, fmt.Sprintf("%d%c found; expecting range", x, b)
        }
    }
    if x < low || x > high {
        return x, fmt.Sprintf("%d not in range", x)
    }
    return x, ""
}

func ScanBytes(short, long int) []byte {
    Assert(1 <= short && short <= long)
    var b byte
    buf := make([]byte, long)
    skipws: for {
        b = ReadByte()
        switch b {
        case ' ', '\t', '\r':
            // keep looking
        case '\n':
            panic(fmt.Sprintf("unexpected newline; expecting string"))
        default:
            break skipws
        }
    }
    buf[0] = b
    length := 1
    buildstring: for {
        var ok bool
        b, ok = MaybeReadByte()
        if !ok {
            break buildstring
        }
        switch b {
        case ' ', '\t', '\r':
            break buildstring
        case '\n':
            UnreadByte()
            break buildstring
        default:
            if length >= long {
                panic(fmt.Sprintf("string length not in range %d..%d", short, long))
            }
            buf[length] = b
            length++
        }
    }
    if length < short {
        panic(fmt.Sprintf("string length not in range %d..%d", short, long))
    }
    return buf[:length]
}

func ScanString(short, long int) string {
    return string(ScanBytes(short, long))
}
