def beautifulBinaryString(a):
    return a.replace("010","011").count("1")-a.count("1")
input()
print(beautifulBinaryString(input()))
