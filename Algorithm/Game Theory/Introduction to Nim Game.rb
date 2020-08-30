#!/bin/ruby

require 'json'
require 'stringio'

# Complete the nimGame function below.
def nimGame(pile)

    nim_sum = 0;
    for i in 0..pile.size - 1
        nim_sum = nim_sum ^ pile[i];
    end
    if nim_sum == 0
        "Second"
    else
        "First"
    end

end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

g = gets.to_i

g.times do |g_itr|
    n = gets.to_i

    pile = gets.rstrip.split(' ').map(&:to_i)

    result = nimGame pile

    fptr.write result
    fptr.write "\n"
end
fptr.close()
