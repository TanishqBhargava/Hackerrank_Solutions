#!/bin/ruby

require 'json'
require 'stringio'

# Complete the lonelyinteger function below.
def lonelyinteger(a)
a.reduce(&:^)

end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

a = gets.rstrip.split(' ').map(&:to_i)

result = lonelyinteger a

fptr.write result
fptr.write "\n"
fptr.close()
