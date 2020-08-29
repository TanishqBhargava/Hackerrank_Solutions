from collections import defaultdict

def infdict():
    return defaultdict(infdict)

def build_trie(node, ch):
    child_node = node[ch]
    assert None not in child_node  # no existing words are prefixes of this word
    return child_node

n = int(raw_input())
trie = infdict()
try:
    for _ in range(n):
        s = raw_input()
        end_node = reduce(build_trie, s, trie)
        assert not end_node  # not a prefix of an existing word
        end_node[None]  # None = end-of-word sentinel
    print "GOOD SET"
except AssertionError:
    print "BAD SET"
    print s
